#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
class org{
private:
	int lei;
	bool age;
	int eat;
public:
	org(){ lei = 0;	eat = 0; }
	org(int b) :lei(b){ eat = 0; }
	virtual void move(int &x, int &y, org *a[20][20]){}
	virtual void breed(int times, int x, int y, org *a[20][20]){	}
	int getlei(){ return  lei; }
	void seteat(int a){ eat = a; }
	void addeat(){ eat++; }
	int outeat(){ return eat; }
	virtual void starve(int x, int y, org *b[20][20]){}
	void setage(bool a){ age = a; }
	bool outage(){ return age; }
};
class my : public org{
public:
	my() :org(){}
	my(int b) : org(b){}
	virtual void outlei(){ cout << "my" << endl; }
	void move(int &x, int &y, org *a[20][20]){
		srand((unsigned)time(NULL));
		int f = rand() % 4 + 1;
		if (f == 1){
			if (x - 1 >= 0){
				if (a[x - 1][y] == NULL){
					org *b = a[x][y];
					a[x][y] = NULL;
					x--;
					a[x][y] = b;
				}
			}
		}
		if (f == 2){
			if (x + 1 <= 19){
				if (a[x + 1][y] == NULL){
					org *b = a[x][y];
					a[x][y] = NULL;
					x++;
					a[x][y] = b;
				}
			}
		}
		if (f == 3){
			if (y - 1 >= 0){
				if (a[x][y - 1] == NULL){
					org *b = a[x][y];
					a[x][y] = NULL;
					y--;
					a[x][y] = b;
				}
			}
		}
		if (f == 4){
			if (y + 1 <= 19){
				if (a[x][y + 1] == NULL){
					org *b = a[x][y];
					a[x][y] = NULL;
					y++;
					a[x][y] = b;
				}
			}
		}
	}
	void breed(int times, int x, int y, org *a[20][20]){
		if (times % 3 == 0){
			srand((unsigned)time(NULL));
			int f = rand() % 4 + 1;
			if (f == 1){
				if (x - 1 >= 0){
					if (a[x - 1][y] == NULL){
						org *b = new my(1);
						x--;
						a[x][y] = b;
					}
				}
			}
			if (f == 2){
				if (x + 1 <= 19){
					if (a[x + 1][y] == NULL){
						org *b = new my(1);
						x++;
						a[x][y] = b;
					}
				}
			}
			if (f == 3){
				if (y - 1 >= 0){
					if (a[x][y - 1] == NULL){
						org *b = new my(1);
						y--;
						a[x][y] = b;
					}
				}
			}
			if (f == 4){
				if (y + 1 <= 19){
					if (a[x][y + 1] == NULL){
						org *b = new my(1);
						y++;
						a[x][y] = b;
					}
				}
			}
		}
	}
};
class sy : public org{
public:
	sy(int a) :org(a){}
	void move(int &x, int &y, org *a[20][20]){
		srand((unsigned)time(NULL));
		int f = rand() % 4 + 1;
		bool p = false;
		if (x - 1 >= 0){
			if (a[x - 1][y] != NULL){
				if (a[x - 1][y]->getlei() == 1){
					a[x - 1][y] = a[x][y];
					a[x][y] = NULL;
					x--;
					p = true;
					a[x][y]->seteat(0);
				}
			}
		}
		if (x + 1 <= 19 && p == false){
			if (a[x + 1][y] != NULL){
				if (a[x + 1][y]->getlei() == 1){
					a[x + 1][y] = a[x][y];
					a[x][y] = NULL;
					x++;
					p = true;
					a[x][y]->seteat(0);
				}
			}
		}
		if (y - 1 >= 0 && p == false){
			if (a[x][y - 1] != NULL){
				if (a[x][y - 1]->getlei() == 1){
					a[x][y - 1] = a[x][y];
					a[x][y] = NULL;
					y--;
					p = true;
					a[x][y]->seteat(0);
				}
			}
		}
		if (y + 1 <= 19 && p == false){
			if (a[x][y + 1] != NULL){
				if (a[x][y + 1]->getlei() == 1){
					a[x][y + 1] = a[x][y];
					a[x][y] = NULL;
					y++;
					p = true;
					a[x][y]->seteat(0);
				}
			}
		}
		if (f == 1 && p == false){
			if (x - 1 >= 0){
				if (a[x - 1][y] == NULL){
					a[x - 1][y] = a[x][y];
					a[x][y] = NULL;
					x--;
					a[x][y]->addeat();
				}
			}
		}
		if (f == 2 && p == false){
			if (x + 1 <= 19){
				if (a[x + 1][y] == NULL){
					a[x + 1][y] = a[x][y];
					a[x][y] = NULL;
					x++;
					a[x][y]->addeat();
				}
			}
		}
		if (f == 3 && p == false){
			if (y - 1 >= 0){
				if (a[x][y - 1] == NULL){
					a[x][y - 1] = a[x][y];
					a[x][y] = NULL;
					y--;
					a[x][y]->addeat();
				}
			}
		}
		if (f == 4 && p == false){
			if (y + 1 <= 19){
				if (a[x][y + 1] == NULL){
					a[x][y + 1] = a[x][y];
					a[x][y] = NULL;
					y++;
					a[x][y]->addeat();
				}
			}
		}
	}
	virtual void breed(int times, int x, int y, org *a[20][20]){
		if (times % 8 == 0){
			srand((unsigned)time(NULL));
			int f = rand() % 4 + 1;
			if (f == 1){
				if (x - 1 >= 0){
					if (a[x - 1][y] == NULL){ a[x - 1][y] = new sy(2); }
				}
			}
			if (f == 2){
				if (x + 1 <= 19){
					if (a[x + 1][y] == NULL){ a[x + 1][y] = new sy(2); }
				}
			}
			if (f == 3){
				if (y - 1 >= 0){
					if (a[x][y - 1] == NULL){ a[x][y - 1] = new sy(2); }
				}
			}
			if (f == 4){
				if (y + 1 <= 19){
					if (a[x][y + 1] == NULL){ a[x][y + 1] = new sy(2); }
				}
			}
		}
	}
	virtual void starve(int x, int y, org *b[20][20]){
		if (b[x][y]->outeat() == 3){ b[x][y] = NULL; }
	}
};

int main(int argc, char* argv[])
{
	org *a[20][20] = { NULL };
	int times = 1, z = 0, s = 0;
	char kong = ' ';
	for (int i = 0; i<20; i += 2){
		for (int j = 0; j<20; j += 2){
			my *b = new my(1);
			a[i][j] = b;
		}
	}
	a[5][5] = new sy(2);
	a[7][7] = new sy(2);
	a[9][9] = new sy(2);
	a[11][11] = new sy(2);
	a[13][13] = new sy(2);
	kong = cin.get();
	while (kong == '\n'){
		z = 0;
		s = 0;
		for (int i = 0; i<20; i++){
			for (int j = 0; j<20; j++){
				if (a[i][j] != NULL){
					if (!a[i][j]->outage()){
						int x, y;
						x = i;
						y = j;
						a[i][j]->move(x, y, a);
						if (a[x][y]->getlei() == 2){
							a[x][y]->starve(x, y, a);
							if (a[x][y] == NULL)
								break;
						}
						a[x][y]->breed(times, x, y, a);
					}
				}
			}
		}
		for (int i = 0; i<20; i++){
			for (int j = 0; j<20; j++){
				if (a[i][j] != NULL){
					a[i][j]->setage(false);
					if (a[i][j]->getlei() == 1){
						z++;
						cout << 'O' << ' ';
					}
					else if (a[i][j]->getlei() == 2){
						cout << 'X' << ' ';
						s++;
					}
				}
				else{ cout << ' ' << ' '; }
			}
			cout << endl;
		}
		cout << z << " " << s << endl;
		times++;
		cin.get(kong);
	}
	system("pause");
	return 0;
}
