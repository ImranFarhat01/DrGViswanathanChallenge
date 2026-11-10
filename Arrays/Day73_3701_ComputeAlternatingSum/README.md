\# 3701. Compute Alternating Sum



🔗 \[View on LeetCode](https://leetcode.com/problems/compute-alternating-sum/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 73



\## Problem

Given an integer array nums, the alternating sum is the value obtained by adding the elements at even indices and subtracting the elements at odd indices, that is nums\[0] - nums\[1] + nums\[2] - nums\[3] and so on. Return the alternating sum of nums.



\*\*Examples:\*\*

\- nums = \[1,3,5,7] → -4 (1 - 3 + 5 - 7)

\- nums = \[100] → 100 (there are no odd indices to subtract)



\*\*Constraints:\*\*

\- 1 <= nums.length <= 100

\- 1 <= nums\[i] <= 100



\## Approach

Walk through the array once and look at the parity of each index. If the index is even, add the element to the running total, and if it is odd, subtract it. The total after the last element is the answer.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over the array

\- \*\*Space:\*\* O(1) - only a running total



\## Key Learning

The rule depends on the index, not on the value, so index parity is all that is needed. The branch can also be replaced by a sign variable that flips after every element (sign = -sign), which avoids the modulo check. With n and the values both capped at 100, the largest possible magnitude is 5000, so int is safe.

