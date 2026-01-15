#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // it is based on Moore's Algorithm
        //there is majority elelment in array it is always in lead after encounting other numbers
       int candidate = 0;
       int count = 0;
       for(int num : nums){
        if(count == 0) {
            candidate = num;
        }
        if(num == candidate) {
            count++;
        }
        else {
            count--;
        }
       }
       return candidate;
       
    }
};