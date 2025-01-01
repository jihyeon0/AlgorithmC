#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> days = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    vector<int> lastdays = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total =0;
    int start = 5;
    for(int i=0; i<a-1; i++)
    {
        total += lastdays[i];
    }
    total += b;
    answer = days[(total%7-1+start)%7];
    
    return answer;
}