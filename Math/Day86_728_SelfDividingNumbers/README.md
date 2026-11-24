\# 728. Self Dividing Numbers



🔗 \[View on LeetCode](https://leetcode.com/problems/self-dividing-numbers/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 86



\## Problem

A self-dividing number is a number that is divisible by every digit it contains, and it is not allowed to contain the digit zero. For example, 128 is self-dividing because 128 % 1, 128 % 2 and 128 % 8 are all 0. Given two integers left and right, return a list of all the self-dividing numbers in the range \[left, right], both inclusive.



\*\*Examples:\*\*

\- left = 1, right = 22 → \[1,2,3,4,5,6,7,8,9,11,12,15,22]

\- left = 47, right = 85 → \[48,55,66,77]



\*\*Constraints:\*\*

\- 1 <= left <= right <= 10^4



\## Approach

Check every number in the range one by one. For each number i, peel off its digits with % 10 and / 10, working on a copy so that i itself stays available for the divisibility test. For every digit, the number fails if the digit is 0 or if i is not divisible by it. As soon as one digit fails, stop checking that number and move on. A number that passes every digit is added to the answer.



\## Complexity

\- \*\*Time:\*\* O((right - left + 1) \* d), where d is the number of digits per number. Since the values are at most 10^4, d is at most 5, so this is effectively linear in the size of the range

\- \*\*Space:\*\* O(1) extra, apart from the output list



\## Key Learning

The order of the condition matters: dig == 0 || i % dig != 0. The || short-circuits, so when the digit is 0 the modulo is never evaluated, which prevents a division by zero. The early break also saves work, because most numbers fail on their first or second digit. Keeping a separate copy (temp) for digit extraction is what lets the loop compare against the original number i at every step.

