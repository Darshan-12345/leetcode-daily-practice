# 📌 Daily Temperatures - LeetCode

## 🧠 Problem Statement

Given an array `temperatures[]` where `temperatures[i]` represents the temperature on the ith day,  
return an array `answer[]` such that:

- `answer[i]` = number of days you need to wait to get a warmer temperature.
- If no warmer day exists in future, then `answer[i] = 0`.

---

## 🔍 Example

### Example 1:
Input:[73,74,75,71,69,72,76,73]
output:[1,1,4,2,1,1,0,0]

---
## 💡 Approach (Using Stack - Right to Left Traversal)

This problem is a variation of **Next Greater Element**.

### ✅ Why Stack?

We use a **monotonic decreasing stack** to efficiently find the next warmer temperature.

### ✅ Why Right to Left?

If we traverse from right → left:

- We already know future temperatures.
- Stack will contain indices of warmer temperatures.
- We can directly calculate difference in indices.

---

## 🚀 Algorithm

1. Create a result array `ans[]` of same size initialized with 0.
2. Create a stack to store indices.
3. Traverse from right → left.
4. While stack is not empty AND current temperature >= stack top temperature:
   - Pop from stack.
5. If stack is not empty:
   - `ans[i] = stack.top() - i`
6. Push current index into stack.

---

## ⏱ Time & Space Complexity

- **Time Complexity:** O(n)  
  Each element is pushed and popped once.

- **Space Complexity:** O(n)  
  Stack can contain at most n elements.

---
## 💡 Approach (Using Stack - Right to Left Traversal)

This problem is a variation of **Next Greater Element**.

### ✅ Why Stack?

We use a **monotonic decreasing stack** to efficiently find the next warmer temperature.

### ✅ Why Right to Left?

If we traverse from right → left:

- We already know future temperatures.
- Stack will contain indices of warmer temperatures.
- We can directly calculate difference in indices.

---

## 🚀 Algorithm

1. Create a result array `ans[]` of same size initialized with 0.
2. Create a stack to store indices.
3. Traverse from right → left.
4. While stack is not empty AND current temperature >= stack top temperature:
   - Pop from stack.
5. If stack is not empty:
   - `ans[i] = stack.top() - i`
6. Push current index into stack.

---

## ⏱ Time & Space Complexity

- **Time Complexity:** O(n)  
  Each element is pushed and popped once.

- **Space Complexity:** O(n)  
  Stack can contain at most n elements.


