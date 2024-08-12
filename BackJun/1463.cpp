#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

// DP, 메모이제이션, 10^6보다 작거나 같은 정수 N -> 수가 큰 경우도 있으므로 바텀-업 이용 계획 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> v(N + 1,-1); // index 0은 사용x

    v[1] = 0;

    // 세가지 방법중 가장 적은 횟수를 저장
    // N == 값이자 v의 index

    for(int i=2; i<=N; ++i)
    {
        // -1의 경우
        //i ==2 일 때, -1 연산을 한 경우 -> 이미 계산한 v[1]의 횟수 + 1(-1 연산에 대한 횟수)
       // min을 이용해  v[i] 갱신

        v[i] = v[i - 1] + 1; 

        if (i % 2 == 0)
            v[i] = min(v[i], v[i / 2] + 1);
        
        if (i % 3 == 0)
            v[i] = min(v[i], v[i / 3] + 1);
     }

    cout << v[N];

    return 0;
}