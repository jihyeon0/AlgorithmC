#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    if(phone_number.length() == 4)
    {
        answer = phone_number;
        return answer;
    }
    
    for(int i=0; i<phone_number.length() -4; i++)
    {
        phone_number[i] = '*';
    }
    answer = phone_number;
    return answer;
}