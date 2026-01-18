#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

/*
 LeetCode 347 - Top K Frequent Elements
 Day-07 Practice
*/

/*--------------------------------------------------
 Method 1: Brute Force
 Time Complexity: O(n * k)
 Space Complexity: O(n)
--------------------------------------------------*/
class SolutionBruteForce {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> result;

        for (int i = 0; i < k; i++) {
            int maxFreq = INT_MIN;
            int element = 0;

            for (auto it : freq) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    element = it.first;
                }
            }

            result.push_back(element);
            freq.erase(element);
        }
        return result;
    }
};

/*--------------------------------------------------
 Method 2: Max Heap
 Time Complexity: O(n log n)
 Space Complexity: O(n)
--------------------------------------------------*/
class SolutionMaxHeap {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for (auto it : freq) {
            maxHeap.push({it.second, it.first});
        }

        vector<int> result;
        while (k-- > 0) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};

/*--------------------------------------------------
 Method 3: Bucket Sort (Optimal)
 Time Complexity: O(n)
 Space Complexity: O(n)
--------------------------------------------------*/
class SolutionBucketSort {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && k > 0; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                k--;
                if (k == 0) break;
            }
        }
        return result;
    }
};
