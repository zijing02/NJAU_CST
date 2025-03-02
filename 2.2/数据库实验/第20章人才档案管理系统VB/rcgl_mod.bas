Attribute VB_Name = "function_module"
Public strCnn As String  '数据库连接串
Public conODBC As Connection
Public Old_Row As Integer       '浏览信息表表格前一次行数
Public String_Area As String    '地区编号
Public Name_Area As String      '地区名称
Public Num_Archive As Integer   '成果个数
Public Sum_People_Area          '某地区人数
Public ID_Person As String
Public ByName As String


'数据库连接对象

'-----连接数据库服务器
Public Sub Sub_ConnectServer()
   '-----------------’SQL Server 2000连接串
   'strCnn = "Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;PWD=sa;Initial Catalog=rc_base;Data Source=mxm"
   '-----------------’SQL Server 2005连接串
   strCnn = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=rc_base;Data Source=MXM\SQLEXPRESS"
   Set conODBC = New ADODB.Connection
   conODBC.Open strCnn
End Sub

'=========将地区名转换成地区编号：将地区名转换成它的地区编号形式
Public Sub no_area()
   
   Sub_ConnectServer
   Set rs = New ADODB.Recordset
   rs.CursorType = adOpenStatic
   rs.LockType = adLockOptimistic '
   '-----------读地区编号表
   rs.Open "Select * From AreaTab where Name_area='" + Name_Area + "'", conODBC
   num_records = rs.RecordCount
   If num_records = 0 Then
      MsgBox ("没有此地区编号！")
      Exit Sub
   End If
   String_Area = rs!no_area
   rs.Close
   conODBC.Close
End Sub

'========人才编号长度计算: value_num:编号数值；　　string_num：编号字符串形式
Public Sub person_ID_tran(value_num, string_num)
    Dim string_max As String

    string_max = "00000"
    len_num = Len(Trim(Str(value_num)))
    string_max = Left(string_max, Len(string_max) - len_num)
    string_num = string_max + Trim(Str(value_num))
End Sub

'=========查询某地区人数
Public Sub Sum_People()


    '======查询地区编号
    no_area
    '=====求出此人编号
    Sub_ConnectServer
    Set rs = New ADODB.Recordset
    rs.CursorType = adOpenStatic
    rs.LockType = adLockOptimistic '
    '-----------打开人才基本信息表
    rs.Open "Select * From BTab where person_ID like '" + String_Area + "%" + "'", conODBC
    num_records = rs.RecordCount
    rs.Close
    Sum_People_Area = num_records + 1
End Sub
