# Subarray Sum Equals K

## 📌 Problem Statement
Given an integer array `nums` and an integer `k`, return the total number of **continuous subarrays** whose sum equals `k`.

A subarray is a contiguous part of the array.

---

## 💡 Intuition

Brute force checks all possible subarrays, but that takes too much time for large inputs.

To optimize, we use the **Prefix Sum + Hash Map** technique.

The key idea is:
> If the difference between two prefix sums is `k`, then the subarray between them has sum `k`.

---

## 🧠 Prefix Sum Concept

Let:
- `prefixSum[i]` = sum of elements from index `0` to `i`

For a subarray from index `i` to `j`:
