//
// Created by euna on 2023/07/07.
//

#include <iostream>
#include <vector>

using namespace std;

int C; // 테스트 케이스의 수
int H, W;
int board[20][20]; // H × W

const int TYPES[4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
};

void coverBoard(vector<pair<int, int> > &pos, int n) {
    for (int i = 0; i < 3; ++i) {
        int y = pos[i].first;
        int x = pos[i].second;
        board[y][x] = n;
    }
}

bool isAvailable(int type, vector<pair<int, int> > &pos, int y, int x) {
    for (int i = 0; i < 3; ++i) {
        int ny = y + TYPES[type][i][0];
        int nx = x + TYPES[type][i][1];

        if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
            return false;
        }
        if (board[ny][nx] == 1) {
            return false;
        }
        pos.push_back(make_pair(ny, nx));
    }
    return true;
}

int cover() {
    // 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
    int y = -1, x = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == 0) {
                y = i, x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    // 기저 사례: 모든 칸을 채웠으면 1을 반환한다.
    if (y == -1 && x == -1) {
        return 1;
    }

    int cnt = 0;
    for (int type = 0; type < 4; ++type) {
        vector<pair<int, int> > pos;
        // 만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출한다.
        if (isAvailable(type, pos, y, x)) {
            coverBoard(pos, 1);
            cnt += cover();
            coverBoard(pos, 0);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, 0, sizeof(board));
    char line[20]; // '#', '.'

    cin >> C;
    while (C--) {
        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            cin >> line;
            for (int j = 0; j < W; j++) {
                board[i][j] = (line[j] == '#') ? 1 : 0;
            }
        }
        cout << cover() << endl;
    }
}
