#include <iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

//�Ӹ���Ҽ�, � �ܾ �ڿ������� �о �Ȱ��ٸ�, ���ڿ�

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //char arr[100000] = {1};
    //while (true)
    //{
    //    cin >> arr;
    //    if(48 == arr[0])
    //        return 0;
    //    bool result = true;
    //    int len = (int)strlen(arr); //null����x
    //    int back = { len-1 };
    //    for (int i = 0; i < len / 2; ++i)
    //    {
    //        
    //        if (arr[i] != arr[back])
    //        {
    //            result = false;
    //            break;
    //        }
    //        back--;
    //    }
    //    if(result)
    //        cout << "yes" << '\n';
    //    else
    //        cout << "no" << '\n';
    //}

    //string ������, reverse, buff[0] ��������
    while (true)
    {
        string num = "";
        cin >> num;

        string buff = num;
        reverse(num.begin(), num.end());

        if (buff[0] == '0')
            break;

        if (buff == num)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}