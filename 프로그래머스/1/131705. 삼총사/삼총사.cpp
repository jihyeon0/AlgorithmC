#include <string>
#include <vector>

using namespace std;

 int answer = 0;
 int start, deep, sum = 0;
    
 void re(vector<int>& number, int start, int deep, int sum, int& answer)
    {
        if(deep == 3)
        {
            if(sum == 0)  answer++;
            return;
        }
     
     
        for(int i=start; i<number.size(); i++)
        {
            re(number, i+1, deep +1, sum+number[i], answer);
        }
    }

int solution(vector<int> number) {
   
   re(number, 0, 0,0,answer);
    
    return answer;
}