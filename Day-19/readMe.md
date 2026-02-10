3Sum Problem
Problem

Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]] such that:

nums[i] + nums[j] + nums[k] = 0


The solution set must not contain duplicate triplets.

Approach
1. Brute Force Approach (Initial Idea)

The first idea is to use three nested loops to check every possible triplet.

Steps:

Use three loops to pick i, j, k

If the sum is 0, store the triplet

Use a set to avoid duplicate triplets

Time Complexity: O(n³)
This approach is very slow and not efficient for large inputs.

2. Optimized Approach (Two Pointer Technique)

To improve performance, we convert the problem into a 2-Sum problem.

Step 1 — Sort the Array

Sorting helps:

Apply the two-pointer method

Easily skip duplicate values

Detect impossible cases quickly

If all values are positive → no triplet possible

If all values are negative → no triplet possible

Step 2 — Fix First Element

Use a loop to fix the first element nums[i].

To avoid duplicate triplets:

If the current element is the same as the previous element, skip it.

if(i > 0 && nums[i] == nums[i-1]) continue;

Step 3 — Convert Remaining Problem to 2-Sum

For every fixed element:

Target = -nums[i]

Use two pointers:

left = i + 1

right = n - 1

Find pairs such`. such that:

nums[left] + nums[right] == target

Step 4 — Pointer Movement Logic

Inside the while loop:

If pair found:

Store the triplet

Move both pointers

Skip duplicate values using while loops

If sum greater than target:

right--


If sum smaller than target:

left++

Step 5 — Avoid Duplicate Pairs

After finding a valid triplet:

while(left < right && nums[left] == nums[left-1]) left++;
while(left < right && nums[right] == nums[right+1]) right--;


This ensures only unique triplets are stored.

Complexity Analysis

Sorting: O(n log n)

Two-pointer scanning: O(n²)

Total Time Complexity: O(n²)
Space Complexity: O(1) (excluding output)

Key Learning

The 3Sum problem can be solved efficiently by:

Sorting the array

Fixing one element

Reducing the remaining problem to 2-Sum using two pointers

Skipping duplicates at all necessary steps