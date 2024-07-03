#include <iostream>
#include <map>
#include <algorithm>
#include<Windows.h>
using namespace std;

// 이진탐색트리, 구조체와 클래스를 이용하여 구현

//노드 구조체 정의 -> 어떤 데이터들을 들고 있어야하는가
//삽입,서치, 최대, 최소,넥스트, 삭제, 재배치 구현

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;

	int key;
};

class BinarySearchTree
{
public:
	void insert(int key);
	Node* search(Node* node, int key); //입력받은 키가 트리에 있는지
	void Delete(int key); // 삭제 노드의 자식이 없는 경우, 자식이 1개인 경우, 자식이 2개인 경우
	void Delete(Node* node);
	void Replace(Node* deletenode, Node* node);
	Node* Next(Node* node); //다음 큰 수 찾는다
	Node* Min(Node* node);
	Node* Max(Node* node);
public:
	Node* GetNode() { return root; }
	void SetCursorPos(int x, int y);
	void Print() { Print(root, 10, 0); };
	void Print(Node* node, int x, int y);
private:
	Node* root = nullptr;
};

void BinarySearchTree::SetCursorPos(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x),static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPos(x, y);

	cout << node->key;

	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}



void BinarySearchTree::insert(int key)
{
	//노드 생성
	Node* newnode = new Node();
	//뉴노드에 key 입력
	newnode->key = key;
	
	//꼭대기부터 왼오 판단
	if (root == nullptr) //맨처음 삽입
	{
		root = newnode;
		return;
	}

	//자식이 있었다면
	
		Node* node = root;
		Node* parent = nullptr;
	
		//자식이 없는 맨 아래 부모노드 찾기
		while (node != nullptr)
		{
			parent = node;

			if (node->key > key) //왼쪽이라면
			{
				node = node->left;
			}
			else  //오른쪽이라면
			{
				node = node->right;
			}
		}
		// whlie문에서 node = node->left==nullptr로 탈출하면
		// 저장해뒀던 parent로 저장 parent==왼쪽 또는 오른쪽 자식이 없는 부모 노드
		
		//자식노드에서 부모 등록
		newnode->parent = parent;

		//부모노드에서 자식 등록
		//부모노드의 어느쪽에 추가해야하는지 판단
		if (parent->key > key) //부모의 왼쪽이라면
			parent->left = newnode;
		else
			parent->right = newnode;
}

// 강의영상 14:19
Node* BinarySearchTree::search(Node* node, int key)
{
	//재귀 이용
	//탈출 조건
	if (node == nullptr || node->key == key)
		return node;
	if (key< node->key) //왼쪽이면
		return search(node->left, key);
	else
		return search(node->right, key);
}

void BinarySearchTree::Delete(int key)
{
	//삭제할 노드의 왼자식이 없다면 오른쪽 자식을 올리고
	//삭제할 노드의 오른자식이 없다면 왼쪽 자식을 올리고
	//둘다있다면 삭제할 노드 키값의 다음 수를 올림
	Node* deletenode = search(root, key);
	Delete(deletenode);
}

void BinarySearchTree::Delete(Node* node)
{
	//삭제할 노드의 왼자식이 없다면 오른쪽 자식을 올리고
	//삭제할 노드의 오른자식이 없다면 왼쪽 자식을 올리고
	//둘다있다면 삭제할 노드 키값의 다음 수를 올림
	if (node == nullptr)
		return;

	if (node->left == nullptr)
	{
		Replace(node, node->right);
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	else
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BinarySearchTree::Replace(Node* deletenode, Node* node)
{
	//삭제할 노드의 부모와 삭제할 노드의 자식을 연결
	if (deletenode->parent == nullptr) //삭제노드가 애초에 루트인 경우
		root = node;
	else if (deletenode == deletenode->parent->left)
		deletenode->parent->left = node;
	else
		deletenode->parent->right = node;

	if (node)
		node->parent = deletenode->parent;
}

Node* BinarySearchTree::Next(Node* node)
{
	//다음으로 큰 수
	//삭제할 노드(10)의 자식이 있는 경우
	//     10
	//   5    20
	// 1  3  15 21
	if (node->right)
		return Min(node->right);
	//삭제할 노드(15)의 자식이 없는 경우
	//     10
	//   5    20
	// 1  3  15 21

	Node* parent = node->parent;
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}
	return parent;
}

Node* BinarySearchTree::Min(Node* node)
{
	while(node->left)
		 node = node->left;
	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
		node = node->right;
	return node;
}

int main(void)
{
	BinarySearchTree bst;
	bst.insert(10);
	bst.Print();
	bst.insert(1);
	bst.Print();
	bst.insert(15);
	bst.Print();
	bst.insert(20);
	bst.Print();
	bst.insert(7);
	bst.Print();
	bst.insert(5);
	bst.Print();

	cout << "\n";
	cout << "\n";
	int num;
	cin >> num;
	Node* result = bst.search(bst.GetNode(), num);
	if (result == nullptr)
		cout << "없음\n";
	else
		cout << result->key<<"\n";

	result = bst.Min(bst.GetNode());
	cout << result->key << "\n";

	result = bst.Max(bst.GetNode());
	cout << result->key << "\n";

	bst.Delete(7);
	bst.Print();

	return 0;
}







































////배열 기반 이진탐색
//vector<int> arr;
//
//void binarySearch(int m)
//{
//	int left, mid, right;
//	left = 0;
//	right = arr.size() - 1;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (m < arr[mid]) //중간 보다 m이 작은 경우
//		{
//			right = mid - 1;
//		}
//		else if (m > arr[mid]) //중간 보다 m이 큰 경우
//		{
//			left = mid + 1;
//		}
//		else // 찾은 경우
//		{
//			cout << "1\n";
//			return;
//		}
//	}
//	if (left > right) // 찾지 못한 경우
//	{
//		cout << "0\n";
//		return;
//	}
//}
//
//int main()
//{
//
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	int N, Nnum,M, Mnum;
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> Nnum;
//		arr.push_back(Nnum);
//	}
//	//벡터 정렬
//	sort(arr.begin(), arr.end());
//
//	cin >> M;
//	//이분탐색
//	for (int i = 0; i < M; ++i)
//	{
//		cin >> Mnum;
//		binarySearch(Mnum);
//	}
//	return 0;
//}