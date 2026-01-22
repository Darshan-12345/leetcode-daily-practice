# Longest Consecutive Sequence

## 🧩 Problem Statement

Given an unsorted array of integers `nums`, return the length of the **longest consecutive elements sequence**.

**Constraint:**
The algorithm must run in **O(n)** time.

---

## 🤔 My Initial Thinking (Where I Got Confused)

At first, I thought:

* If numbers are consecutive, their **difference is 1**
* So I can check `current + 1` exists and keep increasing the count

### Problems with this approach:

* ❌ **Duplicates** cause repeated counting
* ❌ **Multiple consecutive sequences** exist
* ❌ Same sequence gets **recounted many times**
* ❌ Iterating directly over the array leads to **TLE for large inputs**

This made the solution inefficient and incorrect for large test cases.

---

## 💡 Key Insight (After Getting Help)

The most important realization:

> **Only start counting when the number is the START of a sequence**

A number `x` is the start of a sequence **if and only if**:

```
(x - 1) does NOT exist
```

If `(x - 1)` exists, then `x` is already part of another sequence, so we skip it.

---

## ✅ Correct Approach

### Step 1: Use a HashSet

* Copy all elements of the array into a `HashSet`
* This automatically **removes duplicates**
* Allows **O(1)** average lookup

### Step 2: Iterate Over the HashSet

* Iterate over **unique elements only** (not the array)
* This avoids recounting the same sequence multiple times

### Step 3: Identify Sequence Start

* For each number `x`:

  * If `(x - 1)` exists → skip
  * Else → `x` is the start of a sequence

### Step 4: Expand the Sequence

* Use a `while` loop to check:

  * `x + 1`, `x + 2`, `x + 3`, ...
* Count the length until the sequence breaks

### Step 5: Update Maximum Length

* Compare current sequence length with `maxLength`
* Update if current is larger

---

## 🧠 What I Learned

* HashSet is essential to handle duplicates efficiently
* Checking `(x - 1)` avoids redundant work
* Each number is processed **only once**, guaranteeing **O(n)** time
* Iterating over the array instead of the set can cause **TLE**

---

## 🎯 Final Takeaway

This problem looks simple, but the real challenge is:

* Avoiding duplicate work
* Identifying the correct starting point
* Ensuring true O(n) performance

Understanding **why** the naive approach fails helped me understand the **correct optimized solution**.

---

### 👤 Author

**Darshan**
