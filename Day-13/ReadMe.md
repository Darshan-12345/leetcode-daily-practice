# Find All Anagrams in a String (Sliding Window)

## Problem
Given two strings `s` and `p`, find all starting indices of `p`'s anagrams in `s`.


---

## 🧪 My First Approach (Brute Force)

### Idea
- For every substring of `s` with length `p.length()`
- Count frequency of characters
- Compare with frequency of `p`
- If equal, push starting index

### Problem with this approach
- Recalculates frequency for **every substring**
- Time complexity becomes **O(n²)**
- Causes **TLE (Time Limit Exceeded)**  
- When trying to copy frequency arrays → **MLE (Memory Limit Exceeded)**

❌ Not acceptable for large inputs.

---

## 🚀 Optimized Approach (Sliding Window)

### Key Insight
Instead of recalculating frequency again and again:
- Fix a window of size `p.length()`
- Slide it one step at a time
- Only **one character enters** and **one character leaves**

---

## 🧠 Steps Used

### 1️⃣ Frequency of `p`
Create an array `freqP[26]`  
This stores how many times each character appears in `p`.

### 2️⃣ First Window Frequency
Create `windowFreq[26]`  
Count frequency of the first `p.length()` characters of `s`.

### 3️⃣ First Comparison
If `windowFreq == freqP`  
→ anagram found at index `0`

### 4️⃣ Slide the Window
For each new character:
- ➕ **Include new character** (right side)
- ➖ **Remove old character** (left side)
- Compare frequencies again

If equal → push starting index.

---

## 🧩 Small Hints (for future me)

- Window size is always **fixed**
- Only **2 updates per slide**
- Never recompute full frequency
- `vector<int>(26)` comparison is **constant time**
- Sliding window = add one + remove one

Think:
