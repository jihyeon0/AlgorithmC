#include <iostream>
#include<vector>
#include <math.h>
using namespace std;

// ���� ���� ������ �� : ó���� ������ N���� 1�� ���� => ���� ���� �� ������ ������ �����ؾ���
//�Ÿ�,�̵�Ƚ��,������ ���̿� ��Ģ

/*
�Ÿ�  ���  �̵�Ƚ��
 1      1       1
 2     11       2
 3     111      3
 4     121      3
 5     1211     4
 6     1221     4
 7     12211    5
 8     12221    5
 9     12321    5
 10    123211   6
*/

int X, Y, T;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> X >> Y;
        int cnt{ 0 };

        if (sqrt(Y - X) <= round(sqrt(Y - X)))
        {
            cout << 2 * round(sqrt(Y - X)) - 1 << '\n';
        }
        else
        {
            cout << 2 * round(sqrt(Y - X)) << '\n';
        }

    }
    

    return 0;
}