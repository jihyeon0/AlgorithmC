#include <iostream>
using namespace std;

void hanoi(int N, int start, int temp, int goal)
{
    if (N == 1)
    {
        cout << start << " " << goal << '\n'; 
        return;
    }
    else
    {
        hanoi(N - 1, start, goal, temp);
        cout << start << " " << goal << '\n';
        hanoi(N - 1, temp, start, goal);
    }

}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    int start{ 1 }, temp{ 2 }, goal{ 3 };
    cin >> N;
    M = N;
    int cnt{ 1 };
    while (M--)
    {
        cnt *= 2;
    }
    cout << cnt - 1<<'\n';
    hanoi(N, start, temp, goal);

}