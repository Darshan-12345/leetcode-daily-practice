# Day-04: Majority Element (LeetCode 169)

## Problem
Given an array `nums` of size `n`, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.

## Approaches

### 1. Sorting Approach
- Sort the array.
- Since the majority element appears more than n/2 times, it will always be at the middle index.

Time Complexity: O(n log n)  
Space Complexity: O(1)

---

### 2. Hash Map Approach
- Store frequency of each element.
- Return the element whose frequency is greater than n/2.

Time Complexity: O(n)  
Space Complexity: O(n)

---

### 3. Moore’s Voting Algorithm (Optimal)
- Maintain a `candidate` and a `count`.
- When count becomes 0, choose a new candidate.
- Increment count if the current element equals candidate, else decrement.
- The final candidate is the majority element.

Time Complexity: O(n)  
Space Complexity: O(1)

## Learning
Moore’s Voting Algorithm works because the majority element always remains dominant even after cancellation with other elements.
