#include <iostream>
#include<math.h>
using namespace std;

//ÆÑÅä¸®¾ó 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;

    int result = 1;

    for (int i = 1; i <= N; ++i)
    {
        result *= i;
    }

    cout << result;

    return 0;
}