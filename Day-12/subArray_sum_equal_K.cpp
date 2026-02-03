#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
 


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
        unordered_map<int,int> mp;
        int n = nums.size();
        int sum  = 0;
       int count = 0;
       vector<int> prefixSum(n);
       prefixSum[0] = nums[0];
       // first calculate prefix sum
       for(int i =1; i<n; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i];
       }
       // then check subarray is exist or not 
       // use formula subarray(i,j) = pre(j) - pre(i-1)
       // we suppose  sum for i to j is k 
       // then we need to find pre(i-1) in map
       // and store all prefixSum with there freq in map 
       // and search them and increase count
       for(int j =0; j<n; j++) {
        if(prefixSum[j] == k) count++;
        int val = prefixSum[j] - k;
        if(mp.find(val) != mp.end()) {
            count+= mp[val];
        }
        if(mp.find(prefixSum[j]) == mp.end()) {
            mp[prefixSum[j]] = 0;
        }
        mp[prefixSum[j]]++;


       }
       
      
        return count;
    }
};