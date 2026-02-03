#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];          // move 1 step
            fast = nums[nums[fast]];    // move 2 steps
        } while (slow != fast);

        // Phase 2: Find entry point of cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // duplicate number
    }
};