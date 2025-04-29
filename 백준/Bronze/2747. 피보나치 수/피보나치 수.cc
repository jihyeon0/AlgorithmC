#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int a = 0, b = 1, answer = 1;
    for (int i = 2; i <= n; i++) {
        answer = a + b;
        a = b;
        b = answer;
    }

    cout << answer << '\n';
    return 0;
}