# 2897. Apply Operations on Array to Maximize Sum of Squares

🔗 [View on LeetCode](https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/)

- **Platform:** LeetCode
- **Difficulty:** Hard
- **Day:** 44

## Problem
Given a 0-indexed integer array nums and a positive integer k, you can repeat this operation any number of times: pick two distinct indices i and j and simultaneously set nums[i] to (nums[i] AND nums[j]) and nums[j] to (nums[i] OR nums[j]). After the operations, choose k elements from the final array and compute the sum of their squares. Return the maximum possible sum of squares modulo 10^9 + 7.

**Examples:**
- nums = [2,6,5,8], k = 2 → 261 (final array can be [0,6,0,15], choosing 15 and 6)
- nums = [4,5,4,7], k = 3 → 90 (no operations needed, choose 7, 5 and 4)

**Constraints:**
- 1 <= k <= nums.length <= 10^5
- 1 <= nums[i] <= 10^9

## Approach
Look at one bit position at a time. When the operation is applied to two numbers, a bit that both numbers have stays in both, a bit that neither has stays in neither, and a bit that exactly one of them has simply moves to the OR position. So for every bit, the number of elements that have it set never changes, but those set bits can be moved around between elements freely.

Squaring rewards unequal numbers (the function is convex), so the best strategy is to pack the bits into as few elements as possible. Count how many numbers have each bit set, then build the k chosen numbers greedily: for each pick, take one copy of every bit that still has a remaining count, combine them into one number, square it, and add it to the answer modulo 10^9 + 7. The first number collects every available bit, the second collects every bit that appeared at least twice, and so on.

## Complexity
- **Time:** O(32 * (n + k)), which is O(n) since k <= n and 32 is a constant (one pass to count bits, then k passes over 32 bit positions)
- **Space:** O(1) - a fixed array of 32 counters

## Key Learning
The operation looks complicated, but the key is finding what it keeps unchanged. The per-bit counts are invariant, so the problem reduces to redistributing a fixed pool of bits to maximize a convex function, and the answer for convex objectives is to concentrate the bits. A few implementation details worth remembering: values are at most 10^9, so only bits 0 to 29 are ever set, and curr stays below 2^30, which means curr * curr fits in a long long before taking the modulo. Using 1LL << b instead of 1 << b would be a safer habit for loops that run up to bit 31.
