
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
  
    int numer = (numer1 * denom2) + (numer2 * denom1);
    int denom = denom1 * denom2;
    int igcd = gcd(numer, denom);

    answer.push_back(numer / igcd);
    answer.push_back(denom / igcd);
    return answer;
}