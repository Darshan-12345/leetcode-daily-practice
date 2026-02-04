# LeetCode 125 – Valid Palindrome

## 📌 Problem Statement

Given a string `s`, determine if it is a **palindrome**, considering **only alphanumeric characters** and **ignoring cases**.

A palindrome reads the same forward and backward after removing non-alphanumeric characters and normalizing case.

---

## 🧠 Solution Overview

This problem can be solved using **two different approaches**:

1. **Approach 1: Extra String + Two Pointers (O(n) Space)**
2. **Approach 2: Optimized Two Pointers In-place (O(1) Space)**

Both approaches use the **two-pointer technique**, but differ in space usage.

---

## 🟢 Approach 1: Using Extra String (O(n) Space)

### 🔹 Idea

* Create an empty string
* Traverse the input string
* Keep only **alphanumeric characters**
* Convert uppercase letters to lowercase
* Apply two-pointer palindrome check on the cleaned string

### 🔹 Steps

1. Initialize empty string `val`
2. Filter characters using `isalnum()`
3. Convert uppercase to lowercase manually
4. Use two pointers (`left`, `right`) to check palindrome

### ✅ C++ Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string val = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(isalnum(s[i])) {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    val.push_back(s[i] + 32);
                } else {
                    val.push_back(s[i]);
                }
            }
        }
        
        int left = 0, right = val.size() - 1;
        while(left < right) {
            if(val[left] != val[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

### ⏱ Complexity

* **Time:** O(n)
* **Space:** O(n)

---

## 🔵 Approach 2: Optimized In-place Two Pointers (O(1) Space)

### 🔹 Idea

* Avoid creating an extra string
* Use two pointers directly on the original string
* Skip non-alphanumeric characters on the fly
* Compare characters after converting them to lowercase

### 🔹 Steps

1. Initialize `left = 0`, `right = s.length() - 1`
2. Skip non-alphanumeric characters from both ends
3. Compare lowercase characters
4. If mismatch occurs, return `false`

### ✅ C++ Code (Optimized)

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while(left < right) {
            while(left < right && !isalnum(s[left])) {
                left++;
            }
            while(left < right && !isalnum(s[right])) {
                right--;
            }
            
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

### ⏱ Complexity

* **Time:** O(n)
* **Space:** O(1) ✅

---

## 🧪 Example

```
Input:  "A man, a plan, a canal: Panama"
Output: true
```

Explanation:

* After removing non-alphanumeric characters and ignoring case,
  the string becomes `amanaplanacanalpanama`, which is a palindrome.

---

## 🆚 Comparison Summary

| Feature             | Approach 1           | Approach 2     |
| ------------------- | -------------------- | -------------- |
| Extra String        | Yes                  | No             |
| Space Complexity    | O(n)                 | O(1)           |
| Simplicity          | Easier to understand | More optimized |
| Interview Preferred | ❌                    | ✅              |

---

## 🏁 Conclusion

* **Approach 1** is beginner-friendly and easy to understand.
* **Approach 2** is optimal and preferred in interviews due to constant space usage.

Both approaches are valid; choosing one depends on constraints and optimization needs.

---

## 🔗 Reference

* LeetCode 125: Valid Palindrome
