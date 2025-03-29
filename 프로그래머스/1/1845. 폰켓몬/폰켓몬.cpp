#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;

	unordered_map<int, int> m;

	for (auto& i : nums)
	{
		m[i]++;
	}
	if (m.size() > nums.size() / 2)
	{
		answer = nums.size() / 2;
	}
	else
	{
		answer = m.size();
	}



	return answer;
}