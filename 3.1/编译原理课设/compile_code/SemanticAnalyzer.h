#pragma once
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include"SyntaxAnalyzer.h"
#include"LexicalAnalyzer.h"
#include"SemanticAnalyzer.h"
using namespace std;
typedef struct Node
{
    int type;                                  // M,S,E,id
    string name;                               // 名字
    int place, code;                           // 符号表存储位置，TAC语句序列
    vector<int> truelist, falselist, nextlist; // 真链、假链、下一跳
} Node;
typedef struct Three_Address_Code
{
    string j;
    string a, b, code;
} Three_Address_Code;
class Semantic_Analyzer // 需要使用符号表以及符号栈
{
    vector<Three_Address_Code> TAC;
    int nextstm;
    vector<Node> symbol;          // 符号栈
    int top;                        // 符号栈栈顶指针
    vector<string> symbol_table; // 符号表
    int newtemp;                    // 符号表新地址，指向当前最后一个已填充的符号表
public:
    Semantic_Analyzer();
    Semantic_Analyzer(vector<string>& symbol_table);
    int lookup(Node name);                                           // 变量是否被声明过*,找不到返回0报错
    void makelist(vector<int>& list, int code);                      // 生成一条只包含code的链
    void merge(vector<int>& list, vector<int>& p1, vector<int>& p2); // 连接两个链表 p1 和 p2 ，返回结果链表
    void backpatch(vector<int>& list, int code);                     // 将链表 p 中每个元素所指向的跳转语句的标号置为 aim
    void emit(string j, string a, string b, string code);        // 生成四元式
    void reduction(int type, Node& P);                               // 哪个语句的归约操作
    void print();                                                    // 输出四元式
    void set_symbol(vector<Node>& s, int t);
    ~Semantic_Analyzer();
};