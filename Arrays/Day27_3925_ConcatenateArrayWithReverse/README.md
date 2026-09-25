# 3925. Concatenate Array With Reverse

🔗 [View on LeetCode](https://leetcode.com/problems/concatenate-array-with-reverse/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 27

## Problem
Given an integer array nums of length n, construct a new array ans of length 2n such that the first n elements are the same as nums, and the next n elements are nums in reverse order.

**Examples:**
- nums = [1,2,3] → [1,2,3,3,2,1]
- nums = [1] → [1,1]

**Constraints:**
- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Approach
Create a result array of size 2n. Fill the first n positions directly by copying nums in order. Then fill the remaining n positions by walking through nums backward (from the last element to the first) and appending each one to the result array using a separate running index.

## Complexity
- **Time:** O(n) - two linear passes over nums, one forward and one backward
- **Space:** O(n) for the output array (required by the problem, since the result itself has size 2n)

## Key Learning
A straightforward two-pass construction, filling the first half and second half of the result separately, is often clearer than trying to compute both halves in a single combined loop. Since ans[i] and ans[i+n] follow different index patterns (direct copy vs reverse copy), keeping them as two distinct loops avoids unnecessary complexity in the indexing logic.
