# LeetCode 71 – Simplify Path

## 🧩 Problem

Given a string `path`, which represents an **absolute path in a Unix-style file system**, simplify it.

In a Unix file system:

* `.` refers to the **current directory**
* `..` refers to the **parent directory**
* Multiple slashes like `//` are treated as a **single slash `/`**
* Any other sequence of characters is considered a **directory name**

The task is to return the **simplified canonical path**.

---

## 📥 Example

**Input**

```
path = "/.../a/../b/c/../d/./"
```

**Output**

```
/.../b/d
```

---

## 📖 Explanation

The path is processed step by step:

| Step | Directory | Action                         | Current Path |
| ---- | --------- | ------------------------------ | ------------ |
| 1    | `...`     | Normal directory → move inside | `/...`       |
| 2    | `a`       | Move inside                    | `/.../a`     |
| 3    | `..`      | Go back to parent              | `/...`       |
| 4    | `b`       | Move inside                    | `/.../b`     |
| 5    | `c`       | Move inside                    | `/.../b/c`   |
| 6    | `..`      | Go back                        | `/.../b`     |
| 7    | `d`       | Move inside                    | `/.../b/d`   |
| 8    | `.`       | Stay in same directory         | `/.../b/d`   |

Final simplified path:

```
/.../b/d
```

---

## 💡 Approach

To simplify the path, we process directory names one by one.

### Steps

1. Split the path using `/`.
2. Use a **stack (or vector)** to keep track of directories.
3. For each token:

   * If token is `""` or `"."` → ignore it
   * If token is `".."` → remove the last directory from stack (if any)
   * Otherwise → push the directory name to the stack
4. Finally, join all elements in the stack with `/` to build the canonical path.

---

## 🧠 Key Observations

* `"..."` is **not special**; it is treated as a normal folder name.
* `".."` is the **only token that moves one directory up**.
* The path must always start with `/`.

---

## ⏱ Time and Space Complexity

**Time Complexity:**

```
O(n)
```

where `n` is the length of the path.

**Space Complexity:**

```
O(n)
```

for storing directory names.

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string token = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {

                if (token == "" || token == ".") {
                    // ignore
                }
                else if (token == "..") {
                    if (!st.empty())
                        st.pop_back();
                }
                else {
                    st.push_back(token);
                }

                token = "";
            } 
            else {
                token += path[i];
            }
        }

        string result = "";
        for (string dir : st) {
            result += "/" + dir;
        }

        if (result == "")
            return "/";

        return result;
    }
};
```

---

## 🚀 What I Learned

* Handling **special directory symbols (`.` and `..`)**
* Using **stack-like structures to simulate directory traversal**
* Tokenizing strings based on delimiters
* Understanding **Unix path rules**

---

## 📌 Author

**Darshan Shete**
