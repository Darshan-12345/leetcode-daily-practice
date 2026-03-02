# 🧮 Evaluate Reverse Polish Notation (LeetCode 150)

## 📌 Problem Statement

Evaluate the value of an arithmetic expression in **Reverse Polish Notation (RPN)**.

Valid operators are:
- `+`
- `-`
- `*`
- `/`

Each operand may be an integer or another expression.

Division between two integers should truncate toward zero.

---

## 🧠 What is Reverse Polish Notation?

In RPN:
- Operators come **after** operands.
- No need for parentheses.
- Evaluation is done using a **stack**.

### Example 1:
Input:
["2","1","+","3","*"]

Explanation:
(2 + 1) * 3 = 9

Output:
9

---

### Example 2:
Input:
["4","13","5","/","+"]

Explanation:
13 / 5 = 2  
4 + 2 = 6  

Output:
6

---

## 🚀 Approach (Using Stack)

1. Create a stack of integers.
2. Traverse the tokens:
   - If token is a number → convert using `stoi()` and push to stack.
   - If token is an operator:
     - Pop top two numbers.
     - Apply operation.
     - Push result back to stack.
3. Final answer will be at top of stack.

---

## ⚠️ Important Concept

Order matters!

If stack has:
5 (bottom)
3 (top)

For "-" operator:

Result = 5 - 3  
NOT 3 - 5

Always:

num1 = top  
num2 = next  

result = num2 operator num1

---

