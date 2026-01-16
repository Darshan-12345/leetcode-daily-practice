# Day-05: Ransom Note (LeetCode 383)

## Problem
Given two strings `ransomNote` and `magazine`, return true if `ransomNote` can be constructed using the letters from `magazine`.
Each letter in `magazine` can be used only once.

## Approach
- Use a frequency array of size 26 for lowercase letters.
- Count frequency of each character in `magazine`.
- Subtract frequency using characters of `ransomNote`.
- If at any point frequency becomes negative, return false.
- Otherwise, return true.

## Algorithm
1. If ransomNote length is greater than magazine length, return false.
2. Initialize frequency array.
3. Traverse magazine and increment frequencies.
4. Traverse ransomNote and decrement frequencies.
5. If any frequency is negative, return false.
6. Return true.

## Complexity
- Time Complexity: O(n + m)
- Space Complexity: O(1)
