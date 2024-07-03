#include <iostream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //ют╥б
    int A, B;
    cin >> A >> B;
    if (A > B)
        cout << ">";
    else if (A < B)
        cout << "<";
    else if (A == B)
        cout << "==";

    return 0;
}