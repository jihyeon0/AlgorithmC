#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	/*
	N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. 
	�� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.
	ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
	*/
	int N,M{ 0 };
	cin >> N;
	vector<int> num;
	for (int i = 0; i < N; ++i)
	{
		cin >> M;
		num.push_back(M);
	}
	sort(num.begin(), num.end());
	
	for (const auto& i : num)
	{
		cout << i << endl;
	}

	return 0;
}