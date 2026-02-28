Valid Parentheses (Stack Problem)
🧠 Problem Statement

Given a string s containing only:

( ) { } [ ]

Check whether the string is valid.

✅ Valid String Rules:

Har opening bracket ka matching closing bracket hona chahiye.

Brackets correct order me close hone chahiye.

Har closing bracket ka ek corresponding opening bracket hona chahiye.

🔎 Example
Input:  "()"
Output: true

Input:  "()[]{}"
Output: true

Input:  "(]"
Output: false

Input:  "([)]"
Output: false

Input:  "{[]}"
Output: true
🚀 Approach: Stack
💡 Core Idea

Opening brackets ko stack me push karenge.

Closing bracket aaye toh check karenge:

Stack empty toh invalid.

Stack ka top matching opening bracket hona chahiye.

End me stack empty hona chahiye.

🔥 Step-by-Step Thinking
1️⃣ Stack Banayenge
stack<char> st;
2️⃣ String Traverse Karenge

For each character:

✅ Case 1: Opening Bracket
(  [  {

→ Stack me push kar do.

✅ Case 2: Closing Bracket
)  ]  }

Step-by-step:

Agar stack empty hai → return false

Check karo:

( matches )

{ matches }

[ matches ]

Agar match hai → pop karo

Agar match nahi → return false

3️⃣ Final Check

Loop ke baad:

Agar stack empty → valid string

Warna → invalid

⏱ Time & Space Complexity
Time Complexity:

O(n)
(Each character ek hi baar process hota hai)

Space Complexity:

O(n)