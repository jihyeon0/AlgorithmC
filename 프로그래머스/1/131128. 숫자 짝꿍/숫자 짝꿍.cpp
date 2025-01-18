#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";  //짝꿍이 존재하지 않으면, 짝꿍은 - 1 , 짝꿍이 0으로만 구성되어 있다면, 짝꿍은 0
    vector<int> vx(10, 0);
    vector<int> vy(10, 0);
    vector<int> canuse(10, 0);
    int cnt = 0;

    //안에 든 0~9까지 숫자의 갯수를 셈 

    for ( auto x : X)
    {
        int ix = x - '0';
        vx[ix]++;
    }
    for (auto y : Y)
    {
        int iy = y - '0';
        vy[iy]++;
    }

    //사용할 수 있는 개수를 정함 => vx, vy 중 적은 쪽에 맞춤
    for (int i = 0; i < 10; i++)
    {
        if (vx[i] == 0 || vy[i] == 0)
        { 
            cnt++;  //둘중 하나라도 0이면 사용못함
            continue;
        }

        if (vx[i] < vy[i]) //vx[i]가 더 적음
            canuse[i] = vx[i];
        else
            canuse[i] = vy[i];
    }
    if (cnt == 10) //짝궁이 없는 경우
    {
        string s = to_string(-1);
        return s;
    }
    cnt = 0;

    for (int i = 9; i >= 0; i--) //거꾸로 세면서 큰 숫자 만들기
    {
        if (canuse[i] == 0) 
            continue;

        if (i == 0 && cnt == 0) //끝까지 올 동안 cnt가 안 늘었으면 다른 숫자 사용x
        {
            string s = to_string(0);
            return s;
        }

        while (canuse[i] > 0)
        {
            cnt++;
            string s = to_string(i);
            answer += s;
            canuse[i]--;
        }
    }

    //answer 에 0만 있는 경우

    return answer;
}