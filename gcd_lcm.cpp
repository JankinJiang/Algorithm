#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

// int gcd(int a, int b) {
//     if (a == b) {
//         return 1;
//     } else {
//         while (a != 0 && b != 0) {
//             if (a / b) {
//                 a %= b;
//             } else if (b / a) {
//                 b %= a;
//             }
//         }
//         if (a) {
//             return a;
//         } else {
//             return b;
//         }
//     }
// }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    ios::sync_with_stdio(false);
    int m, n;
    int ans = 1;
    long long int abcd;
    abcd = LONG_LONG_MAX;
    cout << abcd << endl;
    while (cin >> m >> n) {
        // ans = m * n / gcd(m, n);

        cout << gcd(m, n) << endl;
    }
    cout << ans << endl;
    return 0;
}