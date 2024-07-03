#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 //이분탐색 안에 완전탐색했으므로 ->O(NlogN)
int N; //집의 개수
int C; //공유기 개수
vector<int> v;
int pos, _max;
int _left, _mid, _right;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N>>C;
	v.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> pos;
		v.push_back(pos);
	}
	//정렬
	sort (v.begin(), v.end());

	//집 단위로 설치
	_left = 1; // 거리!!, pos값이 아님!! 존나 혼남
	_right = v[N - 1] - v[0]; 
	_mid = (_left + _right) / 2; //중간 거리 
	//mid거리 단위로 잘랐을때 만족하는 집
	
	
	//설치 가능 "거리"를 이분탐색하라
	
	while (_left <= _right)
	{
		int cnt = 1; // v[0]에 무조건 설치, 설치한 공유기 개수
		int visited = 0;
		_mid = (_left + _right) / 2;
		for (int i = 1; i < N; ++i)
		{
			if (v[i] - v[visited] >= _mid) // 검사 위치 - 설치된 위치 >= 설치간격
			{
				cnt += 1; //설치하고
				visited = i; // 설치된 위치를 갱신
			}
		}
		if (cnt >= C) // 설치 개수를 만족했다면 더 긴 거리로도 가능한지
		{
			_max = max(_max,_mid);
			_left = _mid + 1;
		}
		else // 설치개수를 만족하지 못했다면
		{
			_right = _mid - 1;
		}
	}
	//가장 많은 수로 가장 먼 거리 구하기
	
	cout << _max;
	return 0;
}