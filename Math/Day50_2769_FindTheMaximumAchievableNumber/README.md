\# 2769. Find the Maximum Achievable Number



🔗 \[View on LeetCode](https://leetcode.com/problems/find-the-maximum-achievable-number/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 50



\## Problem

Given two integers num and t, a number x is achievable if it can become equal to num after applying the following operation at most t times: increase or decrease x by 1, and simultaneously increase or decrease num by 1. Return the maximum possible value of x.



\*\*Examples:\*\*

\- num = 4, t = 1 → 6 (decrease x by 1 and increase num by 1, so 6 - 1 = 5 and 4 + 1 = 5)

\- num = 3, t = 2 → 7



\*\*Constraints:\*\*

\- 1 <= num, t <= 50



\## Approach

To make x as large as possible while still being able to meet num, x has to come down and num has to go up. Each operation can decrease x by 1 and increase num by 1 at the same time, so the gap between them shrinks by 2 per operation.



With t operations, the gap can shrink by at most 2t. So the largest starting gap that can still be closed is 2t, which means the largest achievable x is num + 2t.



\## Complexity

\- \*\*Time:\*\* O(1) - a single arithmetic expression

\- \*\*Space:\*\* O(1) - no extra memory used



\## Key Learning

The operation moves both numbers at once, which is easy to misread as a gap that shrinks by 1. Moving them in opposite directions closes the gap by 2 per step, and that factor of 2 is the whole problem. Working through one small example by hand (num = 4, t = 1 gives 6) is the quickest way to confirm the formula before coding it.

