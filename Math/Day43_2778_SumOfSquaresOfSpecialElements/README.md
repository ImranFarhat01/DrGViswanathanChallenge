\# 2778. Sum of Squares of Special Elements



🔗 \[View on LeetCode](https://leetcode.com/problems/sum-of-squares-of-special-elements/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 43



\## Problem

Given a 1-indexed integer array nums of length n, an element nums\[i] is special if i divides n (n % i == 0). Return the sum of the squares of all special elements.



\*\*Examples:\*\*

\- nums = \[1,2,3,4] → 21 (special elements are nums\[1], nums\[2], nums\[4], so 1 + 4 + 16)

\- nums = \[2,7,1,19,18,3] → 63 (special elements are nums\[1], nums\[2], nums\[3], nums\[6], so 4 + 49 + 1 + 9)



\*\*Constraints:\*\*

\- 1 <= nums.length == n <= 50

\- 1 <= nums\[i] <= 50



\## Approach

The problem uses 1-based positions, but C++ arrays are 0-based, so the element at 1-based position i lives at index i - 1. Loop over every index and test the 1-based position (i + 1) against n. Whenever n % (i + 1) == 0, add the square of that element to the running total.



Index 0 (position 1) is always special because 1 divides every n, so it is added before the loop starts and the loop begins from index 1.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over the array with a constant-time modulo check at each step

\- \*\*Space:\*\* O(1) - only a running total is used



\## Key Learning

The only real trap here is the off-by-one between the problem's 1-based indexing and the code's 0-based indexing, so the divisibility check has to use (i + 1) while the array access uses i. Adding index 0 separately works, but it is not required: since n % 1 == 0 is always true, the loop could simply start at i = 0 and the special case would disappear. The values stay tiny under these constraints (at most 50 \* 50 \* 50), so int is safe.

