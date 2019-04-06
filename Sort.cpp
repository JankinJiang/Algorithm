#include <iostream>
using namespace std;

void BubbleSort(int num[], int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = len - 1; j > i; j--){
            if(num[j-1] > num[j]){
                num[j] = num[j] ^ num[j - 1];
                num[j - 1] = num[j] ^ num[j - 1];
                num[j] = num[j] ^ num[j - 1];
            }
        }
    }
}

void SelectionSort(int num[], int len){
    int k;
    int min;
    for (int i = 0; i < len - 1; i++){
        min = 0x3f3f3f3f;
        for (int j = i; j < len; j++){
            if(min > num[j]){
                min = num[j];
                k = j;
            }
        }
        int t = num[k];
        num[k] = num[i];
        num[i] = t;
        // num[k] = num[k] ^ num[i];
        // num[i] = num[k] ^ num[i];
        // num[k] = num[k] ^ num[i];
    }
}

void InsertionSort(int num[], int len){
    int temp;
    for (int i = 1; i < len; i++){
        temp = num[i];
        for (int j = i-1; j >= 0; j--){
            if(num[j] > temp){
                num[j + 1] = num[j];
            }
            else{
                num[j + 1] = temp;
                break;
            }
        }
        // temp = num[i];
        // int j = i - 1;
        // while (j >= 0 && num[j] > temp){
        //     num[j + 1] = num[j];
        //     j--;
        // }
        // num[j + 1] = temp;
    }
}

void ShellSort(int num[], int len){
    for (int r = len / 2; r >= 1; r/=2){
        for (int i = r; i < len; i++){
            int temp = num[i];
            int j = i - r;
            while (j >= 0 && num[j] > temp){
                num[j + r] = num[j];
                j -= r;
            }
            num[j + r] = temp;
        }
    }
}

void QuickSort1(int num[], int left, int right){
    int i, j, key;
    if(left < right){
        i = left;
        j = right;
        key = num[left];
        while(i<j){
            while (i < j && num[j] > key)
                j--;
            if (i < j){
                num[i] = num[j];
                i++;
            }
            while (i < j && num[i] < key)
                i++;
            if (i < j){
                num[j] = num[i];
                j--;
            }
        }
        num[i] = key;
        QuickSort1(num, left, i - 1);
        QuickSort1(num, i + 1, right);
    }
}

void QuickSort2(int num[], int left, int right){
    int i, j, key;
    if(left < right){
        i = left;
        j = right;
        key = num[(left + right) / 2];
        while (i < j){
            while (i < j && num[i] < key)
                i++;
            while (i < j && num[j] > key)
                j--;
            if (i < j){
                int t = num[i];
                num[i] = num[j];
                num[j] = t;
                i++;
                j--;
            }
        }
        if(i==j)
            i++;
        QuickSort2(num, left, i - 1);
        QuickSort2(num, i + 1, right);
    }
}

void HeapSort(int num[], int len){
    int j, k;
    int t;
    for (int i = len / 2 - 1; i >= 0; i--){
        while (2 * i + 1 < len){
            j = 2 * i + 1;
            if (j + 1 < len){
                if (num[j] < num[j + 1])
                    j++;
            }
            if (num[i] < num[j]){
                t = num[i];
                num[i] = num[j];
                num[j] = t;
                i = j;
            }
            else
                break;
        }
    }

    for (int i = len - 1; i > 0; i--){
        t = num[0];
        num[0] = num[i];
        num[i] = t;
        k = 0;
        while (2 * k + 1 < i){
            j = 2 * k + 1;
            if (j + 1 < i){
                if (num[j] < num[j + 1])
                    j++;    
            }
            if (num[k] < num[j]){
                t = num[k];
                num[k] = num[j];
                num[j] = t;
                k = j;
            }
            else
                break;
        }
    }
}

void MergeSort(int num[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        MergeSort(num, left, mid);
        MergeSort(num, mid + 1, right);
        int tmp[right - left + 1];
        for (int i = left; i <= right; i++)
            tmp[i - left] = num[i];
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++)
        {
            if (i > mid)
            {
                num[k] = tmp[j - left];
                j++;
            }
            else if (j > right)
            {
                num[k] = tmp[i - left];
                i++;
            }
            else if (tmp[i - left] < tmp[j - left])
            {
                num[k] = tmp[i - left];
                i++;
            }
            else
            {
                num[k] = tmp[j - left];
                j++;
            }
        }
    }    
}

int main(int argc, char const *argv[])
{
    int a[11] = {1, 3, 5, 6, 7, 3, 4, 9, 7, 4, 13};
    MergeSort(a, 0,10);
    for (int i = 0; i < 11; i++){
        cout << a[i] << "\t";
    }
    cout << endl;

    system("pause");
    return 0;
}
