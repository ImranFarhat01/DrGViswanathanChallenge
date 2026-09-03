# 3876. Construct Uniform Parity Array II

🔗 [View on LeetCode](https://leetcode.com/problems/construct-uniform-parity-array-ii/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 5

## Problem
You are given an array `nums1` of `n` distinct integers.

You need to construct another array `nums2` of the same length such that all elements in `nums2` are either **all odd or all even**.

For each index `i`, you can choose exactly one of the following:

- `nums2[i] = nums1[i]`
- `nums2[i] = nums1[i] - nums1[j]`, where `j != i` and `nums1[i] - nums1[j] >= 1`

Return `true` if it is possible to construct such an array, otherwise return `false`.

**Examples:**
- `nums1 = [1,4,7]` → `true`
- `nums1 = [2,3]` → `false`
- `nums1 = [4,6]` → `true`

**Constraints:**
- `1 <= n == nums1.length <= 10^5`
- `1 <= nums1[i] <= 10^9`
- `nums1` consists of distinct integers

## Approach
The key observation is based on **parity**.

When subtracting two numbers:

- Even - Odd = Odd
- Odd - Even = Odd
- Even - Even = Even
- Odd - Odd = Even

If there are no odd elements, then all elements are already even, so the answer is `true`.

Otherwise, let `minOdd` be the smallest odd element and `minEven` be the smallest even element.

For an even element to be converted into an odd value, we need to subtract a smaller odd element from it. The smallest odd element gives us the best possible chance of doing this.

Therefore, all even elements can be converted into positive odd values if and only if:

`minEven > minOdd`

So, we only need one traversal of the array to find the minimum odd and even values.

## Complexity
- **Time:** O(n) - single pass through the array
- **Space:** O(1) - only two variables are used

## Key Learning
The main insight is that we do not need to actually construct `nums2` or try different choices of `j`.

By focusing on **parity** and tracking the smallest odd and even values, the problem can be reduced to a simple condition: `minEven > minOdd`.

This is a good example of how identifying a mathematical property can turn a seemingly complicated construction problem into a simple one-pass solution.
