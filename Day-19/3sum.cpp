#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[n - 1] < 0)
            return ans;
        for (int i = 0; i < n; i++) {
            // for avoiding repeted values
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int left = i + 1, right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int val = nums[left] + nums[right];

                if (val == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                // for also avoding repeated values
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                } else if (val > target)
                    right--;
                else
                    left++;
            }
        }

        return ans;
    }
};