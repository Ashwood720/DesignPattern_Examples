#include "iostream"

using namespace std;

class StackIterator;

class DataStack
{
public:
	friend class StackIterator;
	DataStack()
	{
		Lenght = -1;
	}
	void push(int value)
	{
		Items[++Lenght] = value;
	}
	int pop()
	{
		return Items[Lenght--];
	}

private:
	int Items[10];
	int Lenght;
};

class StackIterator
{
public:
	StackIterator(const DataStack& st) : Stack(st)
	{
		Index = 0;
	}

	void operator++()
	{
		Index++;
	}

	int operator*()
	{
		return Stack.Items[Index];
	}
	bool operator()()
	{
		return Index != Stack.Lenght + 1;
	}

private:
	const DataStack& Stack;
	int Index;
};

bool operator==(const DataStack& s1, const DataStack& s2)
{
	StackIterator it1(s1), it2(s2);

	for(; it1(); ++it1, ++it2)
	{
		if (*it1 != *it2) break;
	}
	return !it1() && !it2();
}

int main()
{
	DataStack stack1;
	for (int i = 1; i < 5; i++)
	{
		stack1.push(i);
	}
	DataStack stack2(stack1);

	cout << boolalpha << (stack1 == stack2) << endl;

	stack1.push(10);

	cout << boolalpha << (stack1 == stack2) << endl;

}