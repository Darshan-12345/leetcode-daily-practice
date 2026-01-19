# Product of Array Except Self

## Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

### Constraints

* `2 <= nums.length <= 10^5`
* `-30 <= nums[i] <= 30`
* Product of any prefix or suffix fits in a 32-bit integer
* Division operation is **not allowed**

---

## Approach 1: Prefix and Suffix Arrays

### Idea

For every index `i`:

* Compute the product of all elements **before** index `i` (prefix product)
* Compute the product of all elements **after** index `i` (suffix product)
* Multiply both to get the final answer for index `i`

### Steps

1. Create a `prefix` array where:

   * `prefix[i] = nums[0] * nums[1] * ... * nums[i-1]`
2. Create a `suffix` array where:

   * `suffix[i] = nums[i+1] * nums[i+2] * ... * nums[n-1]`
3. Final result:

   * `ans[i] = prefix[i] * suffix[i]`

### Complexity

* **Time:** O(n)
* **Space:** O(n) (extra prefix and suffix arrays)

### Pros

* Easy to understand
* Very clear logic

### Cons

* Uses extra space

---

## Approach 2: Optimized Space (O(1) Extra Space)

### Key Observation

The output array does **not** count as extra space. So we can reuse it to store prefix products and compute suffix products on the fly.

### Idea

1. Store prefix products directly in the `ans` array
2. Traverse from the right using a single variable `rightProduct` to keep track of suffix product
3. Multiply prefix and suffix values to get the final answer

### Steps

1. Initialize `ans[0] = 1`
2. Fill `ans[i]` with prefix product:

   ```cpp
   ans[i] = nums[i-1] * ans[i-1];
   ```
3. Initialize `rightProduct = 1`
4. Traverse from right to left:

   * `ans[i] *= rightProduct`
   * `rightProduct *= nums[i]`

### Complexity

* **Time:** O(n)
* **Extra Space:** O(1)

### Why This Works

* Prefix products are already stored in `ans`
* Suffix products are calculated dynamically
* No division and no extra arrays are used

---

## Example

Input:

```
nums = [1, 2, 3, 4]
```

Output:

```
[24, 12, 8, 6]
```

---

## Conclusion

* First approach is great for learning and clarity
* Second approach is **interview-optimized** and space-efficient
* Both run in O(n) time without using division

✅ Recommended approach for interviews: **Optimized O(1) space solution**
