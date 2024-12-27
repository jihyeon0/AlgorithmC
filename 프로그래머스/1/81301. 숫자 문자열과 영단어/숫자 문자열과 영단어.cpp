#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> numbers = {"zero", "one", "two","three", "four", "five", "six", "seven", "eight", "nine"};
    int answer = 0;
    string str;
    string snum;
    
    for(int i=0; i<s.length(); i++)
    {
        if(islower(s[i]))  
        {
            str += s[i];
            for(int j=0; j<numbers.size(); j++)
            {
                if(str==numbers[j])
                {
                    snum += to_string(j);
                    str = "";
                    break;
                }
            }
        }
        else
        {
            snum += s[i];
        }
    }
    answer = stoi(snum);
    return answer;
}