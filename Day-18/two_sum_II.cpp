#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right) {
            int ans  = numbers[left] + numbers[right];
            if(ans  == target) {
                return {left+1,right+1};
            }
            else if( ans < target) {
                left++;
            }
            else{
                right--;
            }
        }
        return {left,right};
    }
};