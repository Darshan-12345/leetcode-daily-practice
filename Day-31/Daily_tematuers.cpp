#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(n - 1);
        vector<int> result(n,0);
       
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()])
                st.pop();
            if (st.size() > 0) {
               result[i] = st.top() - i;
            }
           
            st.push(i);
        }
        return result;
    }
};