Sliding Window Maximum (Leetcode 239)
🧠 Problem Summary

Given an array nums and a window size k,
har window ke liye maximum element return karna hai.

Example:

Input:  nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
🚀 Approach: Monotonic Deque (Optimal – O(n))
💡 Core Idea

Hum ek deque banayenge jo:

Elements ko decreasing order me store karega

Deque ka front hamesha maximum element hoga

Deque me hum indices store karenge, values nahi.

🔥 Step-by-Step Thinking Process
1️⃣ Deque Banayenge
deque<int> dq;

Ye indices store karega.

2️⃣ Har element ke liye 3 cheeze check karenge

For every index i:

✅ Step A: Remove Smaller Elements (Back se)

Jab naya element aaye:

Check karo kya deque ka back wala element current element se chota hai?

Agar chota hai → pop_back()

Yeh tab tak karo jab tak back bada na ho jaye

Reason:
Chote elements future me kabhi max nahi ban sakte.

✅ Step B: Current Element Push Karo
dq.push_back(i);

Ab deque decreasing order maintain karega.

✅ Step C: Window ke Bahar wale Elements Remove Karo

Check karo:

if (dq.front() == i - k)
    dq.pop_front();

Agar front window ka part nahi hai
(toh wo outdated hai), toh usko remove kar do.

3️⃣ Result Store Kab Karenge?

Jab first window complete ho jaye:

if (i >= k - 1)
    result.push_back(nums[dq.front()]);

Kyuki:

dq.front() hamesha max element ka index hai

Usko result me push kar denge

🧠 Why This Works?

Deque decreasing order maintain karta hai

Front always maximum hota hai

Har element ek hi baar push aur pop hota hai

⏱ Time Complexity:

O(n)

📦 Space Complexity:

O(k)