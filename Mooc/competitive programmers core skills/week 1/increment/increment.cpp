#include <iostream>
#include <vector>
#include <climits>

// int max(int a, int &b);

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    std::string str;
    cin >> str;
    int n = str.size(), idx = 0;
//    cout << n << endl;
    for (char ch: str) {
        if (ch != '9') {

            break;
        }else ++idx;

    }
    if (idx != n) {
        cout << n;
    } else cout << n + 1;
}
