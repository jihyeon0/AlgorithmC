#include <iostream>

using namespace std;

//����� ����Ʈ�� �̿��� ��ť(��) ����

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
		case 1: //���� X�� ���� �տ� �ִ´�.
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
			++size;//������++
		}
		break;

		case 2://���� X�� ���� �ڿ� �ִ´�.
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
			++size;//������++
		}
		break;

		case 3: //���� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
		{
			if (size == 0) { cout << -1 << '\n'; }
			else
			{
				cout << pHead->value << '\n';
				if (size == 1)//������ ������ ��
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

		case 4: //���� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
		{
			if (size == 0) { cout << -1 << '\n'; }
			else
			{
				cout << pTail->value << '\n';

				if (size == 1)//������ ������ ��
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

		case 5: // ���� ����ִ� ������ ������ ����Ѵ�.
		{
			cout << size << '\n';
		}
		break;

		case 6: //���� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
		{
			cout << (size == 0) ? true : false;
			cout << '\n';
		}
		break;

		case 7: //���� ������ �ִٸ� �� ���� ������ ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
		{
			(size != 0) ? cout << pHead->value << '\n' : cout << -1 << '\n';
		}
		break;

		case 8: //���� ������ �ִٸ� �� ���� ������ ����Ѵ�. ���ٸ� -1�� ��� ����Ѵ�.
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
