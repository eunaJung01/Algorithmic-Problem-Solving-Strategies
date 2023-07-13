//
// Created by euna on 2023/07/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

vector<int> fences(50, 0);

int solve(int left, int right) {
    // 기저 사례: 판자가 하나밖에 없는 경우
    if (left == right) {
        return fences[left];
    }

    // TODO: 두 구간으로 문제를 분할한다. → 부분 문제 1, 2
    int mid = (left + right) / 2;
    int result = max(solve(left, mid), solve(mid + 1, right));

    // TODO: 부분 문제 3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    int low = mid, high = mid + 1;
    int height = min(fences[low], fences[high]);

    // [mid, mid + 1]만 포함하는 너비 2인 사각형을 고려한다.
    result = max(result, height * 2);

    // 사각형이 입력 전체를 덮을 때까지 확장해 나간다.
    while (left < low || high < right) {
        // 항상 높이가 더 높은 쪽으로 확장한다.
        if (high < right && (low == left || fences[low - 1] < fences[high + 1])) {
            height = min(height, fences[++high]);
        } else {
            height = min(height, fences[--low]);
        }
        // 확장한 후 사각형의 넓이
        result = max(result, height * (high - low + 1));
    }
    return result;
}

int main() {
    int C; // 테스트 케이스의 개수
    cin >> C;

    int N; // 판자의 수
    while (C--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> fences[i];
        }
        cout << solve(0, N - 1) << endl;
    }
}
