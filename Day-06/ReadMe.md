# Day-06: Group Anagrams (LeetCode 49)

## Problem
Given an array of strings, group the anagrams together.

## Approach 1: Sorting
- Sort each string.
- Use sorted string as key in hash map.
- Anagrams will have the same sorted form.

Time Complexity: O(n * k log k)  
Space Complexity: O(n)

---

## Approach 2: Frequency Array (Optimal)
- Count frequency of characters using array of size 26.
- Convert frequency array to string key using separator (#).
- Use this key in hash map.

Time Complexity: O(n * k)  
Space Complexity: O(n)

## Learning
Initially considered brute force comparison, but it caused repeated work.
Using hashing avoids redundant comparisons and improves performance.
