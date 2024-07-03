#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;
int oper[4];

int max_num = INT_MIN;
int min_num = INT_MAX;

void recur(int cur, int total)
{
    if (cur == n)
    {
        max_num = max(max_num, total);
        min_num = min(min_num, total);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (!oper[i]) continue;

        oper[i]--;
        if (i == 0)
        {
            recur(cur + 1, total + vec[cur]); 
            // main���� ���� (1, vec[0]) ȣ�� -> ��� �ι��� ȣ�� recur(1 + 1, vec[0] + vec[1])...  
            // 
            // recursion(now+1, vec[now] + vec[now + 1]); ��  Ʋ�� ����
            //����ó�� ���� (0, 0) ȣ�� -> ��� �ι��� ȣ��  recur(0 + 1, vec[0] + vec[1])-> ��� ������ ȣ��  recur(1 + 1, vec[1] + vec[2]) => �������� ����
        }
        else if (i == 1)
        {
            recur(cur + 1, total - vec[cur]);
        }
        else if (i == 2)
        {
            recur(cur + 1, total * vec[cur]);
        }
        else if (i == 3)
        {
            recur(cur + 1, total / vec[cur]);
        }
        oper[i]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    for (int i = 0; i < 4; i++)    cin >> oper[i];

    recur(1, vec[0]);
    cout << max_num << '\n' << min_num;

    return 0;
}