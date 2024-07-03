#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// vector에 노드객체 담아서 사용
// 트리 전위, 중위, 후위 구현, 재귀사용
// char형 알파벳을 int로 변환하여 임의접근 사용

struct Node
{
	char left;
	char right;
};

int N;
vector<Node>v(26);

//방문체크
void front(int start) // 부왼오 ABDCEFG
{
	int vecindex = start - 65;

	cout << (char)start; // 부모 출력

	if (v[vecindex].left != '.') //왼쪽자식이있으면 왼쪽
	{
		int next = (int)v[vecindex].left;
		front(next);
	}
	if (v[vecindex].right != '.') //오른쪽자식이있으면 왼쪽
	{
		int right = (int)v[vecindex].right;
		front(right);
	}
}

void mid(int start) // 왼부오 DBAECFG
{
	//왼쪽자식탐색
	// 재귀 -> 왼쪽 자식 없다면 출력하고 리턴
	//돌아와서 출력
	//오른자식 탐색
	//있다면 왼자식 탐색

	int vecindex = start - 65;
	
	if (v[vecindex].left != '.') //왼쪽자식이있으면 왼쪽
	{
		int next = (int)v[vecindex].left;
		mid(next);
	}
	// 더이상 왼쪽 자식이 없을 때 빠져나와서 부모 출력
	cout << (char)start;

	if (v[vecindex].right != '.') //오른자식이있다면
	{
		int next = (int)v[vecindex].right;
		mid(next); // 오른자식의 왼쪽부터 탐색
	}
}

void back(int start) // 왼오부 DBEGFCA
{
	int vecindex = start - 65;

	if (v[vecindex].left != '.') //왼쪽자식이있으면 왼쪽
	{
		int next = (int)v[vecindex].left;
		back(next);
	}

	if (v[vecindex].right != '.') //오른자식이있다면
	{
		int next = (int)v[vecindex].right;
		back(next); // 오른자식의 왼쪽부터 탐색
	}

	// 더이상 왼쪽 자식이 없을 때 빠져나와서 부모 출력
	cout << (char)start;

}


int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	char _value, _left, _right;

	for (int i = 0; i < N; i++)
	{
		cin >> _value >> _left >> _right;
		v[(int)_value - 65].left = _left;
		v[(int)_value - 65].right = _right;
	}
	
	front((int)'A'); 
	cout << '\n';
	mid((int)'A');
	cout << '\n';
	back((int)'A');

	return 0;
}