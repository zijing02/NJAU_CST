#include"SyntaxAnalyzer.h"
#include"LexicalAnalyzer.h"
#include"SemanticAnalyzer.h"
SyntaxAnalyzer::SyntaxAnalyzer(LexicalAnalyzer l, Semantic_Analyzer s) {
	les = l;
	sem = s;
	init_token1();
	init_str();
	init_Grammar();
	init_SLR();
}
void SyntaxAnalyzer::init_token1() {
	map<string, int> tmp = les.get_token();
	for (auto it = tmp.begin(); it != tmp.end(); it++) {
		string s = it->first;
		int value = it->second;
		token1.insert(make_pair(value, s));
	}
}
void SyntaxAnalyzer::init_str()
{
	input = les.return_syn_arr();
	input.push_back(18);
	instr = les.return_scan_arr();
	instr.push_back("#");
	for (auto it = instr.begin(); it != instr.end(); it++)
		len += it->size();
	len += 1;
	state.push_back(0);
	Node node = { 18, "#" };
	symbol.push_back(node);
	sem.set_symbol(symbol, top);
	top = symbol.size() - 1;
	sem.set_symbol(symbol, top);
}
void SyntaxAnalyzer::init_Grammar()
{
	// 构造语法，只需要知道规约成什么符号以及规约几个字符即可
	// grammar[i][0]为规约成什么字符，其中S'不存在设置为100 grammar[i][1]为规约几个字符
	grammar[0][0] = 100;
	grammar[0][1] = 1; // S’->S
	grammar[1][0] = 19;
	grammar[1][1] = 3; // S->id := E
	grammar[2][0] = 19;
	grammar[2][1] = 5; // S->if E then M S
	grammar[3][0] = 19;
	grammar[3][1] = 9; // S->if E then M S N else M S
	grammar[4][0] = 19;
	grammar[4][1] = 6; // S->while M E do M S
	grammar[5][0] = 19;
	grammar[5][1] = 4; // S->S;M S
	grammar[6][0] = 20;
	grammar[6][1] = 0; // M->ε
	grammar[7][0] = 21;
	grammar[7][1] = 0; // N->ε
	grammar[8][0] = 22;
	grammar[8][1] = 3; // E->E + E
	grammar[9][0] = 22;
	grammar[9][1] = 3; // E->E * E
	grammar[10][0] = 22;
	grammar[10][1] = 2; // E->-E
	grammar[11][0] = 22;
	grammar[11][1] = 1; // E->id
	grammar[12][0] = 22;
	grammar[12][1] = 4; // E->E || E
	grammar[13][0] = 22;
	grammar[13][1] = 4; // E->E && E
	grammar[14][0] = 22;
	grammar[14][1] = 2; // E->!E
	grammar[15][0] = 22;
	grammar[15][1] = 3; // E->(E)
	grammar[16][0] = 22;
	grammar[16][1] = 3; // E->E rop E
	grammar[17][0] = 22;
	grammar[17][1] = 1; // E->True
	grammar[18][0] = 22;
	grammar[18][1] = 1; // E->False
}
void SyntaxAnalyzer::init_SLR()
{
	// 向slr中填入数据的集中方法
	//[]：slr[make_pair(0,4)]=action{1,4};
	// emplace：slr.emplace(make_pair(0,4),action{1,4});
	// slr.insert(make_pair(make_pair(0,4),action{1,4}));
	slr.insert({ {0, 1}, {1, 4} });
	slr.insert({ {0, 2}, {1, 3} });
	slr.insert({ {0, 4}, {1, 2} });
	slr.insert({ {0, 19}, {1, 1} });
	slr.insert({ {1, 5}, {1, 5} });
	slr.insert({ {1, 18}, {1, 0} });
	slr.insert({ {2, 6}, {1, 6} });
	slr.insert({ {3, 4}, {1, 9} });
	slr.insert({ {3, 9}, {1, 8} });
	slr.insert({ {3, 10}, {1, 11} });
	slr.insert({ {3, 16}, {1, 12} });
	slr.insert({ {3, 17}, {1, 13} });
	slr.insert({ {3, 22}, {1, 7} });
	slr.insert({ {3, 25}, {1, 10} });
	slr.insert({ {4, 1}, {2, 6} });
	slr.insert({ {4, 2}, {2, 6} });
	slr.insert({ {4, 4}, {2, 6} });
	slr.insert({ {4, 9}, {2, 6} });
	slr.insert({ {4, 10}, {2, 6} });
	slr.insert({ {4, 16}, {2, 6} });
	slr.insert({ {4, 17}, {2, 6} });
	slr.insert({ {4, 20}, {1, 14} });
	slr.insert({ {4, 25}, {2, 6} });
	slr.insert({ {5, 1}, {2, 6} });
	slr.insert({ {5, 2}, {2, 6} });
	slr.insert({ {5, 4}, {2, 6} });
	slr.insert({ {5, 9}, {2, 6} });
	slr.insert({ {5, 10}, {2, 6} });
	slr.insert({ {5, 16}, {2, 6} });
	slr.insert({ {5, 17}, {2, 6} });
	slr.insert({ {5, 20}, {1, 15} });
	slr.insert({ {5, 25}, {2, 6} });
	slr.insert({ {6, 4}, {1, 9} });
	slr.insert({ {6, 9}, {1, 8} });
	slr.insert({ {6, 10}, {1, 11} });
	slr.insert({ {6, 16}, {1, 12} });
	slr.insert({ {6, 17}, {1, 13} });
	slr.insert({ {6, 22}, {1, 16} });
	slr.insert({ {6, 25}, {1, 10} });
	slr.insert({ {7, 3}, {1, 17} });
	slr.insert({ {7, 7}, {1, 18} });
	slr.insert({ {7, 8}, {1, 19} });
	slr.insert({ {7, 15}, {1, 22} });
	slr.insert({ {7, 23}, {1, 43} });
	slr.insert({ {7, 24}, {1, 44} });
	slr.insert({ {8, 4}, {1, 9} });
	slr.insert({ {8, 9}, {1, 8} });
	slr.insert({ {8, 10}, {1, 11} });
	slr.insert({ {8, 16}, {1, 12} });
	slr.insert({ {8, 17}, {1, 13} });
	slr.insert({ {8, 22}, {1, 23} });
	slr.insert({ {8, 25}, {1, 10} });
	slr.insert({ {9, 3}, {2, 11} });
	slr.insert({ {9, 5}, {2, 11} });
	slr.insert({ {9, 7}, {2, 11} });
	slr.insert({ {9, 8}, {2, 11} });
	slr.insert({ {9, 11}, {2, 11} });
	slr.insert({ {9, 12}, {2, 11} });
	slr.insert({ {9, 13}, {2, 11} });
	slr.insert({ {9, 15}, {2, 11} });
	slr.insert({ {9, 18}, {2, 11} });
	slr.insert({ {9, 23}, {2, 11} });
	slr.insert({ {9, 24}, {2, 11} });
	slr.insert({ {10, 4}, {1, 9} });
	slr.insert({ {10, 9}, {1, 8} });
	slr.insert({ {10, 10}, {1, 11} });
	slr.insert({ {10, 16}, {1, 12} });
	slr.insert({ {10, 17}, {1, 13} });
	slr.insert({ {10, 22}, {1, 24} });
	slr.insert({ {10, 25}, {1, 10} });
	slr.insert({ {11, 4}, {1, 9} });
	slr.insert({ {11, 9}, {1, 8} });
	slr.insert({ {11, 10}, {1, 11} });
	slr.insert({ {11, 16}, {1, 12} });
	slr.insert({ {11, 17}, {1, 13} });
	slr.insert({ {11, 22}, {1, 25} });
	slr.insert({ {11, 25}, {1, 10} });
	slr.insert({ {12, 3}, {2, 17} });
	slr.insert({ {12, 5}, {2, 17} });
	slr.insert({ {12, 7}, {2, 17} });
	slr.insert({ {12, 8}, {2, 17} });
	slr.insert({ {12, 11}, {2, 17} });
	slr.insert({ {12, 12}, {2, 17} });
	slr.insert({ {12, 13}, {2, 17} });
	slr.insert({ {12, 15}, {2, 17} });
	slr.insert({ {12, 18}, {2, 17} });
	slr.insert({ {12, 23}, {2, 17} });
	slr.insert({ {12, 24}, {2, 17} });
	slr.insert({ {13, 3}, {2, 18} });
	slr.insert({ {13, 5}, {2, 18} });
	slr.insert({ {13, 7}, {2, 18} });
	slr.insert({ {13, 8}, {2, 18} });
	slr.insert({ {13, 11}, {2, 18} });
	slr.insert({ {13, 12}, {2, 18} });
	slr.insert({ {13, 13}, {2, 18} });
	slr.insert({ {13, 15}, {2, 18} });
	slr.insert({ {13, 18}, {2, 18} });
	slr.insert({ {13, 23}, {2, 18} });
	slr.insert({ {13, 24}, {2, 18} });
	slr.insert({ {14, 4}, {1, 9} });
	slr.insert({ {14, 9}, {1, 8} });
	slr.insert({ {14, 10}, {1, 11} });
	slr.insert({ {14, 16}, {1, 12} });
	slr.insert({ {14, 17}, {1, 13} });
	slr.insert({ {14, 22}, {1, 26} });
	slr.insert({ {14, 25}, {1, 10} });
	slr.insert({ {15, 1}, {1, 4} });
	slr.insert({ {15, 2}, {1, 3} });
	slr.insert({ {15, 4}, {1, 2} });
	slr.insert({ {15, 19}, {1, 27} });
	slr.insert({ {16, 5}, {2, 1} });
	slr.insert({ {16, 7}, {1, 18} });
	slr.insert({ {16, 8}, {1, 19} });
	slr.insert({ {16, 13}, {2, 1} });
	slr.insert({ {16, 15}, {1, 22} });
	slr.insert({ {16, 18}, {2, 1} });
	slr.insert({ {16, 23}, {1, 43} });
	slr.insert({ {16, 24}, {1, 44} });
	slr.insert({ {17, 1}, {2, 6} });
	slr.insert({ {17, 2}, {2, 6} });
	slr.insert({ {17, 4}, {2, 6} });
	slr.insert({ {17, 9}, {2, 6} });
	slr.insert({ {17, 10}, {2, 6} });
	slr.insert({ {17, 16}, {2, 6} });
	slr.insert({ {17, 17}, {2, 6} });
	slr.insert({ {17, 20}, {1, 28} });
	slr.insert({ {17, 25}, {2, 6} });
	slr.insert({ {18, 4}, {1, 9} });
	slr.insert({ {18, 9}, {1, 8} });
	slr.insert({ {18, 10}, {1, 11} });
	slr.insert({ {18, 16}, {1, 12} });
	slr.insert({ {18, 17}, {1, 13} });
	slr.insert({ {18, 22}, {1, 29} });
	slr.insert({ {18, 25}, {1, 10} });
	slr.insert({ {19, 4}, {1, 9} });
	slr.insert({ {19, 9}, {1, 8} });
	slr.insert({ {19, 10}, {1, 11} });
	slr.insert({ {19, 16}, {1, 12} });
	slr.insert({ {19, 17}, {1, 13} });
	slr.insert({ {19, 22}, {1, 30} });
	slr.insert({ {19, 25}, {1, 10} });
	slr.insert({ {20, 4}, {1, 9} });
	slr.insert({ {20, 9}, {1, 8} });
	slr.insert({ {20, 10}, {1, 11} });
	slr.insert({ {20, 16}, {1, 12} });
	slr.insert({ {20, 17}, {1, 13} });
	slr.insert({ {20, 22}, {1, 31} });
	slr.insert({ {20, 25}, {1, 10} });
	slr.insert({ {21, 4}, {1, 9} });
	slr.insert({ {21, 9}, {1, 8} });
	slr.insert({ {21, 10}, {1, 11} });
	slr.insert({ {21, 16}, {1, 12} });
	slr.insert({ {21, 17}, {1, 13} });
	slr.insert({ {21, 22}, {1, 32} });
	slr.insert({ {21, 25}, {1, 10} });
	slr.insert({ {22, 4}, {1, 9} });
	slr.insert({ {22, 9}, {1, 8} });
	slr.insert({ {22, 10}, {1, 11} });
	slr.insert({ {22, 16}, {1, 12} });
	slr.insert({ {22, 17}, {1, 13} });
	slr.insert({ {22, 22}, {1, 33} });
	slr.insert({ {22, 25}, {1, 10} });
	slr.insert({ {23, 3}, {2, 10} });
	slr.insert({ {23, 5}, {2, 10} });
	slr.insert({ {23, 7}, {2, 10} });
	slr.insert({ {23, 8}, {2, 10} });
	slr.insert({ {23, 11}, {2, 10} });
	slr.insert({ {23, 12}, {2, 10} });
	slr.insert({ {23, 13}, {2, 10} });
	slr.insert({ {23, 15}, {2, 10} });
	slr.insert({ {23, 18}, {2, 10} });
	slr.insert({ {23, 23}, {2, 10} });
	slr.insert({ {23, 24}, {2, 10} });
	slr.insert({ {24, 3}, {2, 14} });
	slr.insert({ {24, 5}, {2, 14} });
	slr.insert({ {24, 7}, {2, 14} });
	slr.insert({ {24, 8}, {2, 14} });
	slr.insert({ {24, 11}, {2, 14} });
	slr.insert({ {24, 12}, {2, 14} });
	slr.insert({ {24, 13}, {2, 14} });
	slr.insert({ {24, 15}, {2, 14} });
	slr.insert({ {24, 18}, {2, 14} });
	slr.insert({ {24, 23}, {2, 14} });
	slr.insert({ {24, 24}, {2, 14} });
	slr.insert({ {25, 7}, {1, 18} });
	slr.insert({ {25, 8}, {1, 19} });
	slr.insert({ {25, 11}, {1, 34} });
	slr.insert({ {25, 15}, {1, 22} });
	slr.insert({ {25, 23}, {1, 43} });
	slr.insert({ {25, 24}, {1, 44} });
	slr.insert({ {26, 7}, {1, 18} });
	slr.insert({ {26, 8}, {1, 19} });
	slr.insert({ {26, 12}, {1, 35} });
	slr.insert({ {26, 15}, {1, 22} });
	slr.insert({ {26, 23}, {1, 43} });
	slr.insert({ {26, 24}, {1, 44} });
	slr.insert({ {27, 5}, {2, 5} });
	slr.insert({ {27, 13}, {2, 5} });
	slr.insert({ {27, 18}, {2, 5} });
	slr.insert({ {28, 1}, {1, 4} });
	slr.insert({ {28, 2}, {1, 3} });
	slr.insert({ {28, 4}, {1, 2} });
	slr.insert({ {28, 19}, {1, 36} });
	slr.insert({ {29, 3}, {2, 8} });
	slr.insert({ {29, 5}, {2, 8} });
	slr.insert({ {29, 7}, {2, 8} });
	slr.insert({ {29, 8}, {1, 19} });
	slr.insert({ {29, 11}, {2, 8} });
	slr.insert({ {29, 12}, {2, 8} });
	slr.insert({ {29, 13}, {2, 8} });
	slr.insert({ {29, 15}, {2, 8} });
	slr.insert({ {29, 18}, {2, 8} });
	slr.insert({ {29, 23}, {2, 8} });
	slr.insert({ {29, 24}, {2, 8} });
	slr.insert({ {30, 3}, {2, 9} });
	slr.insert({ {30, 5}, {2, 9} });
	slr.insert({ {30, 7}, {2, 9} });
	slr.insert({ {30, 8}, {2, 9} });
	slr.insert({ {30, 11}, {2, 9} });
	slr.insert({ {30, 12}, {2, 9} });
	slr.insert({ {30, 13}, {2, 9} });
	slr.insert({ {30, 15}, {2, 9} });
	slr.insert({ {30, 18}, {2, 9} });
	slr.insert({ {30, 23}, {2, 9} });
	slr.insert({ {30, 24}, {2, 9} });
	slr.insert({ {31, 3}, {2, 12} });
	slr.insert({ {31, 5}, {2, 12} });
	slr.insert({ {31, 7}, {1, 18} });
	slr.insert({ {31, 8}, {1, 19} });
	slr.insert({ {31, 11}, {2, 12} });
	slr.insert({ {31, 12}, {2, 12} });
	slr.insert({ {31, 13}, {2, 12} });
	slr.insert({ {31, 15}, {1, 22} });
	slr.insert({ {31, 18}, {2, 12} });
	slr.insert({ {31, 23}, {2, 12} });
	slr.insert({ {31, 24}, {1, 44} });
	slr.insert({ {32, 3}, {2, 13} });
	slr.insert({ {32, 5}, {2, 13} });
	slr.insert({ {32, 7}, {1, 18} });
	slr.insert({ {32, 8}, {1, 19} });
	slr.insert({ {32, 11}, {2, 13} });
	slr.insert({ {32, 12}, {2, 13} });
	slr.insert({ {32, 13}, {2, 13} });
	slr.insert({ {32, 15}, {1, 22} });
	slr.insert({ {32, 18}, {2, 13} });
	slr.insert({ {32, 23}, {2, 13} });
	slr.insert({ {32, 24}, {2, 13} });
	slr.insert({ {33, 3}, {2, 16} });
	slr.insert({ {33, 5}, {2, 16} });
	slr.insert({ {33, 7}, {1, 18} });
	slr.insert({ {33, 8}, {1, 19} });
	slr.insert({ {33, 11}, {2, 16} });
	slr.insert({ {33, 12}, {2, 16} });
	slr.insert({ {33, 13}, {2, 16} });
	slr.insert({ {33, 15}, {2, 16} });
	slr.insert({ {33, 18}, {2, 16} });
	slr.insert({ {33, 23}, {2, 16} });
	slr.insert({ {33, 24}, {2, 16} });
	slr.insert({ {34, 3}, {2, 15} });
	slr.insert({ {34, 5}, {2, 15} });
	slr.insert({ {34, 7}, {2, 15} });
	slr.insert({ {34, 8}, {2, 15} });
	slr.insert({ {34, 11}, {2, 15} });
	slr.insert({ {34, 12}, {2, 15} });
	slr.insert({ {34, 13}, {2, 15} });
	slr.insert({ {34, 15}, {2,15} });
	slr.insert({ {34, 18}, {2, 15} });
	slr.insert({ {34, 23}, {2, 15} });
	slr.insert({ {34, 24}, {2, 15} });
	slr.insert({ {35, 1}, {2, 6} });
	slr.insert({ {35, 2}, {2, 6} });
	slr.insert({ {35, 4}, {2, 6} });
	slr.insert({ {35, 9}, {2, 6} });
	slr.insert({ {35, 10}, {2, 6} });
	slr.insert({ {35, 16}, {2, 6} });
	slr.insert({ {35, 17}, {2, 6} });
	slr.insert({ {35, 20}, {1, 37} });
	slr.insert({ {35, 25}, {2, 6} });
	slr.insert({ {36, 5}, {2, 2} });
	slr.insert({ {36, 13}, {2, 7} });
	slr.insert({ {36, 18}, {2, 2} });
	slr.insert({ {36, 21}, {1, 38} });
	slr.insert({ {37, 1}, {1, 4} });
	slr.insert({ {37, 2}, {1, 3} });
	slr.insert({ {37, 4}, {1, 2} });
	slr.insert({ {37, 19}, {1, 39} });
	slr.insert({ {38, 13}, {1, 40} });
	slr.insert({ {39, 5}, {2, 4} });
	slr.insert({ {39, 13}, {2, 4} });
	slr.insert({ {39, 18}, {2, 4} });
	slr.insert({ {40, 1}, {2, 6} });
	slr.insert({ {40, 2}, {2, 6} });
	slr.insert({ {40, 4}, {2, 6} });
	slr.insert({ {40, 9}, {2, 6} });
	slr.insert({ {40, 10}, {2, 6} });
	slr.insert({ {40, 16}, {2, 6} });
	slr.insert({ {40, 17}, {2, 6} });
	slr.insert({ {40, 20}, {1, 41} });
	slr.insert({ {40, 25}, {2, 6} });
	slr.insert({ {41, 1}, {1, 4} });
	slr.insert({ {41, 2}, {1, 3} });
	slr.insert({ {41, 4}, {1, 2} });
	slr.insert({ {41, 19}, {1, 42} });
	slr.insert({ {42, 5}, {2, 3} });
	slr.insert({ {42, 13}, {2, 3} });
	slr.insert({ {42, 18}, {2, 3} });
	slr.insert({ {43, 4}, {2, 6} });
	slr.insert({ {43, 2}, {2, 6} });
	slr.insert({ {43, 1}, {2, 6} });
	slr.insert({ {43, 9}, {2, 6} });
	slr.insert({ {43, 25}, {2, 6} });
	slr.insert({ {43, 10}, {2, 6} });
	slr.insert({ {43, 16}, {2, 6} });
	slr.insert({ {43, 17}, {2, 6} });
	slr.insert({ {43, 20}, {1, 20} });
	slr.insert({ {44, 4}, {2, 6} });
	slr.insert({ {44, 2}, {2, 6} });
	slr.insert({ {44, 1}, {2, 6} });
	slr.insert({ {44, 9}, {2, 6} });
	slr.insert({ {44, 25}, {2, 6} });
	slr.insert({ {44, 10}, {2, 6} });
	slr.insert({ {44, 16}, {2, 6} });
	slr.insert({ {44, 17}, {2, 6} });
	slr.insert({ {44, 20}, {1, 21} });
}
void SyntaxAnalyzer::work()
{
	cout << endl << "SyntaxAnalyzer analyse：" << endl;
	// it为输入串中的第一个符号
	auto it = input.begin();
	int idx = 0, place = 0, result = 0;
	while (it != input.end())
	{
		cout << "step: " << step << "\t\t";
		print_vector();
		top = symbol.size() - 1;
		sem.set_symbol(symbol, top);
		// state.back()为状态栈栈顶元素，*it为当前输入符号
		// 通过二者的组合在SLR表中找到对应的动作it2{flag,val}
		auto it2 = slr.find(make_pair(state.back(), *it));
		if (it2 != slr.end()) {
			// 移进操作，直接将it2->second.val压入状态栈，并将it压入符号栈
			cout << "action：";
			if (it2->second.flag == 1)
			{
				Node node;
				node.type = *it;
				node.name = instr[idx];
				if (*it == 4 || *it == 16 || *it == 17) {
					int place = les.find_symbol(instr[idx]);
					node.place = place;
				}
				if (it2->second.val == 0)
				{
					/*state.pop_back();
					state.pop_back();
					symbol.pop_back();
					symbol.pop_back();
					input.erase(input.begin());*/
					Node node;
					sem.reduction(it2->second.val, node);
					cout << "acc";
					result = 1;
				}
				else
					cout << "S" << it2->second.val;
				state.push_back(it2->second.val);
				symbol.push_back(node);
				sem.set_symbol(symbol, top);
				input.erase(input.begin());
				idx++;
			}
			// 归约操作，根据it2->second.val在grammar中找到对应的产生式
			// 将符号栈顶的符号按照grammar[it2->second.val][1]的长度弹出
			// 将grammar[it2->second.val][0]的产生式的左部符号压入符号栈
			else if (it2->second.flag == 2)
			{
				Node node;
				node.type = grammar[it2->second.val][0];
				//调用语义分析模块进行语义分析
				sem.reduction(it2->second.val, node);
				cout << "r" << it2->second.val << "\t";
				for (int i = 0; i < grammar[it2->second.val][1]; i++)
				{
					state.pop_back();
					symbol.pop_back();
					sem.set_symbol(symbol, top);
				}
				symbol.push_back(node);
				sem.set_symbol(symbol, top);
				auto it3 = slr.find(make_pair(state.back(), grammar[it2->second.val][0]));
				if (it3 != slr.end())
					cout << "GOTO：" << it3->second.val,
					state.push_back(it3->second.val);
			}
		}
		else {
			/*
			auto it4 = slr.find(make_pair(state.back(), 18));
			input.emplace(input.begin() + idx, "#");
			if (it4->second.flag == 2)
			{
				cout<<"action";
				Node node;
				node.type = grammar[it4->second.val][0];
				//调用语义分析模块进行语义分析
				sem.reduction(it4->second.val, node);
				cout << "r" << it4->second.val << "\t";
				for (int i = 0; i < grammar[it4->second.val][1]; i++)
				{
					state.pop_back();
					symbol.pop_back();
					sem.set_symbol(symbol, top);
				}
				symbol.push_back(node);
				sem.set_symbol(symbol, top);
				auto it3 = slr.find(make_pair(state.back(), grammar[it4->second.val][0]));
				if (it3 != slr.end())
					cout << "GOTO：" << it3->second.val,
					state.push_back(it3->second.val);
			}
			else {
			*/
			for (int i = 0; i < 64; i++)
				cout << "-";
			cout << endl;
			cout << endl << "error：" << endl << "step：" << step << " "
				<< "状态" << state.back() << "遇到" << token1[*it] << "无法识别" << endl
				<< "输入的" << instr[idx] << "或者" << symbol.back().name << "不符合预期" << endl;
			break;
		}
		cout << endl;
		for (int i = 0; i < 64; i++)
			cout << "-";
		cout << endl;
		it = input.begin();
		step++;
	}
	if (result) cout << "输入语句符合语法" << endl;
	cout << endl << "semantic analysis:" << endl;
	sem.print();
}
void SyntaxAnalyzer::print_vector()
{
	cout << "state: ";
	for (int num : state) {
		if (num >= 10)
			cout << "(" << num << ")";
		else
			cout << num;
	}
	cout << endl;
	cout << "symbol: ";
	for (Node node : symbol)
		cout << token1[node.type] << " ";
	cout << endl;
	cout << "input: ";
	for (int num : input)
		cout << token1[num] << " ";

	cout << endl;
}
void SyntaxAnalyzer::print_slr()
{
	cout << endl << "构造的SLR表如下：" << endl << "SLR(1)表中共有：" << slr.size() << "项" << endl;
	for (int i = 0; i <= 42; i++)
	{
		if (i == 0)
		{
			cout << "\t";
			for (int k = 1; k < 26; k++) {
				if (k == 14)
					continue;
				cout << k << "\t";
			}
		}
		cout << endl;
		for (int j = 0; j < 26; j++)
		{
			if (j == 0)
			{
				cout << i << "\t";
				continue;
			}
			auto it = slr.find(make_pair(i, j));
			if (it != slr.end())
			{
				if (it->second.val == 0)
					cout << "acc";
				else
				{
					if (it->second.flag == 1)
						cout << "S";
					else if (it->second.flag == 2)
						cout << "r";
					cout << it->second.val;
				}
			}
			// cout << "(" << j << ")" << "\t";
			cout << "\t";
		}
		cout << endl;
		for (int k = 0; k < 8 * 25; k++)
			cout << "-";
		cout << endl;
	}
}