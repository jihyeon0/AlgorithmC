#include <iostream>
#include<math.h>
using namespace std;

// 15439  상의 N개 , 하의 N개, 같은 색 겹치지 않는 조합
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;

    cout << N * N - N;

    return 0;
}

//24723 녹색거탑의 정상에서 바닥으로 내려오는 경우의 수 블록1개 당 2가지
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
//
//    int N;
//
//    cin >> N;
//
//    cout << pow(2, N);
//
//    return 0;
//}