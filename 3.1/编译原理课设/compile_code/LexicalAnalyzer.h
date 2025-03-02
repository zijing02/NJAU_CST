#pragma once
#include<iostream>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>
#include<fstream>
#include"SyntaxAnalyzer.h"
#include"LexicalAnalyzer.h"
#include"SemanticAnalyzer.h"
using namespace std;
class CreateToken {
	map<string, int> token;
public:
	CreateToken();
	~CreateToken();
	void readFile(string path = "token.txt");
	void splitString(string str);
	map<string, int> getToken();
};

class LexicalAnalyzer {
	map<string, int> token;
	int line_count = 0;
	bool end_flag = false;
	vector<int> syn_arr;
	vector<string> symbol_table;
	string scan_table[100];
	string reserved_word_table[100];
	vector<string> scan_arr;
public:
	LexicalAnalyzer();
	LexicalAnalyzer(map<string, int> token);
	~LexicalAnalyzer();
	void readCode(string path = "code.txt");
	void createReversedWordTable();
	bool Analyse(string str);
	bool isKeyword(string str);
	int  find_scan(string str);
	int  find_symbol(string str);
	vector<int> return_syn_arr();
	vector<string> return_scan_arr();
	map<string, int> get_token();
	vector<string>get_symbol_table();
};


