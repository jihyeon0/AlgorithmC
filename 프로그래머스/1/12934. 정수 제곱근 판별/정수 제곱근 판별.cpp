#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
long long answer = 0;
long long x = 1;
    while(x * x <= n)
    {
        if(x * x == n) 
        {
            answer = (x+1)*(x+1);
            return answer;
        }
        x++;
    }
    answer = -1;
    return answer;
}