#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int count = 0;
        vector<int>arr(n);
        int max1 = height[0],max2 = height[n-1];
         arr[0] =-1;
        for(int i =1; i<n; i++) {
            arr[i] = max1;
            max1 = max(height[i],max1);
        }
        arr[n-1] = -1;
        for(int  i = n-2; i>=0; i--) {
            arr[i] = min(arr[i],max2);
            max2 = max(height[i],max2);
        }
        for(int i =1; i<n-1; i++) {
            int val = arr[i]-height[i];
            if(val > 0) {
                count+=val;
            }
        }
        

       
       return count;
    }  
};