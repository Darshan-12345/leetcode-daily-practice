# 📅 Day-07 – Top K Frequent Elements (C++)

## 🧠 Problem
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.

---

## ✅ Approaches Implemented

### 1️⃣ Brute Force
- Count frequency using hashmap
- Repeat `k` times:
  - Find max frequency element
  - Remove it from map

**Time Complexity:** O(n * k)  
**Space Complexity:** O(n)

---

### 2️⃣ Max Heap
- Store `{frequency, element}` in priority queue
- Pop top `k` elements

**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

---

### 3️⃣ Bucket Sort (Optimal)
- Index represents frequency
- Store elements at their frequency index
- Traverse bucket from end

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

✔ This satisfies the follow-up condition (better than O(n log n))

---

## 🚀 Learning Outcomes
- Comparison of brute force vs optimized solutions
- How bucket sort improves performance
- Frequency-based problem patterns

🔥 Consistency beats motivation
