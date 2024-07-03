#include <iostream>
#include<math.h>
using namespace std;

//이항계수  nCk =  n!/(n-k)k!
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N,K;

    cin >> N>>K;

    int result = 1;
    int result2 = 1;
    int result3 = 1;

    for (int i = 1; i <= N; ++i)
    {
        result *= i;
    }
    for (int i = 1; i <= K; ++i)
    {
        result2 *= i;
    }
    for (int i = 1; i <= N-K; ++i)
    {
        result3 *= i;
    }
    cout << result / (result3 *result2);

    return 0;
}