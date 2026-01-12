// LeetCode 1: Two Sum
// Approach: Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if(map.find(need) != map.end()) {
                return {map[need], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
