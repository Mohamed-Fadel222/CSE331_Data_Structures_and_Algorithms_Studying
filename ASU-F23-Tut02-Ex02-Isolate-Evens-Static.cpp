#include <iostream>
using namespace std;

int* test(int numbers[], int arr_length, int& new_arr_length) {
    static int result[100]; // What if we have less than 100? More? Also, we're still using static! Bad!
    int counter = 0;
    for (int i = 0; i < arr_length; i++) {
        if (numbers[i] % 2 == 0) {
            result[counter++] = numbers[i]; // Remember postfix unary operators?
        }
    }
    new_arr_length = counter;
    return result;
}

int main() {
    int* result, i;
    int nums[] = { 1, 2, 4, 5, 7, 9, 11, 12, 13 };
    int arr_length = sizeof(nums) / sizeof(nums[0]);
    int new_arr_length;
    result = test(nums, arr_length, new_arr_length);
    for (i = 0; i < new_arr_length; i++) cout << result[i] << " ";
    // Seems to be working correctly... but, does it really?
    return 0;
}

