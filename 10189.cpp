#include <iostream>
#include <string.h>

using namespace std;

char arr[100][100];

void tryInc(int x, int y, int max_x, int max_y) {
    if (x < 0 || x >= max_x || y < 0 || y >= max_y) {
        return;
    }

    if (arr[x][y] == '*') {
        return;
    }

    arr[x][y] += 1;
}

int main() {
    int n, m;

    int field = 1;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        if (field != 1) {
            cout << endl;
        }

        cout << "Field #" << field ++ << ":" << endl;
        memset(arr, '0', 10000);
        int i = 0, j = 0;

        char c;

        do {
            cin >> c;

            if (c == '*') {
                arr[i][j] = '*';

                tryInc(i - 1, j - 1, n, m);
                tryInc(i - 1, j, n, m);
                tryInc(i - 1, j + 1, n, m);

                tryInc(i, j - 1, n, m);
                tryInc(i, j + 1, n, m);

                tryInc(i + 1, j - 1, n, m);
                tryInc(i + 1, j, n, m);
                tryInc(i + 1, j + 1, n, m);
            }

            j++;
            if (j == m) {
                i++;
                j = 0;
            }

        } while(i < n && j < m);

        for (int p = 0; p < n; p++) {
            for (int q = 0; q < m; q++) {
                cout << arr[p][q];
            }
            cout << endl;
        }
    }
}