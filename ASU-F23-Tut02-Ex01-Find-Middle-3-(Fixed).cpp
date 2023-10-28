#include <iostream>
using namespace std;

int* test(int numbers[], int arr_length, int& new_arr_length) {
    static int result[]{ numbers[arr_length / 2 - 1], numbers[arr_length / 2], numbers[arr_length / 2 + 1] };
    new_arr_length = 3;
    return result;
}

int main() {
    int* result, i;
    int nums[] = { 1, 5, 7, 9, 11, 13 };
    int arr_length = sizeof(nums) / sizeof(nums[0]);

    cout << "Original array:" << endl;
    for (i = 0; i < arr_length; i++) {
        cout << nums[i] << " ";
    }

    int new_arr_length;
    result = test(nums, arr_length, new_arr_length);
    // arr_length = sizeof(result) / sizeof(result[0]); // Error #1
    cout << "\nNew array:" << endl;
    // for (i = 0; i <= arr_length; i++) {              // Error #2
    for (i = 0; i < new_arr_length; i++) {
        cout << *(result + i) << " ";
    }

    return 0;
}

