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
struct action
{
	// flag为1表示移进操作，不区分终结符还是非终结符，为2表示规约操作，区分终结符还是非终结符
	// val为移进或规约后应该向状态栈中压入的状态或者应该使用哪一条产生式进行规约
	int flag;
	int val;
};
class SyntaxAnalyzer
{
	int step = 0;					 // 步骤
	int top = 0;						 // 符号栈顶指针
	int len = 0;						//输入串长度
	int grammar[30][2];				 // 文法
	vector<int> state;				 // 状态栈
	vector<Node> symbol;				 // 符号栈
	vector<int> input;				 // 输入符号
	vector<string>instr;
	map<int, string>token1;			//数字向字符串转换的token
	map<pair<int, int>, action> slr; // slr表
	LexicalAnalyzer les;
	Semantic_Analyzer sem;
public:
	SyntaxAnalyzer(LexicalAnalyzer l, Semantic_Analyzer s);
	void init_token1();
	void init_str();
	void init_Grammar();
	void init_SLR();
	void work();
	void print_slr();
	void print_vector();
};