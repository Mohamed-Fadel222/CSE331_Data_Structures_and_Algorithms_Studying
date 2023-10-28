#include <iostream>
using namespace std;

void banishTheNegativity(int*& nums, int size) {
    int* temp = new int[size];
    int j = 0;
    for (int i = 0; i < size; i++) if (nums[i] >= 0) temp[j++] = nums[i];
    for (int i = 0; i < size; i++) if (nums[i] < 0) temp[j++] = nums[i];
    for (int i = 0; i < size; i++) nums[i] = temp[i];
    // We could do better with a deque! More on that later...
    // Should delete "temp" to avoid heap memory overflow!
    delete[] temp;
}

int main() {
    int nums[] = { 0, 9, -7, 2, -12, 11, -20 };
    int size = sizeof(nums) / sizeof(nums[0]);
    int* nums_ptr = nums;
    banishTheNegativity(nums_ptr, size);
    for (int i = 0; i < size; i++) cout << nums[i] << " ";
    return 0;
}

