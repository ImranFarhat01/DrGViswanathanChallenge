# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

🔗 [View on LeetCode](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 49

## Problem
A decimal number is deci-binary if each of its digits is either 0 or 1 and it has no leading zeros (for example 101 and 1100). Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

**Examples:**
- n = "32" → 3 (10 + 11 + 11 = 32)
- n = "82734" → 8
- n = "27346209830709182346" → 9

**Constraints:**
- 1 <= n.length <= 10^5
- n consists of only digits
- n has no leading zeros and represents a positive integer

## Approach
Each deci-binary number contributes at most 1 to any single digit position. So to build a digit d at some position, at least d numbers must have a 1 in that position. The digit with the largest value therefore forces at least that many numbers, and the answer can never be smaller than the maximum digit.

That lower bound is also enough. With max digit m, use m numbers, and for each position put a 1 in exactly d of them, where d is that position's digit. Every position then sums correctly, and no number is wasted. So the answer is simply the maximum digit of n.

## Complexity
- **Time:** O(n) - one pass over the digits
- **Space:** O(1) - a single variable for the maximum

## Key Learning
The problem sounds like a partitioning or search problem, but it collapses into one observation: each digit position is independent, and the position with the largest digit decides everything. The input can be 10^5 digits long, so the string cannot be converted into an integer anyway, and the digit-wise reasoning is what makes the problem solvable. One small optimization is possible: once a 9 is found, the loop can stop early, since no digit can be larger.
