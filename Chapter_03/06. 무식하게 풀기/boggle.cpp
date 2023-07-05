//
// Created by euna on 2023/07/05.
//

#include <iostream>
#include <vector>

using namespace std;

const int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

int C = 0; // 테스트 케이스의 수
int N = 0; // 단어의 수
char board[5][5];

bool hasLetter(int y, int x, const string &word) {
    if (y > 5 || x > 5) {
        return false;
    }
    if (board[y][x] != word[0]) {
        return false;
    }
    if (word.size() == 1) {
        return true;
    }

    for (int direction = 0; direction < 8; ++direction) {
        int ny = y + dy[direction];
        int nx = x + dx[direction];
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
