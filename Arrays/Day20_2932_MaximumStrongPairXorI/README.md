\# 2932. Maximum Strong Pair XOR I



🔗 \[View on LeetCode](https://leetcode.com/problems/maximum-strong-pair-xor-i/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 20



\## Problem

Given a 0-indexed integer array nums, a pair (x, y) is a strong pair if |x - y| <= min(x, y). Select two integers from nums (the same integer can be picked twice) that form a strong pair and maximize their bitwise XOR. Return that maximum XOR value.



\*\*Examples:\*\*

\- nums = \[1,2,3,4,5] → 7 (from 3 XOR 4)

\- nums = \[10,100] → 0 (only strong pairs are (10,10) and (100,100), both XOR to 0)

\- nums = \[5,6,25,30] → 7 (from 25 XOR 30)



\*\*Constraints:\*\*

\- 1 <= nums.length <= 50

\- 1 <= nums\[i] <= 100



\## Approach

Given the small constraint (n <= 50), a brute-force check of every pair is feasible. Iterate over every pair (i, j) with j >= i (allowing i == j so the same element can pair with itself), check if the pair satisfies the strong pair condition |nums\[i] - nums\[j]| <= min(nums\[i], nums\[j]), and if so, compute its XOR and track the maximum found so far.



\## Complexity

\- \*\*Time:\*\* O(n^2) - checking every pair once, which is fine given n <= 50

\- \*\*Space:\*\* O(1) - only a running maximum tracked



\## Key Learning

With small constraints like n <= 50, brute force over all pairs is often the fastest path to a correct, submittable solution rather than reaching for a more complex approach upfront. This problem's constraints (n <= 50, values <= 100) are a strong signal that O(n^2) is intended, worth noticing constraint sizes as a hint toward the expected time complexity before over-engineering a solution.

