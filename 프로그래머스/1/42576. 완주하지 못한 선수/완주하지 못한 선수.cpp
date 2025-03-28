#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> m;

	for (auto& name : participant)
	{
		m[name]++;
	}

	for (auto& name : completion)
	{
		m[name]--;
	}


	for (auto& m_pair : m)
	{
		if (m_pair.second > 0)
		{
			answer = m_pair.first;
		}
	}

	return answer;
}