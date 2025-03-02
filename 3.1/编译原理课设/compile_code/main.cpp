#include"SyntaxAnalyzer.h"
#include"LexicalAnalyzer.h"
#include"SemanticAnalyzer.h"
int main()
{
	string b[] = { "if","id","then","id",":=","id","#" };
	cout << "LexicalAnalyzer analyse：" << endl;
	//词法
	CreateToken cre;
	//读入token表并形成map
	map<string, int> myMap = cre.getToken();
	LexicalAnalyzer les(myMap);
	//if id then id := id #

	//语义
	vector<string> temp = les.get_symbol_table();
	Semantic_Analyzer sem(temp);

	//语法
	SyntaxAnalyzer sa(les, sem);
	//sa.print_slr();
	sa.work();

	return 0;
}


