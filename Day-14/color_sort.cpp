#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
       vector<int> freq(3);
       
       for(int i = 0; i<n; i++){
            freq[nums[i]]++;
       }
       int c1 = freq[0],c2 = freq[1], c3 = freq[2];
       for(int i = 0; i<n; i++) {
        if(i < c1) {
            nums[i] = 0;
        }
        else if(i >= c1 && i < c1+ c2) {
            nums[i] = 1;
        }
        else {
            nums[i] = 2;
        }
       }
      
    }
};