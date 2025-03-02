#include"SyntaxAnalyzer.h"
#include"LexicalAnalyzer.h"
#include"SemanticAnalyzer.h"
Semantic_Analyzer::Semantic_Analyzer() {}
Semantic_Analyzer::Semantic_Analyzer(vector<string>& symbol_table) // TAC下标从1开始
{
    this->symbol_table = symbol_table;
    newtemp = symbol_table.size() - 1;
    nextstm = 1;
    TAC.push_back(Three_Address_Code{ " ", "_", "_", "_" });
}
Semantic_Analyzer::~Semantic_Analyzer()
{
    nextstm = 0;
    TAC.clear();
}
void Semantic_Analyzer::makelist(vector<int>& list, int code)
{
    list.push_back(code);
}
void Semantic_Analyzer::merge(vector<int>& list, vector<int>& p1, vector<int>& p2)
{
    for (int i = 0; i < p1.size(); i++)
        list.push_back(p1[i]);
    for (int i = 0; i < p2.size(); i++)
        list.push_back(p2[i]);
    p1.clear(), p2.clear();
}
void Semantic_Analyzer::backpatch(vector<int>& list, int code)
{
    for (int i = 0; i < list.size(); i++)
        TAC[list[i]].code = "(" + to_string(code) + ")";
}
void Semantic_Analyzer::emit(string j, string a, string b, string code)
{
    TAC.push_back({ j, a, b, code });
    nextstm++;
}
void Semantic_Analyzer::print()
{
    for (int i = 1; i < TAC.size(); i++)
    {
        cout << '(' << i << ')' << ' ';
        cout << '(' << TAC[i].j << ' ';
        cout << TAC[i].a << ' ';
        cout << TAC[i].b << ' ';
        cout << TAC[i].code << ')' << endl;
    }
}
int Semantic_Analyzer::lookup(Node name)
{
    return name.place;
}
void Semantic_Analyzer::reduction(int type, Node& P) // r0~r18,规约成P
{
    if (type == 0)// S' -> S
    {
        backpatch(symbol[top].nextlist, nextstm);
        emit("acc", "_", "_", "_");
    }
    else if (type == 1) // S -> id := E
    {
        int p = lookup(symbol[top - 2]);
        if (p)
            emit(":=", symbol_table[symbol[top].place], "_", symbol_table[p]);
        else
            ; // error
    }
    else if (type == 2) // S -> if E then M S
    {
        backpatch(symbol[top - 3].truelist, symbol[top - 1].code);
        merge(P.nextlist, symbol[top - 3].falselist, symbol[top].nextlist);
    }
    else if (type == 3) // S -> if E then M1 S1 N else M2 S2
    {
        backpatch(symbol[top - 7].truelist, symbol[top - 5].code);
        backpatch(symbol[top - 7].falselist, symbol[top - 1].code);
        P.nextlist = symbol[top - 4].nextlist;
        merge(P.nextlist, symbol[top - 3].nextlist, symbol[top].nextlist);
    }
    else if (type == 4) // S -> while M1 E do M2 S1
    {
        backpatch(symbol[top - 3].truelist, symbol[top - 1].code);
        P.nextlist = symbol[top - 3].falselist;
        emit("j", "_", "_", "(" + to_string(symbol[top - 4].code) + ")");
        backpatch(symbol[top].nextlist, symbol[top - 4].code);
    }
    else if (type == 5) // S -> S1 ; M S2
    {
        backpatch(symbol[top - 3].nextlist, symbol[top - 1].code);
        P.nextlist = symbol[top].nextlist;
    }
    else if (type == 6) // M -> e
    {
        P.code = nextstm;
    }
    else if (type == 7) // N -> e
    {
        makelist(P.nextlist, nextstm);
        emit("j", "_", "_", "_");
    }
    else if (type == 8) // E -> E1 + E2
    {
        P.place = ++newtemp;
        symbol_table.push_back("T" + to_string(P.place));
        emit("+", symbol_table[symbol[top - 2].place], symbol_table[symbol[top].place], symbol_table[P.place]);
    }
    else if (type == 9) // E-> E1 * E2
    {
        P.place = ++newtemp;
        symbol_table.push_back("T" + to_string(P.place));
        emit("*", symbol_table[symbol[top - 2].place], symbol_table[symbol[top].place], symbol_table[P.place]);
    }
    else if (type == 10) // E -> -E1
    {
        P.place = ++newtemp;
        symbol_table.push_back("T" + to_string(P.place));
        emit("-", symbol_table[symbol[top].place], "_", symbol_table[P.place]);
    }
    else if (type == 11) // E -> id
    {
        P.place = ++newtemp;
        symbol_table.push_back("T" + to_string(P.place));
        int p = lookup(symbol[top]);
        if (p)
            P.place = p;
        else
            ; // error
    }
    else if (type == 12) // E -> E1 || M E2
    {
        backpatch(symbol[top - 3].falselist, symbol[top - 1].code);
        merge(P.truelist, symbol[top - 3].truelist, symbol[top].truelist);
        P.falselist = symbol[top].falselist;
    }
    else if (type == 13) // E -> E1 && M E2
    {
        backpatch(symbol[top - 3].truelist, symbol[top - 1].code);
        merge(P.falselist, symbol[top - 3].falselist, symbol[top].falselist);
        P.truelist = symbol[top].truelist;
    }
    else if (type == 14) // E -> ! E1
    {
        P.truelist = symbol[top].falselist;
        P.falselist = symbol[top].truelist;
    }
    else if (type == 15) // E -> (E1)   
    {
        //{:= ,E1.place,, E.place}    ??
        P.truelist = symbol[top].truelist;
        P.falselist = symbol[top].falselist;
    }
    else if (type == 16) // E -> E1 rop E2
    {
        makelist(P.truelist, nextstm);
        makelist(P.falselist, nextstm + 1);
        symbol_table.push_back("T" + to_string(P.place));
        emit(symbol[top - 1].name, symbol_table[symbol[top - 2].place], symbol_table[symbol[top].place], "_"); // rop.op*
        emit("j", "_", "_", "_");
    }
    else if (type == 17) // E -> True
    {
        makelist(P.truelist, nextstm);
        int p = lookup(symbol[top]);
        P.place = p;
        emit("j", "_", "_", "_");
    }
    else if (type == 18) // E -> False
    {
        makelist(P.falselist, nextstm);
        int p = lookup(symbol[top]);
        P.place = p;
        emit("j", "_", "_", "_");
    }
}
void Semantic_Analyzer::set_symbol(vector<Node>& s, int t) {
    symbol = s;
    top = t;
}