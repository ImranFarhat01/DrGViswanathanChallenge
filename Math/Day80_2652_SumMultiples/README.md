# 2652. Sum Multiples

🔗 [View on LeetCode](https://leetcode.com/problems/sum-multiples/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 80

## Problem
Given a positive integer n, find the sum of all integers in the range [1, n] that are divisible by 3, 5, or 7, and return that sum.

**Examples:**
- n = 7 → 21 (the numbers are 3, 5, 6, 7)
- n = 10 → 40 (the numbers are 3, 5, 6, 7, 9, 10)
- n = 9 → 30 (the numbers are 3, 5, 6, 7, 9)

**Constraints:**
- 1 <= n <= 10^3

## Approach
Go through every number from 1 to n. If a number is divisible by 3, by 5, or by 7, add it to the running total. Using a single condition with || means a number such as 15, which is divisible by both 3 and 5, is added only once.

## Complexity
- **Time:** O(n) - one pass over the range
- **Space:** O(1) - only a running total

## Key Learning
The || in the condition is what prevents double counting. Adding the multiples of 3, 5 and 7 separately would count numbers like 15 and 21 more than once. The O(1) version fixes this with inclusion and exclusion. The sum of all multiples of k up to n is k * m * (m + 1) / 2 where m = n / k. Add that for 3, 5 and 7, subtract it for 15, 21 and 35 (the numbers counted twice), then add it back for 105 (the number counted three times, and then removed three times). Check with n = 10: 18 + 15 + 7 = 40, and every correction term is 0. With n at most 1000, the largest sum is below 500,500, so int is safe either way.<img width="1917" height="856" alt="image" src="https://github.com/user-attachments/assets/316bcc42-35b0-48c7-8dd0-e6688c0cc411" />
