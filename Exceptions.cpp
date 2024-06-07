#include<iostream>
using namespace std;
const int MAX = 3;

class Stack{
	private:
		int st[MAX];
		int top;
		
	public:
		Class Full{};
		Class Empty{};
		
	Stack()
	{
		top = -1;
	}
	
	void push(int var)
	{
		if(top = MAX-1)
		{
			throw full();
		}
		
		st[++top] = var;
	}
	
	int pop()
	{
		if(top<0)
		{
			throw Empty();
		}
		return st[top--];
	}
	
};

int main()
{
	Stack s1;
	try
	{
		s1.push(11);
		s1.push(22);
		s1.push(33;)
		s1.push(55);
		
		cout<<";
	}
}