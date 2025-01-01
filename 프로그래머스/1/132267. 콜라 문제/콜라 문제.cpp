#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n>=a)
    {
        int newget = (n/a)*b; 
        answer += newget;
        n %=a;
        n += newget;
    }
    
    return answer;
}