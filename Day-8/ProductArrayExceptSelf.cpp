#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// ------------------------------
// Approach 1: Prefix + Suffix Arrays (O(n) time, O(n) extra space)
// ------------------------------
class SolutionWithExtraSpace {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n), ans(n);

        // Prefix product
        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // Suffix product
        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        // Final answer
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};

// ------------------------------
// Approach 2: Optimized Space (O(n) time, O(1) extra space)
// ------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // Step 1: Store prefix products directly in ans
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }

        // Step 2: Multiply suffix products using a single variable
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};
