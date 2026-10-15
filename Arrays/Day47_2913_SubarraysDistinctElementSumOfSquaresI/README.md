\# 2913. Subarrays Distinct Element Sum of Squares I



🔗 \[View on LeetCode](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 47



\## Problem

Given a 0-indexed integer array nums, the distinct count of a subarray is the number of distinct values in it. Return the sum of the squares of the distinct counts of all subarrays of nums.



\*\*Examples:\*\*

\- nums = \[1,2,1] → 15 (the six subarrays have distinct counts 1, 1, 1, 2, 2, 2, so 1 + 1 + 1 + 4 + 4 + 4)

\- nums = \[1,1] → 3 (all three subarrays have distinct count 1)



\*\*Constraints:\*\*

\- 1 <= nums.length <= 100

\- 1 <= nums\[i] <= 100



\## Approach

With n at most 100, checking every subarray is fast enough. Fix the starting index i, then extend the end index j one step at a time. Because every value is at most 100, a frequency array of size 101 can track which values are already in the current subarray.



When nums\[j] is added, its frequency goes from 0 to 1 exactly when it is a new distinct value, so the running distinct count increases by one at that moment. After each extension, the current distinct count is the distinct count of nums\[i..j], so its square is added to the answer. A fresh frequency array and a fresh count are created for every new starting index.



\## Complexity

\- \*\*Time:\*\* O(n^2) - there are about n^2 / 2 subarrays, each handled with O(1) array work, plus O(101) to create the frequency array for each of the n starting points

\- \*\*Space:\*\* O(1) - the frequency array has a fixed size of 101 regardless of n



\## Key Learning

When the values live in a small known range, a frequency array beats a hash set: lookups are direct array accesses with no hashing, and the space becomes constant. The check freq\[x]++ == 0 detects a brand new value and updates the count in a single step. The largest possible answer is about 5050 \* 100^2 = 5 \* 10^7, so int is safe here. The harder version of this problem has n up to 10^5, where this approach is too slow and a contribution-based technique with a segment tree is needed.

