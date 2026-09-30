\# 1004. Max Consecutive Ones III



🔗 \[View on LeetCode](https://leetcode.com/problems/max-consecutive-ones-iii/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 32



\## Problem

Given a binary array nums and an integer k, return the maximum number of consecutive 1's achievable if at most k 0's in the array can be flipped to 1's.



\*\*Examples:\*\*

\- nums = \[1,1,1,0,0,0,1,1,1,1,0], k = 2 → 6

\- nums = \[0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3 → 10



\*\*Constraints:\*\*

\- 1 <= nums.length <= 10^5

\- nums\[i] is either 0 or 1

\- 0 <= k <= nums.length



\## Approach

Use a sliding window that expands to include as many elements as possible while tracking the number of zeros currently inside it. Expand the window by moving end forward, incrementing the zero count whenever a 0 is included. Whenever the zero count exceeds k (meaning more zeros than allowed flips are inside the window), shrink from the left by moving start forward until the zero count is back within the allowed limit. At every step, the window size (end - start + 1) represents a valid subarray where at most k zeros could be flipped to make it all 1's, so the maximum window size seen is the answer.



\## Complexity

\- \*\*Time:\*\* O(n) - both start and end pointers move forward at most n times total, no backtracking

\- \*\*Space:\*\* O(1) - only a few counters used



\## Key Learning

This is a classic "shrinking window on constraint violation" sliding window pattern: grow greedily, and only shrink when a specific constraint (here, zero count exceeding k) is broken. The window never needs to shrink below what's necessary, since start only ever moves forward, giving the overall O(n) guarantee despite the nested while loop, since it doesn't reset or run independently of the outer loop's progress.

