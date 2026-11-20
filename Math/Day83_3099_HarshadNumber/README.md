\# 3099. Harshad Number



🔗 \[View on LeetCode](https://leetcode.com/problems/harshad-number/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 83



\## Problem

An integer that is divisible by the sum of its digits is called a Harshad number. Given an integer x, return the sum of the digits of x if x is a Harshad number, otherwise return -1.



\*\*Examples:\*\*

\- x = 18 → 9 (the digit sum is 9, and 18 is divisible by 9)

\- x = 23 → -1 (the digit sum is 5, and 23 is not divisible by 5)



\*\*Constraints:\*\*

\- 1 <= x <= 100



\## Approach

Compute the sum of the digits of x by repeatedly taking the last digit with % 10, adding it to a running sum, and dropping it with / 10. A copy of x is used for this, so the original value is still available afterward. Then check whether x is divisible by that digit sum. If it is, return the digit sum, and otherwise return -1.



\## Complexity

\- \*\*Time:\*\* O(log x) - one step per digit, and x has at most 3 digits here

\- \*\*Space:\*\* O(1) - only a few integer variables



\## Key Learning

The division x % sum is safe from a divide by zero error. Since x is at least 1, it has at least one nonzero digit, so the digit sum is always at least 1. That guarantee comes straight from the constraints, which is why no extra check is needed. The digit extraction loop is the same building block used in earlier problems, and keeping a copy of the original number is the small habit that lets you compare against it after the loop has used it up.

