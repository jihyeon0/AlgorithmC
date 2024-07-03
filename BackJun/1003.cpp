#include <iostream>
#include<vector>
using namespace std;

// 파보나치 수열, 재귀x, 다이나믹 프로그래밍 , 규칙찾기 , cnt++ -> 시간초과

vector<pair<int, int>> v;

void fibonacci(int n) 
{
  for(int i=0; i<n; ++i)
    {
      v.push_back(make_pair(v[i].second, v[i].first +v[i].second));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
 
    cin >>T;

  

    while (T--)
    {
        v.push_back(make_pair(1, 0));
        cin >> N;
        fibonacci(N);

       cout<< v[N].first << " " << v[N].second << '\n';
       v.clear();
    }
    

    return 0;
}