\# 1920. Build Array from Permutation



🔗 \[View on LeetCode](https://leetcode.com/problems/build-array-from-permutation/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 84



\## Problem

Given a zero-based permutation nums (an array of distinct integers from 0 to nums.length - 1), build an array ans of the same length where ans\[i] = nums\[nums\[i]] for every index i, and return it.



\*\*Examples:\*\*

\- nums = \[0,2,1,5,3,4] → \[0,1,2,4,5,3]

\- nums = \[5,0,1,2,3,4] → \[4,5,0,1,2,3]



\*\*Constraints:\*\*

\- 1 <= nums.length <= 1000

\- 0 <= nums\[i] < nums.length

\- The elements in nums are distinct



\*\*Follow-up:\*\* Can it be solved with O(1) extra memory?



\## Approach

Because nums is a permutation, every value is a valid index into nums, so nums\[nums\[i]] never goes out of bounds. Create a new array of the same size and fill temp\[i] with nums\[nums\[i]] in a single loop, writing into the new array so the original values stay untouched while the loop is still reading them.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over the array

\- \*\*Space:\*\* O(n) - for the new array



\## Key Learning

Writing the answers directly back into nums would be wrong, because later positions still need the original values. The follow-up solves this by storing two values in one number. Since every value is smaller than n, a single element can hold the old value in its remainder and the new value in its quotient: nums\[i] = nums\[i] + n \* (nums\[nums\[i]] % n). Taking % n always recovers the original value, even for positions that were already encoded. After that pass, a second pass divides every element by n to keep only the new values. That gives O(1) extra space, and the largest encoded value is below n \* n, which is at most about 10^6 and fits in an int.

