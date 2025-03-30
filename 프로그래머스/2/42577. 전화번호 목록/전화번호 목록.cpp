#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i) {
        const string& current = phone_book[i];
        const string& next = phone_book[i + 1];

        // 접두어인지 검사
        if (next.find(current) == 0) {
            return false;
        }
    }
    return true;
}