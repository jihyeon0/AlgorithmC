#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 소수 판별 함수
bool isPrime(int num) {
    if (num <= 1) return false;      // 1과 그 이하의 수는 소수가 아님
    if (num == 2) return true;       // 2는 소수
    if (num % 2 == 0) return false;  // 짝수는 소수가 아님

    // 3부터 sqrt(num)까지 홀수만 검사
    int sqrt_num = (int)sqrt(num);
    for(int i = 3; i <= sqrt_num; i += 2) {
        if(num % i == 0) return false; // 약수가 존재하면 소수가 아님
    }
    return true; // 약수가 없으면 소수
}

int solution(vector<int> nums) {
    int answer = 0;

    // 세 개의 수를 조합하여 검사
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                int num = nums[i] + nums[j] + nums[k];

                // 소수인지 판별
                if(isPrime(num)) {
                    answer++;
                }
            }
        }
    }

    return answer;
}