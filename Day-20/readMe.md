# Container With Most Water (LeetCode 11)
📝 Problem Statement

You are given an integer array height where each element represents the height of a vertical line drawn at that index.

Find two lines that together with the x-axis form a container such that the container holds the maximum amount of water.

Return the maximum amount of water a container can store.

Initial Thought (Brute Force Approach)

First idea:

Use two nested loops.

Pick every pair (i, j).

Calculate area using:

width = j - i
height = min(height[i], height[j])
area = width * height


Store maximum area.

❌ Time Complexity:

O(n²) — Not efficient for large inputs.

🚀 Optimized Approach — Two Pointer Technique

Instead of checking every pair, we use a two-pointer greedy approach.

🔹 Key Formula
Area = (right - left) * min(height[left], height[right])


To maximize area:

We want large width

And large minimum height

🧠 Algorithm

Initialize:

left = 0
right = n - 1
maxArea = 0


While left < right:

Calculate:

width = right - left
height = min(height[left], height[right])
area = width * height


Update maximum area.

Move the pointer with smaller height:

If height[left] < height[right] → left++

Else → right--

