# 3723. Maximize Sum of Squares of Digits

🔗 [View on LeetCode](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 46

## Problem
Given two positive integers num and sum, a positive integer n is good if it has exactly num digits and its digits add up to exactly sum. The score of n is the sum of the squares of its digits. Return the good integer with the maximum score as a string. If several good integers share the maximum score, return the largest one. If no good integer exists, return an empty string.

**Examples:**
- num = 2, sum = 3 → "30" (good integers are 12, 21, 30, and 30 has the best score of 9)
- num = 2, sum = 17 → "98" (89 and 98 tie on score, and 98 is larger)
- num = 1, sum = 10 → "" (no 1-digit number has digits summing to 10)

**Constraints:**
- 1 <= num <= 2 * 10^5
- 1 <= sum <= 2 * 10^6

## Approach
Squaring rewards unequal digits, so to maximize the sum of squares the digit sum should be packed into as few large digits as possible. That means using as many 9s as possible, then one leftover digit, then zeros.

Build the answer from left to right. At each position, place min(9, remaining sum) and subtract it from the remaining sum. This puts the 9s first, then the leftover digit, then zeros. Putting the largest digits on the left also makes the number itself as large as possible among the tied options, which satisfies the tie-break rule.

If the sum is larger than 9 * num, no valid number exists, so return an empty string. The final check on the remaining sum is a second safety net for the same case.

## Complexity
- **Time:** O(num) - one pass to build the digit string
- **Space:** O(num) - for the output string

## Key Learning
Maximizing a sum of squares under a fixed total is a classic case where concentrating the value wins, since the square function grows faster for larger digits. The same greedy that maximizes the score also gives the largest number, because the big digits sit at the front. A small lesson from my own submission: the first guard condition originally compared num with 9 * num, which is never true, and the solution only passed because a later check covered the same case. Redundant checks can hide typos like this, so it is worth re-reading guard conditions even when the tests pass.
