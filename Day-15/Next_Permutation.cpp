#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size() ;
        for(int i = n-2; i>= 0; i--) {
            if(nums[i]<nums[i+1]) {
                idx = i;
                break;
            }
        }
        // agr array desending order me hai to
        if(idx == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        reverse(nums.begin() +idx +1,nums.end()); // reverse the part next of idx
        // find just grater value than idx
        int j = -1;
        for(int i =idx +1; i<n; i++) {
            if(nums[idx]<nums[i]) {
                j = i;
                break;
            }
        }
        // swap idx value with this next value
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
    }
};
