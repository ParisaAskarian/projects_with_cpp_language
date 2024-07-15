#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int partition(int A[], int low, int high) 
{
    int pivot_index = low + (rand() % (high - low + 1));
    int pivot_value = A[pivot_index];

    if (pivot_index != high) {
        swap(A[pivot_index], A[high]);
    }

    int i = low;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot_value) {
            swap(A[i], A[j]);
            i++;
        }
    }

    swap(A[i], A[high]);
    return i;
}

void quick_sort_process(int A[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(A, low, high);
        quick_sort_process(A, low, pivot_index - 1);
        quick_sort_process(A, pivot_index + 1, high);
    }
}

void quick_sort(int A[], int size) {
    srand(time(NULL));
    quick_sort_process(A, 0, size - 1);
}

int main() {
    string A;
    getline(cin, A);

    istringstream iss(A);
    int num;
    int i = 0;
    int B[10000];
    while (iss >> num) {
        B[i] = num;
        i++;
    }

    quick_sort(B, i);

    for (int j = 0; j < i; j++) {
        cout << B[j] << " ";
    }

    return 0;
}