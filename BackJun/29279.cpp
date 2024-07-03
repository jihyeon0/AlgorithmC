#include <iostream>

using namespace std;

//양방향 리스트를 이용한 디큐(덱) 구현

typedef struct node
{
	int value;
	struct node* next;
	struct node* prev;
}node;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	node* pHead{ nullptr }, *pTail{ nullptr };

	int N, order, value, size{ 0 };
	cin >> N;

	while (N--)
	{
		cin >> order;

		switch (order)
		{
		case 1: //정수 X를 덱의 앞에 넣는다.
		{
			cin >> value;

			if (size == 0)
			{
				pHead = pTail = new node;
				pHead->value = value;
				pHead->prev = nullptr;
				pHead->next = nullptr;
			}
			else
			{
				pHead->prev = new node;
				pHead->prev->next = pHead;
				pHead->prev->prev = nullptr;
				pHead->prev->value = value;
				pHead = pHead->prev;

			}
			++size;//사이즈++
		}
		break;

		case 2://정수 X를 덱의 뒤에 넣는다.
		{
			cin >> value;

			if (size == 0)
			{
				pHead = pTail = new node;
				pTail->value = value;
				pTail->prev = nullptr;
				pTail->next = nullptr;
			}
			else
			{
				pTail->next = new node;
				pTail->next->prev = pTail;
				pTail->next->next = nullptr;
				pTail->next->value = value;
				pTail = pTail->next;

			}
			++size;//사이즈++
		}
		break;

		case 3: //덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
		{
			if (size == 0) { cout << -1 << '\n'; }
			else
			{
				cout << pHead->value << '\n';
				if (size == 1)//마지막 원소일 때
				{
					delete pHead;
					pHead = nullptr;
					pTail = nullptr;
					--size;
				}
				else
				{
					node* nexthead = pHead->next;
					delete pHead;
					pHead = nexthead;
					pHead->prev = nullptr;

					--size;
				}
			}
		}
		break;

		case 4: //덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
		{
			if (size == 0) { cout << -1 << '\n'; }
			else
			{
				cout << pTail->value << '\n';

				if (size == 1)//마지막 원소일 때
				{
					delete pTail;
					pHead = nullptr;
					pTail = nullptr;
					--size;
				}
				else
				{
					node* nextprev = pTail->prev;
					delete pTail;
					pTail = nextprev;
					pTail->next = nullptr;
					--size;
				}
			}
		}
		break;

		case 5: // 덱에 들어있는 정수의 개수를 출력한다.
		{
			cout << size << '\n';
		}
		break;

		case 6: //덱이 비어있으면 1, 아니면 0을 출력한다.
		{
			cout << (size == 0) ? true : false;
			cout << '\n';
		}
		break;

		case 7: //덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
		{
			(size != 0) ? cout << pHead->value << '\n' : cout << -1 << '\n';
		}
		break;

		case 8: //덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
		{
			(size != 0) ? cout << pTail->value << '\n' : cout << -1 << '\n';
		}
		break;
		default:
			break;

		}
	}

	return 0;
}
