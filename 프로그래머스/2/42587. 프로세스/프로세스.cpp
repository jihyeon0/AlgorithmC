#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    while (!q.empty()) {
        int current_priority = q.front().first;
        int current_index = q.front().second;
        q.pop();

        bool has_higher = false;
        queue<pair<int, int>> temp_q = q;
        while (!temp_q.empty()) {
            if (temp_q.front().first > current_priority) {
                has_higher = true;
                break;
            }
            temp_q.pop();
        }

        if (has_higher) {
            q.push({current_priority, current_index});
        } else {
            answer++;
            if (current_index == location) {
                return answer;
            }
        }
    }

    return answer;
}