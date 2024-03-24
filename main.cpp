#include <iostream>
#include <vector>
#include <unordered_set>

bool containsReplica(std::vector<int>& nums) {
    std::unordered_set<int> distinctiveSet;

    for (int num : nums) {
        // If the element is already in the set, there is a replica
        if (distinctiveSet.count(num) > 0) {
            return true;
        }
        // Otherwise, add the element to the set
        distinctiveSet.insert(num);
    }

    // No replicas found
    return false;
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 1};

    bool result = containsReplica(nums);

    if (result) {
        std::cout << "The array contains replicas." << std::endl;
    } else {
        std::cout << "The array does not contain replicas." << std::endl;
    }

    return 0;
}

