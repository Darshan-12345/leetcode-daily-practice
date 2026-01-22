#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums) {
            st.insert(num);
        }
        int maxlen = 0;
        for(int x : st) {
            if(! st.count(x-1)) {
                int curr = x;
                int len = 1;
                while(st.count(curr+1)) {
                    curr++;
                    len++;
                }
                maxlen = max(len,maxlen);
            }
            
        }
        return maxlen;
    }
};