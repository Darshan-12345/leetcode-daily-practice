# Valid Sudoku (LeetCode 36)

## Problem Statement

Given a 9×9 Sudoku board, determine if it is valid. Only the filled cells need to be validated according to the following rules:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3×3` sub-boxes must contain the digits `1-9` without repetition.

Empty cells are represented by `'.'`.

---

## Approach

The idea is simple:

> **If any number repeats in a row, column, or 3×3 box → return `false`.**
> If all checks pass → return `true`.

We solve the problem in **three independent passes**.

---

## 1️⃣ Row Validation

* Traverse each row
* Use a frequency array of size 10
* Ignore `'.'`
* If a number appears more than once → invalid Sudoku

**Why it works:**
Each row must contain unique digits from 1 to 9.

---

## 2️⃣ Column Validation

* Traverse each column
* Reset frequency array for every column
* Ignore `'.'`
* Detect duplicates

**Why it works:**
Each column must also contain unique digits.

---

## 3️⃣ 3×3 Sub-box Validation (Most Confusing Part)

### Key Idea

The outer two loops fix the **starting index** of each 3×3 box:

```cpp
for (int rowStart = 0; rowStart <= 6; rowStart += 3)
    for (int colStart = 0; colStart <= 6; colStart += 3)
```

This generates the top-left corner of each 3×3 box:

```
(0,0) (0,3) (0,6)
(3,0) (3,3) (3,6)
(6,0) (6,3) (6,6)
```

### Inner Loops

The inner loops traverse **inside one 3×3 box**:

```cpp
for (int i = rowStart; i < rowStart + 3; i++)
    for (int j = colStart; j < colStart + 3; j++)
```

A frequency array ensures no number repeats inside the box.

---

## Complexity Analysis

| Metric           | Value                      |
| ---------------- | -------------------------- |
| Time Complexity  | **O(1)** (fixed 9×9 board) |
| Space Complexity | **O(1)**                   |

---

## Example

Input:

```
board =
[
 ['5','3','.','.','7','.','.','.','.'],
 ['6','.','.','1','9','5','.','.','.'],
 ['.','9','8','.','.','.','.','6','.'],
 ['8','.','.','.','6','.','.','.','3'],
 ['4','.','.','8','.','3','.','.','1'],
 ['7','.','.','.','2','.','.','.','6'],
 ['.','6','.','.','.','.','2','8','.'],
 ['.','.','.','4','1','9','.','.','5'],
 ['.','.','.','.','8','.','.','7','9']
]
```

Output:

```
true
```

---

## Conclusion

* Problem is about **careful traversal**, not complex logic
* 3×3 box traversal becomes easy once starting indices are clear
* Frequency array is the cleanest way to detect duplicates

✅ This solution is **clean, readable, and interview-ready**
