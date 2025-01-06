#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> arr(number,0);
    
    for (int i = 1; i <= number; i++) 
    {
        for (int j = i; j <= number; j += i)
        {
            arr[j-1]++;
        }
    }
    
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]>limit)
            arr[i] = power;
       answer += arr[i];
    }
    return answer;
}