#include <iostream>
#include <vector>
#include<queue>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;

int arr[100001] = { 1, };
bool visited[100001] = { false, };
queue<pair<int,int>> discovered;
int cnt{ 0 };
int N, K; //����, ����

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    //�Է�
    cin >> N >> K;

    //Ž�� X-1 , X+1 , 2*X
    
    discovered.push(make_pair(N,0));
    visited[N] = true;

    while (!discovered.empty())
    {
        
        pair<int,int>  start = discovered.front();
        discovered.pop();

        if (start.first == K)
        {
            cnt = start.second;
            break;
        }
        //ť�� ����ְ� Ž�� ����
        
        if (start.first - 1 >= 0 && visited[start.first - 1] == false)
        {
            visited[start.first] = true;
            discovered.push(make_pair(start.first - 1,start.second + 1));
        }
        if (start.first + 1 <= 100000 && visited[start.first + 1] == false)
        {
            discovered.push(make_pair(start.first + 1, start.second +1));
        }
        if (start.first * 2 <= 100000 && visited[start.first * 2] == false)
        {
            discovered.push(make_pair(start.first * 2, start.second + 1));
        }
    }
    
    cout << cnt;

    return 0;
}