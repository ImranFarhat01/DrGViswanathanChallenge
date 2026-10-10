# 2333. Minimum Sum of Squared Difference

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 42

## Problem
Given two positive integer arrays nums1 and nums2 of length n, the sum of squared difference is the sum of (nums1[i] - nums2[i])^2 over all i. You may change any element of nums1 by +1 or -1 at most k1 times in total, and any element of nums2 by +1 or -1 at most k2 times in total. Return the minimum possible sum of squared difference. Elements are allowed to become negative.

**Examples:**
- nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0 → 579
- nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1 → 43

**Constraints:**
- n == nums1.length == nums2.length
- 1 <= n <= 10^5
- 0 <= nums1[i], nums2[i] <= 10^5
- 0 <= k1, k2 <= 10^9

## Approach
Only the absolute difference d = |nums1[i] - nums2[i]| at each index matters. Changing either array by 1 at that index changes d by exactly 1, so the two budgets can be merged into a single budget k = k1 + k2 of "reduce some difference by 1" operations.

Because squaring is convex, reducing a larger difference saves more than reducing a smaller one (going from d to d-1 saves 2d-1). So the greedy choice is to always spend operations on the largest differences first.

Since every difference is at most 10^5, store a count array where countDiff[d] is how many indices have difference d. Then sweep from the largest value down to 1. At each level, move as many indices as the remaining budget allows from level d to level d-1, and subtract that many operations from k. Once k hits 0, stop. Finally, sum countDiff[d] * d * d over all levels.

## Complexity
- **Time:** O(n + M), where M = 10^5 is the maximum possible difference (one pass to count, one sweep over the value range, one pass to sum)
- **Space:** O(M) for the count array

## Key Learning
When the values live in a small bounded range, a counting array lets you process "all elements at the same level" in one step instead of handling elements one by one, which avoids a heap or a sort. Two details are worth remembering here. The total budget k1 + k2 can reach 2 * 10^9, which still fits in a 32-bit int but would not if the limits were any larger. The answer itself can reach roughly 10^15, so the final sum must use long long, and the multiplication has to be done with a long long operand to avoid overflow.
