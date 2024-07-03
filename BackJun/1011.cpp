#include <iostream>
#include<vector>
#include <math.h>
using namespace std;

// 조건 보고 생각난 것 : 처음과 마지막 N값이 1로 고정 => 절반 증가 후 나머지 절반은 감소해야함
//거리,이동횟수,제곱수 사이에 규칙

/*
거리  경로  이동횟수
 1      1       1
 2     11       2
 3     111      3
 4     121      3
 5     1211     4
 6     1221     4
 7     12211    5
 8     12221    5
 9     12321    5
 10    123211   6
*/

int X, Y, T;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> X >> Y;
        int cnt{ 0 };

        if (sqrt(Y - X) <= round(sqrt(Y - X)))
        {
            cout << 2 * round(sqrt(Y - X)) - 1 << '\n';
        }
        else
        {
            cout << 2 * round(sqrt(Y - X)) << '\n';
        }

    }
    

    return 0;
}