#include<iostream>
using namespace std;
const int SIZE = 10;
using namespace std;
class Full
{
private:
	int a;
public:
	Full(int i);
	int getValue();
};
class Empty
{
public:
	void show();
};
class Stack
{
private:
	int stack[SIZE];
	int tos;
public:
	Stack();
	void push(int a);
	int pop();
	int top()const;
};
Full::Full(int i)
{
	a = i;       // 栈满后加入的元素，赋值给a
}
int Full::getValue()
{
	return a;     //抛出栈满后的元素
}
void Empty::show()
{
	cout << "stack is empty!" << endl;
}
Stack::Stack()//构造函数
{
	tos = -1;      //类似栈的头指针，用来判断栈满栈空
}
void Stack::push(int a)//入栈
{
	if (tos >= SIZE - 1)   //先判断栈满栈空，此时说明栈满
	{
		throw  Full(a);  //抛出栈满后的元素
	}
	else
	{
		stack[++tos] = a;  //否则就入栈
	}
}
int Stack::pop()//出栈
{
	if (tos == -1)        //此时栈为空
	{
		throw  Empty(); //这个是根据catch捕获的数据类型来决定要抛出什么类型的数据
	}
	else
	{
		return stack[tos--];  //出栈相应的tos--
	}
}
int main()
{
	Stack s;
	int b[20], i = 0;
	try
	{
		cin >> b[i];
		while (b[i])
		{
			s.push(b[i]);
			++i;
			cin >> b[i];
		}
		for (i = 0; i < SIZE; i++)
			cout << s.pop();
	}
	catch (Full e)
	{
		cout << "Exception: Stack Full..." << endl;
		cout << "The value not push in stack: " << e.getValue() << endl;
	}
	catch (Empty e)
	{
		e.show();
	}
	return 0;
}
