#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(int i =0; i<commands.size(); i++)
    {
        vector<int> v;
        int x = commands[i][0];
        int y = commands[i][1];
        int z = commands[i][2];
        
        for(int j = x-1; j<= y-1; j++)
        {
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[z-1]);
    }
    return answer;
}