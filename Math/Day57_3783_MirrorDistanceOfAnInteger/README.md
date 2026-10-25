# 3783. Mirror Distance of an Integer

🔗 [View on LeetCode](https://leetcode.com/problems/mirror-distance-of-an-integer/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 57

## Problem
Given an integer n, its mirror distance is abs(n - reverse(n)), where reverse(n) is the integer formed by reversing the digits of n. Return the mirror distance of n.

**Examples:**
- n = 25 → 27 (reverse is 52, and abs(25 - 52) = 27)
- n = 10 → 9 (reverse is 01, which is 1, and abs(10 - 1) = 9)
- n = 7 → 0

**Constraints:**
- 1 <= n <= 10^9

## Approach
Build the reversed number one digit at a time. Take the last digit of the remaining number with % 10, append it to the reversed number by multiplying the reversed number by 10 and adding the digit, then drop the last digit with / 10. Repeat until nothing is left. Trailing zeros in n become leading zeros in the reverse, and they vanish on their own because multiplying 0 by 10 keeps it at 0, which handles the n = 10 example automatically. Finally return the absolute difference between n and its reverse.

## Complexity
- **Time:** O(log n) - one step per digit, at most 10 steps
- **Space:** O(1) - only a few integer variables

## Key Learning
Reversing an integer with modulo and division is a building block for palindrome checks, digit sums and many other digit problems. The usual worry is overflow, since the reverse of a large number can exceed the int range. Here it is safe: the only 10-digit input allowed is exactly 10^9, whose reverse is 1, and every other input has at most 9 digits, so its reverse stays below 10^9.
