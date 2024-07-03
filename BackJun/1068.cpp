#define EASYINPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include<vector>
#include <math.h>
using namespace std;

//노드 값 입력 순서의 첫번째가 무조건 루트노드인 경우로 문제를 푼 코드

//dfs로 풀지 않고 함수로 구현
//노드의 자식이 아예 생성되지 않았다면 nullptr
//생성되었다 삭제한 경우 노드의 value = 999
//노드 삭제 후 전체 중위순회하면서 리프노드 찾음
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
//    //자식이 없는 노드를 발견하면 cnt++
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
//    //자식이 없을 때
//    if (node->left == nullptr && node->right == nullptr)
//    {
//        //부모노드와 연결 끊음
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
//        //자신 삭제
//       // delete node;
//        //node = nullptr;
//    }
//    //둘 다 있을 때
//    else if (node->left != nullptr && node->right != nullptr)
//    {
//        DelteNode(node->left);
//        DelteNode(node->right);
//        //자신 삭제
//        //delete node;
//        //node = nullptr;
//        node->value = 999;
//    }
//    //하나만 있을 때
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
//        //자신 삭제
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
//    //구조 생성
//    for (int i = 0; i < N; ++i)
//    {
//        if (arr[i] == -1) //최초 노드 생성
//        {
//            Node* node = new Node;
//            node->parents = nullptr;
//            node->value = i;
//            nodevec.push_back(node);
//        }
//        else
//        {
//            if (i % 2 == 1) //홀수 == 왼
//            {
//                Node* node = new Node; 
//                nodevec.push_back(node);
//                node->parents = nodevec[arr[i]];
//                node->parents->left = node;
//                node->value = i;
//            }
//            else//짝수 == 오
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
//    //삭제할 노드 입력
//    cin >> del;
//
//    //순회하면서 노드값확인
//    
//    for (auto vec : nodevec)
//    {
//        if(vec == nullptr)
//            continue;
//        if (vec->value != del)
//            continue;
//
//        //맞으면 자식이 더 없을 때까지 탐색
//        //노드 삭제하면서 올라옴
//
//        DelteNode(vec);
//        Findlast(nodevec[0]);
//    }
//
//    cout << cnt;
//    return 0;
//}

//노드 값 입력 순서에 상관없는 경우로 푼 코드
//dfs 방법,  풀이 코드 참고용
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
    //자식이 없으면 리프 노드
    if (0 == tree[cur].size())
    {
        answer++;
        return;
    }

    //자식이 하나인데 지워야 할 노드라면 현재 노드가 리프 노드가 됨
    if (1 == tree[cur].size() && nodeToRemove == tree[cur][0])
    {
        answer++;
        return;
    }

    for (int i = 0; tree[cur].size() > i; i++)
    {
        auto next = tree[cur][i];
        //다음 노드를 방문하지 않았으면서 지워야 할 노드가 아닐 때 방문
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

        //입력이 -1이라면 루트 노드
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
