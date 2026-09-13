\# 3258. Count Substrings That Satisfy K-Constraint I



🔗 \[View on LeetCode](https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 15



\## Problem

Given a binary string s and an integer k, a substring satisfies the k-constraint if the count of 0's in it is at most k, or the count of 1's in it is at most k. Return the total number of substrings of s that satisfy the k-constraint.



\*\*Examples:\*\*

\- s = "10101", k = 1 → 12

\- s = "1010101", k = 2 → 25

\- s = "11111", k = 1 → 15 (all substrings qualify)



\*\*Constraints:\*\*

\- 1 <= s.length <= 50

\- 1 <= k <= s.length

\- s\[i] is either '0' or '1'



\## Approach

Use a sliding window with two pointers, l and r. Expand the window by moving r forward one step at a time. Whenever the current window (from l to r) violates the k-constraint, shrink it from the left by moving l forward until the constraint is satisfied again.



The key insight: once the window from l to r satisfies the constraint, every substring ending at r and starting anywhere from l to r also satisfies it (since shrinking from the right side can only reduce the counts further). So instead of counting one substring at a time, add r - l + 1 to the total at each step, which is the number of valid substrings ending exactly at position r.



\## Complexity

\- \*\*Time:\*\* O(n) amortized, since l only ever moves forward and never resets, giving a total of O(n) movements across the whole algorithm, even though the check function itself scans from l to r

\- \*\*Space:\*\* O(1) - only a few counters used



\## Key Learning

When a window satisfies a condition, every shorter window ending at the same right boundary also satisfies it. This lets a single sliding window pass count all valid substrings ending at each position in one shot (r - l + 1 of them), rather than checking every possible substring individually, which would be quadratic.

