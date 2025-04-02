#include <vector>
#include <iostream>
#include <queue>

using namespace std;


vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	queue<int>  q;

	for (int i =0; i< arr.size(); i++)
	{
		if (q.empty())
		{
			q.push(arr[i]);
			answer.push_back(arr[i]);
			continue;
		}
		if (q.front() == arr[i])
		{
			continue;
		}
		else
		{
			q.pop();
			q.push(arr[i]);
			answer.push_back(arr[i]);
		}
	}
	
	return answer;
}