# Day-03: Valid Anagram (LeetCode 242)

## Problem
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

## Approach 1: Hash Map
- Count frequency of characters in string s.
- Subtract frequency using string t.
- If all frequencies become zero, strings are anagrams.

Time: O(n)  
Space: O(n)

## Approach 2: Optimized Frequency Array
- Since strings contain only lowercase letters, use an array of size 26.
- Increment for s and decrement for t.
- Check if all values are zero.

Time: O(n)  
Space: O(1)

## Learning
Initially faced edge case failures, revised logic, and optimized the solution using a fixed-size array.
