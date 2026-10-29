\# 2894. Divisible and Non-divisible Sums Difference



🔗 \[View on LeetCode](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 61



\## Problem

Given positive integers n and m, let num1 be the sum of all integers in \[1, n] that are not divisible by m, and num2 be the sum of all integers in \[1, n] that are divisible by m. Return num1 - num2.



\*\*Examples:\*\*

\- n = 10, m = 3 → 19 (num1 = 37, num2 = 18)

\- n = 5, m = 6 → 15 (no number is divisible by 6, so num2 = 0)

\- n = 5, m = 1 → -15 (every number is divisible by 1, so num1 = 0)



\*\*Constraints:\*\*

\- 1 <= n, m <= 1000



\## Approach

Go through every integer from 1 to n. If it is divisible by m (i % m == 0), add it to num2, otherwise add it to num1. At the end, return num1 - num2.



\## Complexity

\- \*\*Time:\*\* O(n) - a single pass over the range

\- \*\*Space:\*\* O(1) - only two running sums



\## Key Learning

There is an O(1) formula behind this. The sum of 1 to n is n(n+1)/2. The multiples of m up to n are m, 2m, ..., km where k = n / m, and their sum is m \* k(k+1)/2, which is num2. Since num1 = total - num2, the answer is total - 2 \* num2. Check with n = 10, m = 3: total = 55, k = 3, num2 = 3 \* 6 = 18, and 55 - 36 = 19. With n and m at most 1000, the sums stay below 500500, so int is safe either way.

