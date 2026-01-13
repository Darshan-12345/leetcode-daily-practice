# leetcode-daily-practice
Every single problem here is a small battle against laziness, excuses, and comfort. No zero days. No shortcuts. Just showing up and doing the work.


## Day-01: Two Sum

### Problem
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

### Approach
We traverse the array once and use a hash map to store each number along with its index.

For every element `x`:
- Calculate the required value `y = target - x`
- If `y` already exists in the map, we have found the answer
- Return the index of `y` from the map and the current index
- If not found, store `x` in the map with its index

### Complexity
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

### Key Idea
Using a hash map allows us to check the complement in constant time, reducing the overall complexity.
