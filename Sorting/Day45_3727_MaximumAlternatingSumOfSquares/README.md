# 3727. Maximum Alternating Sum of Squares

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 45

## Problem
Given an integer array nums, you may rearrange its elements in any order. The alternating score of an array arr is arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + ... Return the maximum possible alternating score after rearranging.

**Examples:**
- nums = [1,2,3] → 12 (arrangement [2,1,3] gives 4 - 1 + 9)
- nums = [1,-1,2,-2,3,-3] → 16 (arrangement [-3,-1,-2,1,3,2] gives 9 - 1 + 4 - 1 + 9 - 4)

**Constraints:**
- 1 <= nums.length <= 10^5
- -4 * 10^4 <= nums[i] <= 4 * 10^4

## Approach
Squaring removes the sign, so only the magnitude of each element matters. Taking the absolute value of every element makes sorting by magnitude possible.

In any arrangement, the elements at even positions (0, 2, 4, ...) are added and the elements at odd positions are subtracted. There are ceil(n / 2) added positions and floor(n / 2) subtracted positions. To maximize the score, the largest squares should be added and the smallest squares should be subtracted.

So take absolute values, sort in descending order, add the squares of the first (n + 1) / 2 elements, and subtract the squares of the remaining elements.

## Complexity
- **Time:** O(n log n) - dominated by the sort
- **Space:** O(1) extra - the array is modified in place (sorting may use some internal stack space)

## Key Learning
The problem looks like it needs a clever arrangement, but the exact order does not matter. Only which elements land on an added position versus a subtracted position matters, and the number of each kind is fixed by n. That turns the problem into a plain greedy split after sorting. Two small details worth remembering: the absolute value step is what lets sorting by magnitude work, and the products must use 1LL because squares reach 1.6 * 10^9 and the running total across 10^5 elements is far beyond what an int can hold.
