#include <iostream>
using namespace std;

int* test(int numbers[], int arr_length) {
    static int result[]{ numbers[arr_length / 2 - 1], numbers[arr_length / 2], numbers[arr_length / 2 + 1] };
    return result;
}

int main() {
    int* result, i;
    int nums[] = { 1, 5, 7, 9, 11, 13 };
    int arr_length = sizeof(nums) / sizeof(nums[0]);

    cout << "Original array:" << endl;

    for (i = 0; i < arr_length; i++)
        cout << nums[i] << " ";

    result = test(nums, arr_length);
    cout << "\nNew array:" << endl;
    arr_length = sizeof(result) / sizeof(result[0]);
    for (i = 0; i <= arr_length; i++) {
        cout << *(result + i) << " ";
    }

    return 0;
}

