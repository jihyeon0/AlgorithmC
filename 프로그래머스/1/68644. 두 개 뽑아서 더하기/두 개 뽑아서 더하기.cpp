#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> arr;
    
    for(int i =0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            arr.push_back(numbers[i] +numbers[j]);
        }
    }
    
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++)
    {
        if(i+1 <arr.size() && arr[i] == arr[i+1])
            continue;
        answer.push_back(arr[i]);
    }
    return answer;
}