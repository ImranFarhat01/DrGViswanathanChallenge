\# 1929. Concatenation of Array



🔗 \[View on LeetCode](https://leetcode.com/problems/concatenation-of-array/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 28



\## Problem

Given an integer array nums of length n, create an array ans of length 2n where ans\[i] == nums\[i] and ans\[i + n] == nums\[i] for 0 <= i < n. In other words, ans is nums concatenated with itself. Return ans.



\*\*Examples:\*\*

\- nums = \[1,2,1] → \[1,2,1,1,2,1]

\- nums = \[1,3,2,1] → \[1,3,2,1,1,3,2,1]



\*\*Constraints:\*\*

\- n == nums.length

\- 1 <= n <= 1000

\- 1 <= nums\[i] <= 1000



\## Approach

Create a result array of size 2n. In a single pass over nums, place each element at its normal position i and simultaneously at its mirrored position i + n. This fills both halves of the result array in one loop instead of two separate passes.



\## Complexity

\- \*\*Time:\*\* O(n) - single pass over nums

\- \*\*Space:\*\* O(n) for the output array (required, since the result itself has size 2n)



\## Key Learning

Unlike yesterday's problem (Concatenate Array With Reverse), where the two halves followed different index patterns and were cleaner to fill in two separate loops, here both halves use the exact same source value (nums\[i]) just at two different destination positions. This makes a single combined loop the more natural fit, filling ans\[i] and ans\[i+n] together, since there's no extra complexity introduced by combining them.

