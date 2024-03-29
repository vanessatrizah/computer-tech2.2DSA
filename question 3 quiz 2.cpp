#include <iostream>
#include <vector>

  int removeReplicas(std::vector<int>& nums) {
    if (nums.empty()) {//references vector of intergers and returns new lengh.
        return 0;
    }

    int k = 0;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[k]) {
            // Move the unique element to the next position
            nums[++k] = nums[i];
        }
    }

    // The new length is the unique index + 1
    return k + 1;
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5}; //initialise the vector

    int newLength = removeReplicas(nums);

    std::cout << "New Length: " << newLength << std::endl;
    std::cout << "Updated Array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << nums[i] << " ";
    }

    return 0;
}

