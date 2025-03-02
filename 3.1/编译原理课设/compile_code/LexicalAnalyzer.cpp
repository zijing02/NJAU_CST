#include"SyntaxAnalyzer.h"
#include"LexicalAnalyzer.h"
#include"SemanticAnalyzer.h"
CreateToken::CreateToken() {
    this->readFile();
}
CreateToken::~CreateToken() {}
void CreateToken::readFile(string path) {
    string line;
    int value;
    ifstream inputFile(path);
    if (!inputFile) {
        cerr << "无法打开文件 " << path << endl;
        return;
    }
    while (getline(inputFile, line)) {
        this->splitString(line);
    }
    inputFile.close();
}
void CreateToken::splitString(string str) {
    size_t pos = str.find(' ');
    if (pos != string::npos) {
        string first = str.substr(0, pos);
        string second = str.substr(pos + 1);
        size_t endPos = second.find_last_not_of(" \t");
        if (endPos != string::npos) {
            second = second.substr(0, endPos + 1);
        }
        else {
            second = "";
        }
        this->token.insert(pair<string, int>(second, stoi(first)));
    }
}
map<string, int> CreateToken::getToken() {
    return this->token;
}
LexicalAnalyzer::LexicalAnalyzer() {}
LexicalAnalyzer::LexicalAnalyzer(map<string, int> token) {
    symbol_table.push_back("");
    this->token = token;
    this->createReversedWordTable();
    this->readCode();
}
LexicalAnalyzer::~LexicalAnalyzer() {}
void LexicalAnalyzer::readCode(string path) {
    string line;
    ifstream inputFile(path);
    if (!inputFile) {
        cerr << "无法打开文件 " << path << endl;
        return;
    }
    while (getline(inputFile, line)) {
        if (this->Analyse(line) == false) {
            cout << this->line_count << "error" << endl;
        }
        /* if (line == "#") {
             cout << "catch end" << endl;
             this->end_flag = true;
             break;
         }*/
    }
    /*if (!this->end_flag) {
        cerr << endl << "error:\nnot catch end '#'" << endl;
        exit(0);
    }*/
    inputFile.close();
}
bool LexicalAnalyzer::Analyse(string str) {
    this->line_count++;
    int value = 0;
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
        case ' ':
            break;
        case '\t':
            break;

        case ':':
            i++;
            value = token[":"];
            if (str[i] == '=') {
                value = token[":="];
                this->scan_table[value] = ":=";
                cout << "catch := " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
            }
            else {
                this->scan_table[value] = ":";
                cout << "catch : " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
            }
            break;

        case 'w':
            if (str[i] == 'w') {
                if (str.substr(i, 5) == "while") {
                    value = token["while"];
                    this->scan_table[value] = "while";
                    cout << "catch while " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(scan_table[value]);
                    i += 4;
                    break;
                }
            }

        case 'i':
            if (str[i] == 'i') {
                if (str.substr(i, 2) == "if") {
                    value = token["if"];
                    this->scan_table[value] = "if";
                    cout << "catch if " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(scan_table[value]);
                    i += 1;
                    break;
                }
            }

        case 't':
            if (str.substr(i, 4) == "then") {
                value = token["then"];
                this->scan_table[value] = "then";
                cout << "catch then " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                i += 3;
                break;
            }
        case ';':
            if (str[i] == ';') {
                value = token[";"];
                this->scan_table[value] = ";";
                cout << "catch ; " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }

        case '+':
            if (str[i] == '+') {
                value = token["+"];
                this->scan_table[value] = "+";
                cout << "catch + " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }

        case '*':
            if (str[i] == '*') {
                value = token["*"];
                this->scan_table[value] = "*";
                cout << "catch * " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }

        case '-':
            if (str[i] == '-') {
                value = token["-"];
                this->scan_table[value] = "-";
                cout << "catch - " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }

        case '(':
            if (str[i] == '(') {
                value = token["("];
                this->scan_table[value] = "(";
                cout << "catch ( " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }
        case ')':
            if (str[i] == ')') {
                value = token[")"];
                this->scan_table[value] = ")";
                cout << "catch ) " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }
        case '>':
            if (str[i] == '>') {
                if (i + 1 < str.length() && str[i + 1] == '=') {
                    value = token["rop"];
                    this->scan_table[value] = "rop";
                    cout << "catch rop " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(">=");
                    i++;
                }
                else {
                    value = token["rop"];
                    this->scan_table[value] = "rop";
                    cout << "catch rop " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(">");
                }
                break;
            }

        case '<':
            if (str[i] == '<') {
                if (i + 1 < str.length() && str[i + 1] == '=') {
                    value = token["rop"];
                    this->scan_table[value] = "rop";
                    cout << "catch rop " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back("<=");
                    i++;
                }
                else if (i + 1 < str.length() && str[i + 1] == '>') {
                    value = token["rop"];
                    this->scan_table[value] = "rop";
                    cout << "catch rop " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back("<>");
                    i++;
                }
                else {
                    value = token["rop"];
                    this->scan_table[value] = "rop";
                    cout << "catch rop " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back("<");
                }
                break;
            }

        case 'T':
            if (str.substr(i, 4) == "True") {
                value = token["True"];
                this->scan_table[value] = "True";
                this->symbol_table.push_back("True");
                cout << "catch True " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                i += 3;
                break;
            }

        case 'F':
            if (str.substr(i, 5) == "False") {
                value = token["False"];
                this->scan_table[value] = "False";
                this->symbol_table.push_back("False");
                cout << "catch False " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                i += 4;
                break;
            }


        case 'S':
            if (str[i] == 'S') {
                value = token["S"];
                this->scan_table[value] = "S";
                cout << "catch S " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }


        case 'M':
            if (str[i] == 'M') {
                value = token["M"];
                this->scan_table[value] = "M";
                cout << "catch M " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }


        case 'N':
            if (str[i] == 'N') {
                value = token["N"];
                this->scan_table[value] = "N";
                cout << "catch N " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }


        case 'E':
            if (str[i] == 'E') {
                value = token["E"];
                this->scan_table[value] = "E";
                cout << "catch E " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }


        case '|':
            if (str[i] == '|') {
                if (str[i + 1] = '|') {
                    value = token["||"];
                    this->scan_table[value] = "||";
                    cout << "catch || " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(scan_table[value]);
                    i++;
                }
                break;
            }

        case '&':
            if (str[i] == '&') {
                if (str[i + 1] = '&') {
                    value = token["&&"];
                    this->scan_table[value] = "&&";
                    cout << "catch && " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(scan_table[value]);
                    i++;
                }
                break;
            }

        case '!':
            if (str[i] == '!') {
                value = token["!"];
                this->scan_table[value] = "!";
                cout << "catch ! " << value << endl;
                syn_arr.push_back(value);
                scan_arr.push_back(scan_table[value]);
                break;
            }

        case 'd':
            if (str[i] == 'd') {
                if (str[i + 1] == 'o') {
                    value = token["do"];
                    this->scan_table[value] = "do";
                    cout << "catch do " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(scan_table[value]);
                    i++;
                    break;
                }
            }
        case 'e':
            if (str[i] == 'e') {
                if (str.substr(i, 4) == "else") {
                    value = token["else"];
                    this->scan_table[value] = "else";
                    cout << "catch else " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(scan_table[value]);
                    i += 3;
                    break;

                }
            }

        default:
            if (isalpha(str[i]) || str[i] == '_') {
                int start = i;
                while (i < str.length() && (isalnum(str[i]) || str[i] == '_')) {
                    i++;
                }
                string identifier = str.substr(start, i - start);
                if (isKeyword(identifier)) {
                    this->scan_table[token[identifier]] = identifier;
                    cout << "catch " << identifier << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(identifier);

                }
                else {
                    value = token["id"];
                    this->scan_table[value] = "id";
                    bool if_find = 0;
                    for (string element : symbol_table) {
                        if (identifier == element) {
                            if_find = 1;
                        }
                    }
                    if (!if_find) {
                        symbol_table.push_back(identifier);
                    }
                    cout << "catch id " << value << endl;
                    syn_arr.push_back(value);
                    scan_arr.push_back(identifier);

                }
                i--;
            }
            else {
                cout << str[i] << "非法变量名" << endl;
                exit(0);
            }
            break;
        }
    }
    return true;
}
void LexicalAnalyzer::createReversedWordTable() {
    int i = 0;
    for (auto iter = token.begin(); iter != token.end(); ++iter)
    {
        string s = iter->first;
        char c = s.front();
        if (tolower(c) >= 'a' && tolower(c) <= 'z' && s.length() > 1 && s != "rop" && s != "True" && s != "False") {
            reserved_word_table[i] = s;
            i++;
        }
    }
}
bool LexicalAnalyzer::isKeyword(string str) {
    for (int i = 0; i < 100; i++) {
        if (str == reserved_word_table[i]) {
            return true;
        }
    }
    return false;
}
int LexicalAnalyzer::find_scan(string str) {
    for (int i = 0; i < token.size(); i++) {
        if (scan_table[i] == str) {
            return i;
        }
    }
    return 0;
}
int LexicalAnalyzer::find_symbol(string str) {
    for (int i = 0; i < symbol_table.size(); i++) {
        if (symbol_table[i] == str) {
            return i;
        }
    }
    return 0;
}
vector<int> LexicalAnalyzer::return_syn_arr() {
    return syn_arr;
}
vector<string> LexicalAnalyzer::return_scan_arr() {
    return scan_arr;
}
map<string, int> LexicalAnalyzer::get_token() {
    return token;
}
vector<string> LexicalAnalyzer::get_symbol_table() {
    return symbol_table;
}