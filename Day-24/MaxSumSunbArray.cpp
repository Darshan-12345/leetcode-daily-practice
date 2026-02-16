#include<iostream>
#include<vector>
using namespace std;

int MaxSumSubArr(vector<int>nums) {
    int n = nums.size();
    int maxSum = nums[0];
    int currSum = nums[0];
    for(int i = 1; i<n; i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {1,2,3,-2,5};
    cout<<MaxSumSubArr(nums);
}