//
// Created by euna on 2023/07/10.
//

#include <iostream>
#include <string>

using namespace std;

string picture;

string reverse(string::iterator &it) {
    char head = *it;
    ++it;

    if (head == 'b' || head == 'w') {
        return string(1, head);
    }
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    // 각각 위와 아래의 조각들의 위치를 바꾼다.
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    int C;
    cin >> C;

    while (C--) {
        cin >> picture;
        string::iterator it = picture.begin();
        cout << reverse(it) << endl;
    }
}
