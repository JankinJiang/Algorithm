#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

// 二分查找
//返回该元素在数组中的位置，找不到返回-1
int LineFindval(int num[], int len, int v) {
    for (int i = 0; i < len; i++) {
        if (num[i] == v) {
            return i + 1;
        }
    }
    return -1;
}

//返回数组中第i个位置的值，i越界返回-1
int Findp(int num[], int len, int p) {
    if (p <= len && p > 0) {
        return num[p - 1];
    }
    return -1;
}

int BinaryFindval(int num[], int left, int right, int v) {
    int mid = (left + right) / 2;
    int key = num[mid];
    if (key == v) {
        return mid + 1;
    }
    if (left == right) {
        return -1;
    } else if (key > v) {
        return BinaryFindval(num, left, mid - 1, v);
    } else if (key < v) {
        return BinaryFindval(num, mid + 1, right, v);
    }
    return -1; //是否可以取消？
}

int main(int argc, char const *argv[]) {
    int num[15];
    for (int i = 0; i < 15; i++) {
        num[i] = rand() % 100;
    }
    for (int i = 0; i < 15; i++) {
        cout << num[i] << "\t";
    }
    cout << endl;

    sort(num, num + 15);
    cout << BinaryFindval(num, 0, 14, 115) << endl;

    system("pause");
    return 0;
}
