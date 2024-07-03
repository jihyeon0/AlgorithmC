#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include<vector>
#include <math.h>
using namespace std;

//��� �� �Է� ������ ù��°�� ������ ��Ʈ����� ���� ������ Ǭ �ڵ�

//dfs�� Ǯ�� �ʰ� �Լ��� ����
//����� �ڽ��� �ƿ� �������� �ʾҴٸ� nullptr
//�����Ǿ��� ������ ��� ����� value = 999
//��� ���� �� ��ü ������ȸ�ϸ鼭 ������� ã��
//struct Node
//{
//    Node* parents = nullptr;
//    Node* left = nullptr;
//    Node* right = nullptr;
//    int   value = 999;
//};
//
//
//int N, del, cnt{ 0 };
//int arr[51];
//vector<Node*> nodevec;
//
//
//void Findlast(Node* node)
//{
//    if (node == nullptr || node->value == 999)
//        return;
//    //�ڽ��� ���� ��带 �߰��ϸ� cnt++
//    if (node->left == nullptr && node->right == nullptr)
//    {
//        cnt++;
//        return;
//    }
//    if (node->left->value == 999 && node->right->value == 999)
//    {
//        cnt++;
//    }
//    Findlast(node->left);
//    Findlast(node->right);
//    
//}
//
//void DelteNode(Node* node)
//{
//    if (node->value == 999)
//        return;
//
//    //�ڽ��� ���� ��
//    if (node->left == nullptr && node->right == nullptr)
//    {
//        //�θ���� ���� ����
//        if (node->value % 2 == 1)
//        {
//            //node->parents->left = nullptr;
//            node->value = 999;
//        }
//        else
//        {
//            //node->parents->right = nullptr;
//            node->value = 999;
//        }
//        //�ڽ� ����
//       // delete node;
//        //node = nullptr;
//    }
//    //�� �� ���� ��
//    else if (node->left != nullptr && node->right != nullptr)
//    {
//        DelteNode(node->left);
//        DelteNode(node->right);
//        //�ڽ� ����
//        //delete node;
//        //node = nullptr;
//        node->value = 999;
//    }
//    //�ϳ��� ���� ��
//    else
//    {
//        if (node->left != nullptr)
//        {
//            DelteNode(node->left);
//        }
//        else
//        {
//            DelteNode(node->right);
//        }
//        //�ڽ� ����
//        //delete node;
//        //node = nullptr;
//        node->value = 999;
//    }
//}
//
//int main()
//{
//    EASYINPUT;
//    
//    cin >> N;
//    fill(&arr[0], &arr[0]+51, 999 );
//
//    for (int i = 0; i < N; ++i)
//    {
//        cin >> arr[i];
//    }
//
//    //���� ����
//    for (int i = 0; i < N; ++i)
//    {
//        if (arr[i] == -1) //���� ��� ����
//        {
//            Node* node = new Node;
//            node->parents = nullptr;
//            node->value = i;
//            nodevec.push_back(node);
//        }
//        else
//        {
//            if (i % 2 == 1) //Ȧ�� == ��
//            {
//                Node* node = new Node; 
//                nodevec.push_back(node);
//                node->parents = nodevec[arr[i]];
//                node->parents->left = node;
//                node->value = i;
//            }
//            else//¦�� == ��
//            {
//                Node* node = new Node;
//                nodevec.push_back(node);
//                node->parents = nodevec[arr[i]];
//                node->parents->right = node;
//                node->value = i;
//            }
//        }
//    }
//    
//    //������ ��� �Է�
//    cin >> del;
//
//    //��ȸ�ϸ鼭 ��尪Ȯ��
//    
//    for (auto vec : nodevec)
//    {
//        if(vec == nullptr)
//            continue;
//        if (vec->value != del)
//            continue;
//
//        //������ �ڽ��� �� ���� ������ Ž��
//        //��� �����ϸ鼭 �ö��
//
//        DelteNode(vec);
//        Findlast(nodevec[0]);
//    }
//
//    cout << cnt;
//    return 0;
//}

//��� �� �Է� ������ ������� ���� Ǭ �ڵ�
//dfs ���,  Ǯ�� �ڵ� �����
#include <iostream>
#include <vector>

using namespace std;

int N;
int nodeToRemove;
int answer = 0;
vector<vector<int>> tree;
vector<bool> visited;

void dfs(int cur)
{
    //�ڽ��� ������ ���� ���
    if (0 == tree[cur].size())
    {
        answer++;
        return;
    }

    //�ڽ��� �ϳ��ε� ������ �� ����� ���� ��尡 ���� ��尡 ��
    if (1 == tree[cur].size() && nodeToRemove == tree[cur][0])
    {
        answer++;
        return;
    }

    for (int i = 0; tree[cur].size() > i; i++)
    {
        auto next = tree[cur][i];
        //���� ��带 �湮���� �ʾ����鼭 ������ �� ��尡 �ƴ� �� �湮
        if (!visited[next] && nodeToRemove != next)
        {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main()
{
    cin >> N;

    int root;
    tree.assign(N, vector<int>(0));
    for (int i = 0; N > i; i++)
    {
        int input;
        cin >> input;

        //�Է��� -1�̶�� ��Ʈ ���
        if (-1 == input) root = i;
        else
            tree[input].emplace_back(i);
    }

    cin >> nodeToRemove;

    if (nodeToRemove != root)
    {
        visited.assign(N, false);
        visited[root] = true;
        dfs(root);
    }

    cout << answer;

    return 0;
}
