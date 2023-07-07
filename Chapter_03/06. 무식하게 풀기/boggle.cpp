//
// Created by euna on 2023/07/05.
//

#include <iostream>

using namespace std;

const int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

int C = 0; // 테스트 케이스의 수
int N = 0; // 단어의 수
char board[5][5];

bool hasLetter(int y, int x, const string &word) {
    // 기저 사례 1: 시작 위치가 범위 밖이면 무조건 실패한다.
    if (y > 5 || x > 5) {
        return false;
    }

    // 기저 사례 2: 첫 글자가 일치하지 않으면 실패한다.
    if (board[y][x] != word[0]) {
        return false;
    }

    // 기저 사례 3: 단어 길이가 1이면 성공한다.
    if (word.size() == 1) {
        return true;
    }

    // 인접한 8 칸을 검사한다.
    for (int direction = 0; direction < 8; ++direction) {
        int ny = y + dy[direction];
        int nx = x + dx[direction];
        // 다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지는 확인할 필요가 없다.
        if (hasLetter(ny, nx, word.substr(1))) {
            return true;
        }
    }
    return false;
}

bool hasWord(const string &word) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (hasLetter(i, j, word)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C;
    while (C--) {
        // board : 0으로 초기화
        memset(board, 0, sizeof(board));

        for (int i = 0; i < 5; ++i) {
            cin >> board[i];
        }

        cin >> N;
        while (N--) {
            string word;
            cin >> word;
            if (hasWord(word)) {
                cout << word << " " << "YES" << endl;
            } else {
                cout << word << " " << "NO" << endl;
            }
        }
    }
}
