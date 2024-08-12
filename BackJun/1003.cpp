#include <iostream>
#include<vector>
using namespace std;

// 파보나치 수열, 다이나믹 프로그래밍 ,메모이제이션, 규칙찾기 , cnt++ -> 시간초과
// 메모이제이션 : DP테이블에 저장, 재계산x

vector<pair<int, int>> v(41, make_pair(-1, -1));

void fibonacci(int n)
{
    //탑-다운
    { 
        if (v[n].first != -1 && v[n].second != -1) return; //재계산x

        if (n == 0) {
            v[n] = make_pair(1, 0);
        }
        else if (n == 1) {
            v[n] = make_pair(0, 1);
        }
        else
        {
            fibonacci(n - 1); //재귀
            fibonacci(n - 2); //재귀
            v[n] = make_pair(v[n - 1].first + v[n - 2].first, v[n - 1].second + v[n - 2].second);
        }
    }

    //바텀-업
    {
        v[0] = make_pair(1, 0);
        v[1] = make_pair(0, 1);
        for (int i = 2; i <= n; ++i)
        {
            v[i] = make_pair(v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second);
        }
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
        cin >> N;
        fibonacci(N);

       cout<< v[N].first << " " << v[N].second << '\n';
    }
    
    return 0;
}