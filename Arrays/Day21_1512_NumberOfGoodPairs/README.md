# 1512. Number of Good Pairs

🔗 [View on LeetCode](https://leetcode.com/problems/number-of-good-pairs/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 21

## Problem
Given an array of integers nums, return the number of good pairs. A pair (i, j) is good if nums[i] == nums[j] and i < j.

**Examples:**
- nums = [1,2,3,1,1,3] → 4
- nums = [1,1,1,1] → 6 (every pair is good)
- nums = [1,2,3] → 0

**Constraints:**
- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Approach
With small constraints (n <= 100), a brute-force double loop checking every pair (i, j) is fast enough. For each pair where nums[i] equals nums[j] and i is strictly less than j, increment the count.

## Complexity
- **Time:** O(n^2) - checking every pair of indices
- **Space:** O(1) - only a counter used

## Key Learning
This brute-force approach works fine given the small constraint, but a frequency-map approach would be more scalable: count occurrences of each value first, then for any value appearing k times, it contributes k*(k-1)/2 good pairs (choosing 2 out of k identical elements). That approach runs in O(n) instead of O(n^2), worth using if the constraint were larger, but not strictly necessary here.
