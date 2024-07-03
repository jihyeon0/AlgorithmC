#include <iostream>
#include <map>
#include <algorithm>
#include<Windows.h>
using namespace std;

// ����Ž��Ʈ��, ����ü�� Ŭ������ �̿��Ͽ� ����

//��� ����ü ���� -> � �����͵��� ��� �־���ϴ°�
//����,��ġ, �ִ�, �ּ�,�ؽ�Ʈ, ����, ���ġ ����

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
	Node* search(Node* node, int key); //�Է¹��� Ű�� Ʈ���� �ִ���
	void Delete(int key); // ���� ����� �ڽ��� ���� ���, �ڽ��� 1���� ���, �ڽ��� 2���� ���
	void Delete(Node* node);
	void Replace(Node* deletenode, Node* node);
	Node* Next(Node* node); //���� ū �� ã�´�
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
	//��� ����
	Node* newnode = new Node();
	//����忡 key �Է�
	newnode->key = key;
	
	//�������� �޿� �Ǵ�
	if (root == nullptr) //��ó�� ����
	{
		root = newnode;
		return;
	}

	//�ڽ��� �־��ٸ�
	
		Node* node = root;
		Node* parent = nullptr;
	
		//�ڽ��� ���� �� �Ʒ� �θ��� ã��
		while (node != nullptr)
		{
			parent = node;

			if (node->key > key) //�����̶��
			{
				node = node->left;
			}
			else  //�������̶��
			{
				node = node->right;
			}
		}
		// whlie������ node = node->left==nullptr�� Ż���ϸ�
		// �����ص״� parent�� ���� parent==���� �Ǵ� ������ �ڽ��� ���� �θ� ���
		
		//�ڽĳ�忡�� �θ� ���
		newnode->parent = parent;

		//�θ��忡�� �ڽ� ���
		//�θ����� ����ʿ� �߰��ؾ��ϴ��� �Ǵ�
		if (parent->key > key) //�θ��� �����̶��
			parent->left = newnode;
		else
			parent->right = newnode;
}

// ���ǿ��� 14:19
Node* BinarySearchTree::search(Node* node, int key)
{
	//��� �̿�
	//Ż�� ����
	if (node == nullptr || node->key == key)
		return node;
	if (key< node->key) //�����̸�
		return search(node->left, key);
	else
		return search(node->right, key);
}

void BinarySearchTree::Delete(int key)
{
	//������ ����� ���ڽ��� ���ٸ� ������ �ڽ��� �ø���
	//������ ����� �����ڽ��� ���ٸ� ���� �ڽ��� �ø���
	//�Ѵ��ִٸ� ������ ��� Ű���� ���� ���� �ø�
	Node* deletenode = search(root, key);
	Delete(deletenode);
}

void BinarySearchTree::Delete(Node* node)
{
	//������ ����� ���ڽ��� ���ٸ� ������ �ڽ��� �ø���
	//������ ����� �����ڽ��� ���ٸ� ���� �ڽ��� �ø���
	//�Ѵ��ִٸ� ������ ��� Ű���� ���� ���� �ø�
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
	//������ ����� �θ�� ������ ����� �ڽ��� ����
	if (deletenode->parent == nullptr) //������尡 ���ʿ� ��Ʈ�� ���
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
	//�������� ū ��
	//������ ���(10)�� �ڽ��� �ִ� ���
	//     10
	//   5    20
	// 1  3  15 21
	if (node->right)
		return Min(node->right);
	//������ ���(15)�� �ڽ��� ���� ���
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
		cout << "����\n";
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







































////�迭 ��� ����Ž��
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
//		if (m < arr[mid]) //�߰� ���� m�� ���� ���
//		{
//			right = mid - 1;
//		}
//		else if (m > arr[mid]) //�߰� ���� m�� ū ���
//		{
//			left = mid + 1;
//		}
//		else // ã�� ���
//		{
//			cout << "1\n";
//			return;
//		}
//	}
//	if (left > right) // ã�� ���� ���
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
//	//���� ����
//	sort(arr.begin(), arr.end());
//
//	cin >> M;
//	//�̺�Ž��
//	for (int i = 0; i < M; ++i)
//	{
//		cin >> Mnum;
//		binarySearch(Mnum);
//	}
//	return 0;
//}