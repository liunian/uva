#include <iostream>
using namespace std;

int arr[1000001];

int getLoopCount(int i) {
    if (arr[i]) {
        return arr[i];
    }

    int c = 1;
    int inx = i;

    while (i != 1) {
        i = i & 1 ? 3 * i + 1 : i / 2;
        c++;
    }
    arr[inx] = c;

    return c;
}

int getMaxLoopCount(int from, int to) {
    if (from > to) {
        int swp = from;
        from = to;
        to = swp;
    }

    int count = 1;
    do {
        int c = getLoopCount(from);
        if (c > count) {
            count = c;
        }
    } while (from++ < to);

    return count;
}

int main() {

    int i, j;
    while (cin >> i >> j) {
        cout << i << ' ' << j << ' ';

        cout << getMaxLoopCount(i, j) << endl;
    }
}