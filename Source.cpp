#include <vector>
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 10
template <class T> class Stack
{
private:
	T* a;
	int _size;
	int top;
public:
	Stack()
	{
		_size = DEFAULT_SIZE;
		a = new T[_size];
		top = -1;
	}
	void push(T number)
	{
		if (this->is_full())
		{
			T* b = new T[2*_size];
			_size*=2;
			for (int i = 0;i<_size;i++)
			{
				b[i] = a[i];
			}
			delete[] a;
			a = b;

		}
		a[++top] = number;
	}
	T pop()
	{
		if (this->is_empty())
		{
			throw "Stack is empty";
		}
		else
		{
			return a[top--];
		}
	}
	bool is_empty()
	{
		return top == -1;
	}
	bool is_full()
	{
		return top == (_size - 1);
	}
	int size()
	{
		return _size;
	}
	void print()
	{
		for (int i = 0;i<=this->top;i++)
		{
			cout << (*this).a[i] << " ";
		}
	}
};

int main()
{
	int n;
	Stack <double> a;
	for (int i = 0;i<10;i++)
	{
		a.push((double)i);
	}
	a.print(); cout << endl;
	for(int i = 0;i<2;i++)
	{
		a.push((double)i);
	}
	a.print(); cout << endl;
	for(int i = 0;i<2;i++)
	{
		a.pop();
	}
	a.print();
	cin >> n;
}
