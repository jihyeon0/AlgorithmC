#include <iostream>
using namespace std;

// 수의 숫자가 10의 12승이므로 long long
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //입력
    long long A, B, C;
    cin >> A >> B >> C;

    cout << A + B + C;
    return 0;
}