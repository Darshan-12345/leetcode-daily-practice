# Next Permutation (In-place Algorithm)

## 📌 Problem Summary

Given an array of integers `nums`, find the **next lexicographically greater permutation** of the array.

* If a next permutation exists, modify the array **in-place** to that permutation.
* If no such permutation exists (array is in descending order), rearrange it into the **lowest possible order** (ascending).
* Extra space allowed: **O(1)** (constant space).

---

## 🧠 Intuition (My Understanding)

Lexicographical order means dictionary order. The goal is to generate the **just next bigger arrangement**, not a large jump.

Key ideas:

* Changes should be as small as possible.
* The **right side of the array changes faster**, so we always scan from the end.

---

## ✅ Step-by-Step Approach

### **Step 1: Find the Pivot Element**

Traverse the array from **right to left** and find the first index `i` such that:

```
nums[i] < nums[i + 1]
```

* This index `i` is called the **pivot index**.
* The element `nums[i]` is the **pivot element**.
* All elements to the **right of pivot are in descending order**.

📌 Example:

```
[1, 3, 2]
 pivot = 1 (because 1 < 3)
```

---

### **Step 2: If Pivot Is NOT Found**

If no such index exists, it means:

* The array is fully sorted in **descending order**
* This is the **largest permutation**

✅ Action:

```
Reverse (or sort ascending) the entire array
```

📌 Example:

```
[3, 2, 1] → [1, 2, 3]
```

---

### **Step 3: If Pivot Is Found**

Since elements after the pivot are already in **descending order**, we do the following:

#### 3.1 Sort / Reverse the Suffix

Sort (or reverse) the elements **after the pivot index** to make them ascending.

Why?

* After changing the pivot, we want the **smallest possible suffix** to get the next permutation.

---

#### 3.2 Find the Next Greater Element

From the sorted suffix, find the **smallest element that is greater than the pivot element**.

This guarantees:

* The increase is minimal
* We get the immediate next permutation

---

#### 3.3 Swap

Swap:

```
pivot element ↔ next greater element
```

After this swap, the array becomes the **next permutation**.

---

## 🔄 Example Walkthrough

### Example 1

```
Input:  [1, 3, 2]
```

1. Pivot = `1`
2. Suffix = `[3,2]` (descending)
3. Sort suffix → `[2,3]`
4. Next greater than `1` = `2`
5. Swap → `[2,1,3]`

✅ Output:

```
[2,1,3]
```

---

### Example 2

```
Input: [1, 1, 5]
```

1. Pivot = `1`
2. Suffix = `[5]`
3. Next greater = `5`
4. Swap → `[1,5,1]`

✅ Output:

```
[1,5,1]
```

---

## 🔑 Why This Works

* Pivot identifies the **first place where an increase is possible**
* Swapping with the **next greater element** ensures minimal increase
* Sorting/reversing the suffix ensures the **smallest arrangement afterward**

This guarantees the **next lexicographical permutation**, not skipping any.

---

## ⏱ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` (in-place)

---

## 🧠 One-Line Memory Trick

> Increase the pivot slightly, then minimize everything after it.

---

