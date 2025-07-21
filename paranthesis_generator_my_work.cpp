#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    bool x[2*n]; // fixed-size buffer for safety (max n=20)
    int m = 1 << (2 * n); // 2^(2n)

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < 2 * n; i++) {
            x[i] = (k >> i) & 1; 
        }

        bool valid = true;
        int open = 0, close = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (x[i] == 0)
                open++;
            else
                close++;
            
            if (close > open) {
                valid = false;
                break;
            }
        }

        if (valid && open == close) {
            for (int i = 0; i < 2 * n; i++) {
                cout << (x[i] == 0 ? "(" : ")");
            }
            cout << endl;
        }
    }

    return 0;
}