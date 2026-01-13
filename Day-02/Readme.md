# Day-02: Contains Duplicate

## Problem
Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Approach
- Use a hash map to store elements.
- Traverse the array only once.
- If an element already exists in the map, return true.
- Otherwise, insert the element into the map.
- If no duplicates are found, return false.

## Algorithm
1. Initialize an empty hash map.
2. Traverse the array.
3. Check if the current element exists in the map.
4. If yes, return true.
5. Else, insert it into the map.
6. After traversal, return false.

## Time and Space Complexity
- Time Complexity: O(n)
- Space Complexity: O(n)
