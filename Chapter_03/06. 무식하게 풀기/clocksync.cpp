//
// Created by euna on 2023/07/09.
//

#include <iostream>
#include <vector>

using namespace std;

#define SWITCH_NUM 10 // 스위치의 개수
#define CLOCK_NUM 16 // 시계의 개수
#define INF 9999

// LINKED[i][j] = 1 : i번 스위치와 j번 시계가 연결되어 있다.
// LINKED[i][j] = 0 : i번 스위치와 j번 시계가 연결되어 있지 않다.
const int LINKED[SWITCH_NUM][CLOCK_NUM] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

vector<int> clocks(CLOCK_NUM); // 현재 시계들의 상태 (가리키고 있는 방향)

bool isAligned() {
    for (int i = 0; i < CLOCK_NUM; ++i) {
        if (clocks[i] != 0) {
            return false;
        }
    }
    return true;
}

void push(int switchId) {
    for (int clockId = 0; clockId < CLOCK_NUM; ++clockId) {
        if (LINKED[switchId][clockId] == 1) {
            clocks[clockId] += 3;
            clocks[clockId] %= 12;
        }
    }
}

int solve(int switchId) {
    // 모든 시계가 12시를 가리키고 있는지 확인한다.
    if (switchId == SWITCH_NUM) {
        return isAligned() ? 0 : INF;
    }

    // switchID번 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
    int result = INF;
    for (int cnt = 0; cnt < 4; ++cnt) {
        result = min(result, cnt + solve(switchId + 1));
        push(switchId); // switchId번 스위치를 누른다.
    }

    // push(switchId)가 4번 호출되었기 때문에 clocks는 원래와 같은 상태가 된다.
    return result;
}

int main() {
    int C; // 테스트 케이스의 개수
    cin >> C;

    while (C--) {
        int direction;
        for (int clockId = 0; clockId < CLOCK_NUM; ++clockId) {
            cin >> direction;
            clocks[clockId] = direction % 12;
        }

        int result = solve(0);
        if (result == INF) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }
}
