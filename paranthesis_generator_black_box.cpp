#include <iostream>
using namespace std;

void generateParentheses(int n, string current, int open, int close) {
    if (current.length() == 2 * n) {
        cout << current << endl;
        return;
    }
    if (open < n) {
        generateParentheses(n, current + "(", open + 1, close);
    }
    if (close < open) {
        generateParentheses(n, current + ")", open, close + 1);
    }
}

int main() {
    int n; 
    cin >> n; // Read the number of pairs of parentheses
    generateParentheses(n, "", 0, 0); // Start generating parentheses
    return 0;
}