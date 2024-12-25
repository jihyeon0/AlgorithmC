#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    long long min = 9999999999;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    
    for(int i =0; i<arr.size(); i++)
    {
        if(arr[i] == min)
        {
            arr[i] = -1;
            continue;
        }
          answer.push_back(arr[i]);
    }
    
    return answer;
}