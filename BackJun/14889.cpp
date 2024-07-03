#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;

int arr[20][20]; // �ɷ�ġ ���� ǥ
bool visited[20] = { false, }; //�������� �˻�
int teamA[10] = { 0, }; // ���� ������ ��ȣ ����
int teamB[10] = { 0, }; 

int _min = INT32_MAX; //�ɷ�ġ ���� �ּڰ�


void back(int cnt,//���� ������ ��� �̾Ҵ���
          int num) // ���� ��ȣ 
{
    //Ż�� ����
    if (N / 2 == cnt) //��ȣ �� �̾����� ���� �־��ش�
    {
        int Acnt = 0;
        int Bcnt = 0;
        //teamA�� �ϼ��� ���� teamA = { 0�� 3�� 5��...}
        
        //teamB �ϼ� ��Ű��
        for (int i = 0; i < N; ++i) //0~N-1���� ���鼭 teamA[i] �� �ƴϸ� teamB�� �ִ´�
        {
            if (!visited[i]) //�湮�����̾�����
            {
                teamB[Bcnt] = i;
                Bcnt += 1;
            }
            else
            {
                teamA[Acnt] = i;
                Acnt += 1;
            }
        }
        //�� ���� �ɷ�ġ ���ϱ�
        int hapA={0}, hapB = { 0 };
        for (int i = 0; i < N / 2; ++i)
        {
            for (int j = i+1; j < N / 2; ++j)
            {
                hapA += arr[teamA[i]][teamA[j]] + arr[teamA[j]][teamA[i]];
                hapB += arr[teamB[i]][teamB[j]] + arr[teamB[j]][teamB[i]];
            }
        }

        // �� ���� �ɷ�ġ ���밪 ���� �ּҰ� ����
        _min = min(_min, abs(hapA - hapB));
        return;
    }
    // ���� ��ȣ �̱�
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cnt += 1;
            back(cnt, i);
            visited[i] = false;
            cnt -= 1;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> N;

    // ǥ ä��� N��, �ε���: 0 ~ N-1 ����
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }
    
    back(0,0); // ���, ���� ��ȣ
    
    cout << _min;

    return 0;
}