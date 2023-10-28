#include <iostream>
using namespace std;

bool test(int nums[], int arr_length) { return nums[0] == 10 || nums[arr_length - 1] == 10; }

int main() {

    int arr_length;

    int nums1[] = { 10, 20, 40, 50 };
    arr_length = sizeof(nums1) / sizeof(nums1[0]);
    cout << test(nums1, arr_length) << endl;

    int nums2[] = { 05, 20, 40, 10 };
    arr_length = sizeof(nums2) / sizeof(nums2[0]);
    cout << test(nums2, arr_length) << endl;

    int nums3[] = { 10, 20, 40, 10 };
    arr_length = sizeof(nums3) / sizeof(nums3[0]);
    cout << test(nums3, arr_length) << endl;

    int nums4[] = { 12, 24, 35, 55 };
    arr_length = sizeof(nums4) / sizeof(nums4[0]);
    cout << test(nums4, arr_length) << endl;

    return 0;
}
