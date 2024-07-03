#include <iostream>
#include <map>
using namespace std;

// bool arr[10001] ���� �� �����÷ο� �߻� -> 9999��� �ϸ� 9999 +9+9+9+9 =10,035�̱� ������
// ���������� while�� Ż�������� n + num1 + num2 + num3 + num4 + num5 > 10000�� ��� �͵� �ȵ�
// ������ n�� �ϳ��� Ŀ���鼭 10000���� �˻��ϴ� ���̹Ƿ�
// bool arr[100001] �ϸ� ��� �ʰ�
// �׷��� map�� ���� 
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n{ 1 };
    map<int, bool> arr;
    

    int num1, num2, num3, num4, num5;

    while (n< 10000)
    {
        arr.insert({ n,false });

       num1 = (n % 100000) / 10000;
       num2 = (n % 10000) / 1000;
       num3 = (n % 1000) / 100;
       num4 = (n % 100) / 10;
       num5 = n % 10;

       arr.insert({ n + num1 + num2 + num3 + num4 + num5 ,true });
           ++n;
    }

    for (auto& find : arr)
    {
        if (find.second == false)
        {
            cout << find.first << '\n';
        }
    }
    return 0;
}