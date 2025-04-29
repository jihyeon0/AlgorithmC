#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int answer = 0;

    if (a == b && b == c)
    {
        answer = 10000 + a * 1000;
    }
    else if (a == b || a == c)
    {
        answer = 1000 + a * 100;
    }
    else if (b == c)
    {
        answer = 1000 + b * 100;
    }
    else
    {
        int imax = max({ a, b, c });
        answer = imax * 100;
    }
    cout << answer << '\n';
    return 0;
}