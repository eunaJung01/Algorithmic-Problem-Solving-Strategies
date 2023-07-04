//
// Created by euna on 2023/07/03.
//

#include <iostream>

using namespace std;

int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += i;
    }
    return result;
}

int recursiveSum(int n) {
    if (n == 1) {
        return 1; // 더 이상 쪼개지지 않는 경우
    }
    return n + recursiveSum(n - 1); // 재귀
}

int main() {
    cout << sum(5) << '\n';
    cout << recursiveSum(5) << '\n';
}
