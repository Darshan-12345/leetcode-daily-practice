# 🌳 Binary Tree Paths (LeetCode)

## 📌 Problem Statement

Given the `root` of a binary tree, return all root-to-leaf paths in any order.

A **leaf node** is a node with no children.

---

## 🧠 Approach

We use **Recursion (DFS - Depth First Search)** to traverse the binary tree.

### 🔹 Key Idea:

* Start from the root node
* Keep building the path as a string
* When we reach a **leaf node**, store the path in the result
* Use **string copy (`str + ...`) instead of modifying original string (`str += ...`)**

---

## ⚠️ Important Learning

Using `str +=` inside recursion can cause incorrect results because it modifies the same string for all recursive calls.

✅ Always use:

```cpp
str + value + "->"
```

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    void helper(TreeNode* root, vector<string>& result, string str) {
        if(root == NULL) return;

        string a = to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            result.push_back(str + a);
            return;
        }

        helper(root->left, result, str + a + "->");
        helper(root->right, result, str + a + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper(root, result, "");
        return result;
    }
};
```

---

## 🔍 Example

### Input:

```
      1
     / \
    2   3
     \
      5
```

### Output:

```
["1->2->5", "1->3"]
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(N)
  (We visit each node once)

* **Space Complexity:** O(H)
  (Recursion stack, where H = height of tree)

---

## 🚀 Key Takeaways

* Use recursion for tree traversal
* Avoid modifying shared variables in recursion
* Prefer passing **new copies of data**

---

## 🙌 Author

Darshan 🚀
