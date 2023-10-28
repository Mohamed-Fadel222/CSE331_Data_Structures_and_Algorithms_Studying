#include <iostream>
using namespace std;

int* test(int numbers[], int arr_length, int& new_arr_length) {
    static int result[100];
    int counter = 0;
    for (int i = 0; i < arr_length; i++) {
        if (numbers[i] % 2 == 0) {
            result[counter++] = numbers[i];
        }
    }
    new_arr_length = counter;
    return result;
}

int main() {
    int* result1, * result2; // Note how to define more than one pointer in the same declaration
    int nums1[] = { 1, 2, 4, 5, 7, 9, 11, 12, 13 }; // Expected output: 2, 4, 12
    int nums2[] = { 1, 3, 5, 6, 8, 9, 10, 12, 13 }; // Expected output: 6, 8, 10, 12
    int arr_length1 = sizeof(nums1) / sizeof(nums1[0]);
    int arr_length2 = sizeof(nums2) / sizeof(nums2[0]);
    int new_arr_length1;
    int new_arr_length2;
    result1 = test(nums1, arr_length1, new_arr_length1);
    result2 = test(nums2, arr_length2, new_arr_length2);
    for (int i = 0; i < new_arr_length1; i++) cout << result1[i] << " ";
    // Where did result1 go???
    cout << endl;
    for (int i = 0; i < new_arr_length2; i++) cout << result2[i] << " ";
    return 0;
}

