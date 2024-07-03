#include <iostream>
using namespace std;

//�迭�� �̿��� ���� ����

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

void push(mystack& s, int value) //���� X�� ���ÿ� �ִ´�.
{
	s.arr[s.top] = value;
	s.top++;
	s.size++;
}

void pop(mystack& s) //���ÿ� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
{
	if (s.front == s.top) { cout << -1 << '\n'; }
	else
	{
		cout << s.arr[s.top -1] << '\n';
		s.top--;
		s.size--;
	}
}

void size(mystack& s) //���ÿ� ����ִ� ������ ������ ����Ѵ�.
{
	cout << s.top - s.front << '\n';
}

void empty(mystack& s) //������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
{
	if(s.front == s.top) { cout << 1 <<'\n'; }
	else { cout << 0 << '\n'; }
}

void top(mystack& s) //���ÿ� ������ �ִٸ� �� ���� ������ ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
{
	if (s.front == s.top) { cout << -1 << '\n'; }
	else
	{
		cout << s.arr[s.top - 1] << '\n';
	}
}
