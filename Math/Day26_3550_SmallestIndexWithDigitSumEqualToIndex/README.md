\# 3550. Smallest Index With Digit Sum Equal to Index



🔗 \[View on LeetCode](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 26



\## Problem

Given an integer array nums, return the smallest index i such that the sum of the digits of nums\[i] equals i. If no such index exists, return -1.



\*\*Examples:\*\*

\- nums = \[1,3,2] → 2 (digit sum of nums\[2]=2 is 2, matches index 2)

\- nums = \[1,10,11] → 1 (digit sum of nums\[1]=10 is 1, matches index 1, the smallest valid one)

\- nums = \[1,2,3] → -1



\*\*Constraints:\*\*

\- 1 <= nums.length <= 100

\- 0 <= nums\[i] <= 1000



\## Approach

Walk through the array from left to right, computing the digit sum of each element using the standard modulo-and-divide extraction. As soon as an index i is found where the digit sum equals i, return it immediately, since scanning left to right guarantees the first match found is the smallest valid index. If no index satisfies the condition by the end of the loop, return -1.



\## Complexity

\- \*\*Time:\*\* O(n \* d), where n is the array length and d is the (small, constant-bounded) number of digits per element, since nums\[i] <= 1000 means at most 4 digits

\- \*\*Space:\*\* O(1) - only a couple of counters used



\## Key Learning

When looking for the "smallest index satisfying a condition," scanning left to right and returning on the first match is both correct and simpler than computing all valid indices and then taking the minimum, no need to store anything extra or compare candidates afterward. Also worth noting: the edge case where nums\[i] = 0 is handled correctly here, since the while loop simply doesn't execute and sum stays at its initialized value of 0, matching correctly when i = 0.

