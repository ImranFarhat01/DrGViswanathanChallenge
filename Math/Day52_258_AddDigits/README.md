\# 258. Add Digits



🔗 \[View on LeetCode](https://leetcode.com/problems/add-digits/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 52



\## Problem

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.



\*\*Examples:\*\*

\- num = 38 → 2 (38 → 3 + 8 = 11 → 1 + 1 = 2)

\- num = 0 → 0



\*\*Constraints:\*\*

\- 0 <= num <= 2^31 - 1



\*\*Follow-up:\*\* Can it be done without any loop or recursion in O(1) time?



\## Approach

Write a helper, sumDig, that returns the sum of the digits of a number by repeatedly taking num % 10 for the last digit and num / 10 to drop it. Then keep replacing num with its digit sum for as long as num has more than one digit, which is checked with num / 10 > 0. When the loop ends, num is a single digit and is returned.



\## Complexity

\- \*\*Time:\*\* O(log n) - the first digit sum costs one step per digit (at most 10 digits for a 32-bit int), and the number shrinks so fast that only a handful of rounds are ever needed

\- \*\*Space:\*\* O(1) - only a few integer variables



\## Key Learning

The follow-up has a closed form. The result of repeatedly adding digits is called the digital root, and it follows from the fact that a number and its digit sum leave the same remainder when divided by 9. So for num > 0 the answer is 1 + (num - 1) % 9, and for num = 0 the answer is 0. That solves the problem in O(1) time with no loops or recursion. The loop version is still a good first solution because it follows the problem statement directly, and the formula is a nice example of how simulation problems can hide a number theory shortcut.

