#include <iostream>
#include <cstring>
using namespace std;

//큐 구현, 원형 큐, 배열
//선형큐 단점(꽉 차면 추가 불가, 삭제시 앞으로 이동) 보완한 원형 큐
//원하는 크기만큼 메모리 할당 받기 위해서 정적배열이 아니라 동적배열 사용


typedef struct Queue
{
	int* arr;
	int front; // 삭제위치
	int rear; // 삽입위치
	int size; // 원소개수
	int capacity; // 배열의용량, 원소최대저장개수
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

/*큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 
만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/
void pop(Queue* que)
{
	if (que->size == 0) { printf("%d\n", -1); return; }//큐가 비었을 때 pop한 경우
		
	printf("%d\n", que->arr[que->front]);
	que->front++;
	que->size--;

	if (que->front == que->capacity) //마지막 원소 삭제 후
	{
		que->front = 0;  
	}
	/*
	if (que->front == que->rear)로 비교하면 안되는 이유 :  
	pop을 한번도 하지 않고 마지막 원소까지 추가하면 front는 0, rear은 0이 된다. 
	이때 원소가 가득 차있어도 front와 rear이 같아서 큐가 비었다고 판단됨
	*/
	
}

void size(Queue* que)
{
	printf("%d\n", que->size);
}

void empty(Queue* que) //큐가 비어있으면 1, 아니면 0을 출력한다.
{
	if (que->front == que->rear) { printf("%d\n", 1);}
	else{ printf("%d\n", 0); }
}

/*
큐의 가장 앞에 있는 정수를 출력한다. 
만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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


void push(Queue* que, int value)//push X : 정수 X를 큐에 넣는 연산이다.
{
	if (que->rear == que->capacity) { return; } //큐가 다 찼을 때
	
	que->arr[que->rear] = value;
	que->rear++;
	que->size++;

	if (que->rear == que->capacity)//push하고 큐가 다 찼을 때
	{ que->rear = 0;} // rear이 인ㄴ덱스를 벗어난 상태에서 참조되는 걸 방지
}


