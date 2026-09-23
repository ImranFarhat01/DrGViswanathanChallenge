\# 3467. Transform Array by Parity



🔗 \[View on LeetCode](https://leetcode.com/problems/transform-array-by-parity/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 25



\## Problem

Given an integer array nums, transform it by: replacing every even number with 0, replacing every odd number with 1, then sorting the resulting array in non-decreasing order. Return the resulting array.



\*\*Examples:\*\*

\- nums = \[4,3,2,1] → \[0,0,1,1]

\- nums = \[1,5,1,4,2] → \[0,0,1,1,1]



\*\*Constraints:\*\*

\- 1 <= nums.length <= 100

\- 1 <= nums\[i] <= 1000



\## Approach

Walk through the array once, replacing each element with 0 if it's even or 1 if it's odd. Since the array only ever contains 0s and 1s after this pass, sort it using the standard library sort to arrange all 0s before all 1s.



\## Complexity

\- \*\*Time:\*\* O(n log n) - dominated by the sort step, even though the transformation pass itself is O(n)

\- \*\*Space:\*\* O(1) extra - the transformation is done in place (aside from whatever space the sort implementation itself uses internally)



\## Key Learning

Since the array only ever holds two distinct values (0 and 1) after the transformation, a full comparison-based sort is actually overkill. A counting-based approach (count the 0s and 1s, then rebuild the array by placing all counted 0s followed by all counted 1s) would bring this down to O(n) instead of O(n log n), a classic instance of the Dutch National Flag style problem where sorting an array with a small fixed set of distinct values doesn't need a general-purpose sort.

