#include <iostream>
#include <map>
using namespace std;

// bool arr[10001] 했을 때 오버플로우 발생 -> 9999라고 하면 9999 +9+9+9+9 =10,035이기 때문에
// 마찬가지로 while의 탈출조건을 n + num1 + num2 + num3 + num4 + num5 > 10000로 잡는 것도 안됨
// 이유는 n이 하나씩 커지면서 10000까지 검사하는 것이므로
// bool arr[100001] 하면 출력 초과
// 그래서 map에 담음 
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