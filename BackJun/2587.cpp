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
	�ټ� ���� �ڿ����� �־��� �� �̵��� ��հ� �߾Ӱ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	ù° �ٺ��� �ټ� ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����. �־����� �ڿ����� 100 ���� ���� 10�� ����̴�.
	ù° �ٿ��� ����� ����ϰ�, ��° �ٿ��� �߾Ӱ��� ����Ѵ�. ��հ� �߾Ӱ��� ��� �ڿ����̴�.
	*/
	int N{ 0 }; 
	int M{ 0 };
	vector<int> num;
	for (int i = 0; i < 5; ++i)
	{
		cin >> M;
		num.push_back(M);
	}
	sort(num.begin(), num.end());

	for (const auto& i : num)
	{
		N += i;
	}
	cout << N / 5 << endl;
	cout << num.at(5/2) << endl;
	return 0;
}