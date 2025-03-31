#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> m;

	for (auto& c : clothes)
	{
		string type = c[1];
		m[type]++;
	}

	for (auto& p : m)
	{
		answer *= (p.second + 1);
	}

	return answer -1;
}