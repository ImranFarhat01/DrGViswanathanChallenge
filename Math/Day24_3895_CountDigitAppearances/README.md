# 3895. Count Digit Appearances

🔗 [View on LeetCode](https://leetcode.com/problems/count-digit-appearances/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 24

## Problem
Given an integer array nums and an integer digit, return the total number of times digit appears in the decimal representation of all elements in nums.

**Examples:**
- nums = [12,54,32,22], digit = 2 → 4 (2 appears once in 12, once in 32, twice in 22)
- nums = [1,34,7], digit = 9 → 0

**Constraints:**
- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 10^6
- 0 <= digit <= 9

## Approach
For each number in nums, extract its digits one at a time using the standard modulo-and-divide technique: num % 10 gives the last digit, and num /= 10 removes it. Check if the extracted digit matches the target digit, and if so, increment the count. Repeat until the number is fully broken down to zero.

## Complexity
- **Time:** O(n * d), where n is the length of nums and d is the average number of digits per number (bounded by a small constant, since nums[i] <= 10^6 means at most 7 digits)
- **Space:** O(1) - only a running counter used

## Key Learning
Digit extraction via repeated modulo and division is a fundamental building block for a whole class of problems (digit sums, digit counts, palindrome checks on numbers, and so on). Since the digit count per number is bounded by a small constant regardless of n, this pattern is effectively linear in the size of the input array.
