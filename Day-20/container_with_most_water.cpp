#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int result = (right - left) * min(height[left], height[right]);
            area = max(area, result);

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return area;
    }
};
