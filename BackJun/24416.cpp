#include <iostream>
#include<vector>
using namespace std;

int N;
int fibcnt = 0;
int fibonaccicnt = 1;
vector<int> f;

int fib(int n) 
{
    if (n == 1 || n == 2)
    {
        fibcnt++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    for (int i = 3; i<n; ++i)
    {
        fibonaccicnt++;
        f.push_back(f[i - 1] + f[i - 2]);
    }
        return f[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   
    f.push_back(0);
    f.push_back(1);
    f.push_back(f[0]+f[1]);

    cin >> N;

    fib(N);
    cout << fibcnt << " ";

    fibonacci(N);
    cout << fibonaccicnt;



    return 0;
 }