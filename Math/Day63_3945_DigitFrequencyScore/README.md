# 3945. Digit Frequency Score

🔗 [View on LeetCode](https://leetcode.com/problems/digit-frequency-score/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 63

## Problem
Given an integer n, the score of n is the sum of d * freq(d) over all distinct digits d, where freq(d) is the number of times the digit d appears in n. Return the score of n.

**Examples:**
- n = 122 → 5 (digit 1 contributes 1 * 1 = 1, digit 2 contributes 2 * 2 = 4)
- n = 101 → 2 (digit 0 contributes 0, digit 1 contributes 1 * 2 = 2)

**Constraints:**
- 1 <= n <= 10^9

## Approach
Count how many times each digit from 0 to 9 appears. Peel off the last digit of n with n % 10, increase its count in a frequency array of size 10, then drop that digit with n /= 10, and repeat until n becomes 0. After that, loop over the digits 0 to 9 and add i * freq[i] to the answer.

## Complexity
- **Time:** O(log n) - one step per digit of n (at most 10), plus a fixed loop over 10 digits
- **Space:** O(1) - the frequency array has a fixed size of 10

## Key Learning
The formula is a disguise. Each digit d that appears freq(d) times adds d * freq(d), which is the same as adding d once for every occurrence. So the score is simply the sum of the digits of n, and the frequency array is not needed at all. A single loop that adds n % 10 to a running total gives the same answer in O(1) space with less code. The frequency version is still a good way to see the problem as stated, and the same counting pattern works when a problem asks about frequencies for real.
