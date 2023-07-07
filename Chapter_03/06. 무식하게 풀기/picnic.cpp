//
// Created by euna on 2023/07/07.
//

#include <iostream>
#include <vector>

using namespace std;

int C; // 테스트 케이스의 수
int n; // 학생의 수
int m; // 친구 쌍의 수
bool areFriends[10][10]; // 친구 유무
vector<bool> hasPair; // 짝 유무

int countPairings();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C;
    while (C--) {
        memset(areFriends, 0, sizeof(areFriends));

        cin >> n >> m;
        hasPair = vector<bool>(n, false);

        int a, b; // 친구 쌍
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            areFriends[a][b] = areFriends[b][a] = true;
        }

        cout << countPairings() << endl;
    }
}

int countPairings() {
    // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
    int firstFree = -1;
    for (int i = 0; i < n; ++i) {
        if (!hasPair[i]) {
            firstFree = i;
            break;
        }
    }

    // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
    if (firstFree == -1) {
        return 1;
    }

    int cnt = 0;
    for (int i = firstFree + 1; i < n; ++i) {
        if (areFriends[firstFree][i] && !hasPair[i]) {
            hasPair[firstFree] = hasPair[i] = true;
            cnt += countPairings();
            hasPair[firstFree] = hasPair[i] = false;
        }
    }
    return cnt;
}
