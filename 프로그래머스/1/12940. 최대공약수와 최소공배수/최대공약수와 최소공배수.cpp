#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a,b;
    if(n>m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    a = m; b = n;
    while(a%b != 0)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }
    answer.push_back(b);
    answer.push_back((n*m)/b);
    return answer;
}