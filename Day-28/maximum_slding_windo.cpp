#include<iostream>
#include<vector>
#include<queue>

using namespace std;


vector<int> maxSldingWindo(vector<int>& nums, int k) {
    int n = nums.size();
    if(k == 1) return nums;
    vector<int>result;
    deque<int> dq;
    for(int i =0; i<n; i++) {
        while(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(!dq.empty() && i>= k-1){
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main() {
   vector<int> nums = {1,3,-1,-3,5,3,6,7};
   int k = 3;
   vector<int> result = maxSldingWindo(nums,k);
   for(int i =0; i<result.size(); i++) {
       cout<<result[i]<<" ";
   }
}