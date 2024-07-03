#include <iostream>
using namespace std;

//배열을 이용한 스텍 구현

typedef struct mystack
{
	int* arr;
	int front;
	int top;
	int size;
	int capacity;
}mystack;

void stackInit(mystack& s, int size);
void push(mystack& s, int value);
void pop(mystack& s);
void size(mystack& s);
void empty(mystack& s);
void top(mystack& s);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, order, value;
	cin >> N;
	mystack s;
	stackInit(s, N);

	while (N--)
	{
		cin >> order;
		if (order == 1)
		{
			cin >> value;
			push(s, value);
		}
		else if (order == 2)
		{
			pop(s);
		}
		else if (order == 3)
		{
			size(s);
		}
		else if (order == 4)
		{
			empty(s);
		}
		else if (order == 5)
		{
			top(s);
		}
	}

	return 0;
}

void stackInit(mystack& s, int size)
{
	s.arr = new int[size];
	s.front=0;
	s.top =0;
	s.size=0;
	s.capacity = size;
}

void push(mystack& s, int value) //정수 X를 스택에 넣는다.
{
	s.arr[s.top] = value;
	s.top++;
	s.size++;
}

void pop(mystack& s) //스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
{
	if (s.front == s.top) { cout << -1 << '\n'; }
	else
	{
		cout << s.arr[s.top -1] << '\n';
		s.top--;
		s.size--;
	}
}

void size(mystack& s) //스택에 들어있는 정수의 개수를 출력한다.
{
	cout << s.top - s.front << '\n';
}

void empty(mystack& s) //스택이 비어있으면 1, 아니면 0을 출력한다.
{
	if(s.front == s.top) { cout << 1 <<'\n'; }
	else { cout << 0 << '\n'; }
}

void top(mystack& s) //스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
{
	if (s.front == s.top) { cout << -1 << '\n'; }
	else
	{
		cout << s.arr[s.top - 1] << '\n';
	}
}
