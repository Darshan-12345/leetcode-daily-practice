# longest Repeating charater replacemnt in this question
#### we have given k and string s and string is conating A to Z charter Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
 
- for this question we using sliding window and two pointer approch making a substring using two pointers left and right left start from 0 and rigt start from 0 and make also max_len and max_freq of char
- after that we check k is use full for our substring suppose our window is k is less than equal to our value and value is total windo size - max_freq is this condtion is satispy then we update our max_len to prev max_len and max_freq+val else move left and subtract left char from freq array and lastly right ++
- and outside of loop check one condtion if k == 0  and max_freq is 0 then return 1 beacause in this case our max_len is chanege but char also exist there since we rwrite one
- else return our max_len