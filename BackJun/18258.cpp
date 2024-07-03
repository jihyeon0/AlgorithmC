#include <iostream>
#include <cstring>
using namespace std;

//ť ����, ���� ť, �迭
//����ť ����(�� ���� �߰� �Ұ�, ������ ������ �̵�) ������ ���� ť
//���ϴ� ũ�⸸ŭ �޸� �Ҵ� �ޱ� ���ؼ� �����迭�� �ƴ϶� �����迭 ���


typedef struct Queue
{
	int* arr;
	int front; // ������ġ
	int rear; // ������ġ
	int size; // ���Ұ���
	int capacity; // �迭�ǿ뷮, �����ִ����尳��
}Queue;

void queInit(Queue* que, int size);
void push(Queue* que, int value);
void pop(Queue* que);
void size(Queue* que);
void empty(Queue* que);
void front(Queue* que);
void back(Queue* que);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Queue que;
	

	int N{ 0 }, num{ 0 };
	string order;
	cin >> N;
	queInit(&que, N);

	while (N--)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> num;
			push(&que, num);
		}
		else if (order == "pop")
		{
			pop(&que);
		}
		else if (order == "size")
		{
			size(&que);
		}
		else if (order == "empty")
		{
			empty(&que);
		}
		else if (order == "front")
		{
			front(&que);
		}
		else if (order == "back")
		{
			back(&que);
		}
	}


	return 0;
}

void queInit(Queue* que, int size)
{
	que->arr = new int[size];
	que->front = 0;
	que->rear = 0;
	que->size = 0;
	que->capacity = size;
}

/*ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. 
���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.*/
void pop(Queue* que)
{
	if (que->size == 0) { printf("%d\n", -1); return; }//ť�� ����� �� pop�� ���
		
	printf("%d\n", que->arr[que->front]);
	que->front++;
	que->size--;

	if (que->front == que->capacity) //������ ���� ���� ��
	{
		que->front = 0;  
	}
	/*
	if (que->front == que->rear)�� ���ϸ� �ȵǴ� ���� :  
	pop�� �ѹ��� ���� �ʰ� ������ ���ұ��� �߰��ϸ� front�� 0, rear�� 0�� �ȴ�. 
	�̶� ���Ұ� ���� ���־ front�� rear�� ���Ƽ� ť�� ����ٰ� �Ǵܵ�
	*/
	
}

void size(Queue* que)
{
	printf("%d\n", que->size);
}

void empty(Queue* que) //ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
{
	if (que->front == que->rear) { printf("%d\n", 1);}
	else{ printf("%d\n", 0); }
}

/*
ť�� ���� �տ� �ִ� ������ ����Ѵ�. 
���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/
void front(Queue* que)
{
	if(que->front == que->rear) { printf("%d\n", -1); }
	else
	{
		printf("%d\n", que->arr[que->front]);
	}
}

void back(Queue* que)
{
	if (que->front == que->rear) { printf("%d\n", -1); }
	else
	{
		printf("%d\n", que->arr[(que->rear)-1]);
	}
}


void push(Queue* que, int value)//push X : ���� X�� ť�� �ִ� �����̴�.
{
	if (que->rear == que->capacity) { return; } //ť�� �� á�� ��
	
	que->arr[que->rear] = value;
	que->rear++;
	que->size++;

	if (que->rear == que->capacity)//push�ϰ� ť�� �� á�� ��
	{ que->rear = 0;} // rear�� �Τ������� ��� ���¿��� �����Ǵ� �� ����
}


