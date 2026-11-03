\# 3736. Minimum Moves to Equal Array Elements III



🔗 \[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 66



\## Problem

Given an integer array nums, in one move you may increase the value of any single element by 1. Return the minimum total number of moves required so that all elements become equal.



\*\*Examples:\*\*

\- nums = \[2,1,3] → 3 (raise 2 to 3 and raise 1 to 3, which takes 1 + 2 moves)

\- nums = \[4,4,5] → 2



\*\*Constraints:\*\*

\- 1 <= nums.length <= 100

\- 1 <= nums\[i] <= 100



\## Approach

Since elements can only be increased, no element can ever go below its current value. That means the common final value can never be smaller than the maximum element, and choosing the maximum itself is the cheapest option, because any larger target only adds extra moves for every element.



Each element x then needs (max - x) moves, and the total is the sum of (max - x) over all elements, which equals n \* max - sum. One pass finds the maximum and one pass adds up the elements.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass for the maximum and one for the sum

\- \*\*Space:\*\* O(1) - only a few variables



\## Key Learning

This is the easy sibling of #453, where a move incremented n - 1 elements at once and the target ended up being the minimum. Here a move touches a single element and can only go up, so the target is the maximum instead. The same formula shape shows up in both: total distance from the target equals n \* target - sum (or sum - n \* target when the target is the minimum). With n and the values both capped at 100, n \* max is at most 10^4, so int is safe here.

