#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int num=0;
    int y = x;
    while(y>0)
    {
       num += y%10;
        y/=10;
    }
    if(x%num ==0) answer = true;
    else answer = false;
    return answer;
}