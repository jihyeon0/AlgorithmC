#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int N{ 0 };
	int M{ 0 };
	cin >> N;

	list<int> num;

	for (int i = 0; i < N; ++i)
	{
		cin >> M;
		num.push_back(M);
	}

	num.sort(); //vector�� sort() �μ��� �ٸ�

	for(const auto& i : num)
	{
		cout << i << '\n'; // endl; ���� �ð��ʰ�
	}

	return 0;
}