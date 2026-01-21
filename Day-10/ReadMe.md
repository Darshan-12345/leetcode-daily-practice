# Encode and Decode Strings (Length-Based Serialization)

## 🧩 Problem Statement

Design an algorithm to encode a list of strings into a single string and decode it back to the original list.

### Requirements

* Encoding and decoding must be **lossless**
* Strings may contain:

  * Special characters (`#`, `$`, etc.)
  * Numbers
  * Empty strings
* Order of strings must be preserved

---

## 🧠 Why This Problem Matters

This problem is not about strings only.
It teaches **serialization and deserialization**, which is used in:

* Network communication
* File storage formats
* APIs
* Distributed systems

---

## ❌ Initial Thoughts (What Didn’t Work)

### 1️⃣ Frequency-based approach ❌

At first, I thought about:

* Counting character frequency
* Joining using a delimiter

**Why it fails:**

* Loses order
* Fails for duplicate characters
* Cannot reconstruct original strings

---

### 2️⃣ Delimiter-only separation ❌

Example:

```
hello#world
```

**Problem:**
What if the original string itself contains `#`?

Decoder cannot distinguish between:

* separator
* actual data

---

## ✅ Final Approach (Correct Way)

### Key Insight

> **Never guess string boundaries. Always store length.**

We encode each string in the format:

```
<length>#<string>
```

### Example

```
Input:  ["hello", "code"]
Encode: "5#hello4#code"
```

---

## 🔁 Encoding Process

For each string:

1. Convert its length to string
2. Append delimiter `#`
3. Append the actual string

This produces **one continuous encoded string**.

---

## 🔍 Decoding Process (Important Part)

We use an index-based traversal.

### Steps:

1. Start from index `i = 0`
2. Read digits until `#` → this gives string length
3. Skip `#`
4. Read exactly `length` characters
5. Push this substring into result
6. Move index forward
7. Repeat until end

---

## ⚠️ Where I Struggled (Very Important)

### 1️⃣ Counting length incorrectly

Mistake:

```cpp
len = len * 10 + len; // wrong
```

Fix:

```cpp
len = len * 10 + (s[i] - '0');
```

---

### 2️⃣ Infinite loop bug

Forgot to increment `i` while reading digits.

Lesson:

> Every loop that reads characters must move the pointer.

---

### 3️⃣ Confusion about string start index

I was confused:

> “How do I calculate the starting index of the string chunk?”

### Breakthrough Insight:

> **The index right after `#` is the starting index.**

No extra variable is needed.

---

### 4️⃣ Using `for` loop instead of pointer-based loop

Decoding requires:

* jumping over chunks
* skipping fixed sizes

So `while (i < s.length())` is mandatory.

---

## 💡 Hints (For Anyone Trying This Problem)

### Hint 1

Do not split the string using delimiter.

### Hint 2

Length can be more than one digit.

### Hint 3

Delimiter ends metadata, not data.

### Hint 4

Once you know the length, trust it completely.

---

## 🧪 Edge Cases Covered

* Empty string `""`
* Strings containing `#`
* Strings containing numbers
* Duplicate strings
* Multi-digit lengths

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(N)`
  (`N` = total number of characters)
* **Space Complexity:** `O(N)`

---

## 🧠 Key Learnings

* Serialization must be deterministic
* Length-based encoding avoids ambiguity
* Pointer-based parsing is powerful
* Small index mistakes can cause infinite loops

---

## 🧑‍💻 Implementation (C++)

```cpp
class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.length());
            encoded += '#';
            encoded += s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> message;
        int i = 0;

        while (i < s.length()) {
            int len = 0;

            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++; // skip '#'

            string chunk = s.substr(i, len);
            message.push_back(chunk);

            i += len;
        }

        return message;
    }
};
```

---

## 🚀 Final Thoughts

This problem looks simple but tests:

* string parsing
* careful index management
* real-world system design thinking

Solving it improved my understanding of:
**how data is safely transmitted and reconstructed**.

---

### 👤 Author

**Darshan**
