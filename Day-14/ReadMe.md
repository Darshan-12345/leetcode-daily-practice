# Sort Colors (LeetCode 75)

## 🧩 Problem Statement

Given an array `nums` with `n` objects colored **red**, **white**, or **blue**, sort them **in-place** so that objects of the same color are adjacent.

We use the following representation:

* `0` → Red
* `1` → White
* `2` → Blue

You must solve this problem **without using the built-in sort function**.

---

## 💡 My Initial Thinking

Since there are **only 3 possible values (0, 1, 2)**, I thought:

* Why not **count how many times each number appears**?
* Then **rewrite the array** using those counts.

This feels like a natural and clean approach, especially when:

* The number of distinct elements is very small
* Order inside the same color does not matter

---

## ❌ Possible Confusion / Limitation

* This approach uses an **extra array (frequency array)**
* Space complexity is **O(1)** technically (because size is fixed = 3), but:

  * LeetCode also expects an optimal **one-pass, constant-space** solution (Dutch National Flag algorithm)

Still, this solution is:

* Correct
* Easy to understand
* Good for learning and interviews as a first step

---

## ✅ Final Correct Approach (Frequency Counting)

### Step 1: Count frequency of each color

* Create a vector `freq` of size 3
* Increment `freq[nums[i]]`

### Step 2: Rewrite the original array

* First `freq[0]` elements → `0`
* Next `freq[1]` elements → `1`
* Remaining → `2`

---

## 🧠 Why This Works

* Only three values exist → fixed-size frequency array
* No sorting needed
* Time Complexity: **O(n)**
* Space Complexity: **O(1)** (constant extra space)

---

## 🧪 Example

Input:

```
nums = [2,0,2,1,1,0]
```

Frequency:

```
freq = [2,2,2]
```

Output:

```
[0,0,1,1,2,2]
```

---

## 🧑‍💻 Code Implementation

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(3, 0);

        // Count frequency
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        int c1 = freq[0], c2 = freq[1];

        // Rewrite array
        for (int i = 0; i < n; i++) {
            if (i < c1) {
                nums[i] = 0;
            } else if (i < c1 + c2) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
    }
};
```

---

## 🚀 What I Learned

* When the value range is small, **counting is powerful**
* Always check if the problem expects:

  * One-pass solution
  * In-place algorithm
* This solution builds a strong foundation before learning the **Dutch National Flag algorithm**

---

## 🔜 Next Improvement

Learn and implement:

* **Dutch National Flag Algorithm (3 pointers)**
* One pass
* No extra space

---

⭐ If you are reading this repo: this solution shows **clear thinking + learning progression**, not just final answers.
