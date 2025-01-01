#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int j=0;
    int k=0;
    answer = "Yes";
    for(int i=0; i<goal.size(); i++)
    {
       if(j < cards1.size() && cards1[j] == goal[i])
        {
            j++;
           continue;
        }
       if(k < cards2.size() && cards2[k] == goal[i])
        {
            k++;
            continue;
        }
          answer = "No";
          break;
    }
    return answer;
}