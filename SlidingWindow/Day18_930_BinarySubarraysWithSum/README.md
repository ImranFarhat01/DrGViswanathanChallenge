\# 930. Binary Subarrays With Sum



🔗 \[View on LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 18



\## Problem

Given a binary array nums and an integer goal, return the number of non-empty subarrays with sum equal to goal.



\*\*Examples:\*\*

\- nums = \[1,0,1,0,1], goal = 2 → 4

\- nums = \[0,0,0,0,0], goal = 0 → 15



\*\*Constraints:\*\*

\- 1 <= nums.length <= 3 \* 10^4

\- nums\[i] is either 0 or 1

\- 0 <= goal <= nums.length



\## Approach

This follows the same "exactly = atMost(k) - atMost(k-1)" pattern used for counting subarrays with an exact odd count. The numSubarr() helper is a standard sliding window that counts subarrays with sum at most a given goal: expand with r, shrink from the left whenever the running sum exceeds the goal, and add r - l + 1 valid subarrays at each step.



The special case is goal == 0. Since atMost(-1) isn't meaningful (a subarray sum can never be negative, so atMost(-1) should be treated as 0, not computed by actually calling numSubarr with -1), goal == 0 is handled directly by just calling numSubarr(nums, 0) instead of subtracting an atMost(-1) call that the helper isn't designed to handle correctly.



\## Complexity

\- \*\*Time:\*\* O(n) - numSubarr() is O(n) since l only moves forward, and it's called at most twice

\- \*\*Space:\*\* O(1) - only a few counters used



\## Key Learning

The atMost(k) - atMost(k-1) trick has an edge case at k = 0, since atMost(-1) should conceptually be 0 but isn't safe to compute directly if the helper function wasn't written to handle negative goals. Recognizing and special-casing the boundary of a reusable pattern, rather than assuming it generalizes perfectly to every edge, is what separates a working solution from one that silently breaks on edge cases like an all-zero array with goal = 0.



