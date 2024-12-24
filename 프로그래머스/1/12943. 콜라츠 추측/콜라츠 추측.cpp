#include <string>
#include <vector>

using namespace std;

int solution(int num1) {
    int answer = 0;
    long long num = num1;
    while(true)
    {
        if(num ==1) 
         return answer;
        
       if(answer > 500) 
       {
           answer = -1;
           return answer;
       }
        
        if(num %2 ==0) num /= 2;
        else
        {
             num = num * 3 + 1;
        }
        answer++;
    }
    return answer;
}