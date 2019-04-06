#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

#define MAXN 1000002
int prime[100002];
bool flag[MAXN];
int prime_cnt = 0;

void count_prime() {
    for (int i = 0; i < MAXN; ++i) {
        flag[i] = true;
    }
    int j = 2;
    for (int i = 2; i < MAXN; ++i) {
        if (flag[i]) {
            for (j = 2; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    break;
                }
            }
            if (j == (int)sqrt(i) + 1) {
                prime[prime_cnt++] = i;
            }
            for (int k = 2; k < MAXN / i; ++k) {
                flag[i * k] = false;
            }
        }
    }
}

int main() {
    ofstream out_file;
    count_prime();
    out_file.open("prime.data");
    out_file << "prime number\t" << prime_cnt << endl;
    cout << prime_cnt << endl;
    for (int i = 0; i < prime_cnt; ++i) {
        cout << prime[i] << "\t";
        out_file << prime[i] << "\t";
        if ((i + 1) % 20 == 0) {
            cout << endl;
            out_file << endl;
        }
    }
    out_file.close();
    return 0;
}
