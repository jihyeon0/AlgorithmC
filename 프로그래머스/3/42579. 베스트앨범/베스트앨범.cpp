#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genreTotalPlays;
    unordered_map<string, vector<pair<int, int>>> genreToSongs;

    // 1. 장르별 총 재생 수와 곡 정보 저장
    for (int i = 0; i < genres.size(); ++i) {
        genreTotalPlays[genres[i]] += plays[i];
        genreToSongs[genres[i]].push_back({plays[i], i});
    }

    // 2. 장르를 총 재생 수 기준으로 정렬
    vector<string> sortedGenres;
    for (const auto& entry : genreTotalPlays) {
        sortedGenres.push_back(entry.first);
    }
    sort(sortedGenres.begin(), sortedGenres.end(), [&](const string& a, const string& b) {
        return genreTotalPlays[a] > genreTotalPlays[b];
    });

    // 3. 각 장르별로 재생 수 기준 정렬 후 상위 2곡 선택
    vector<int> answer;
    for (const string& genre : sortedGenres) {
        auto& songs = genreToSongs[genre];
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first > b.first; // 재생 수 내림차순
            return a.second < b.second; // 고유 번호 오름차순
        });

        for (int i = 0; i < songs.size() && i < 2; ++i) {
            answer.push_back(songs[i].second); // 고유 번호 추가
        }
    }

    return answer;
}