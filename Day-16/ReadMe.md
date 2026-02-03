# LeetCode 287 – Find the Duplicate Number

## 📌 Problem Statement

You are given an integer array `nums` containing **n + 1 integers**, where each integer is in the range **[1, n]** (inclusive).

There is **only one duplicate number**, but it may appear more than once.

### Constraints

* You **must not modify** the array
* You must use only **O(1) extra space**
* Time complexity should be **better than O(n²)**

---

## 💡 Key Insight

Because:

* Array size = `n + 1`
* Values are in range `[1, n]`

We can treat the array as a **linked list**:

```
index → nums[index]
```

Due to the duplicate number, a **cycle is guaranteed** to exist.
The **duplicate number is the entry point of the cycle**.

To find this cycle and its entry point efficiently, we use **Floyd’s Cycle Detection Algorithm (Tortoise & Hare)**.

---

## 🐢🐇 Floyd’s Cycle Detection Algorithm

### Phase 1: Detect the cycle

* Use two pointers:

  * `slow` moves 1 step at a time
  * `fast` moves 2 steps at a time
* If they meet, a cycle exists

### Phase 2: Find the cycle entry (duplicate number)

* Reset `slow` to the start
* Move both pointers 1 step at a time
* The point where they meet again is the **duplicate number**

---









## 🧠 Example Walkthrough

```
nums = [1,3,4,2,2]

0 → 1 → 3 → 2 → 4
           ↑     ↓
           ← ← ← ←
```

* Cycle detected inside the loop
* Entry point of the cycle = `2`
* Hence, duplicate number = **2**

---

## ⏱ Complexity Analysis

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

---

## 🏁 Conclusion

This approach avoids extra memory and array modification by cleverly interpreting the array as a linked list.

> **Duplicate number = Cycle entry point**

Floyd’s algorithm guarantees correctness with constant space.

---

## 🔗 Reference

* LeetCode Problem 287: Find the Duplicate Number
