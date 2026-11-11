\# 3289. The Two Sneaky Numbers of Digitville



🔗 \[View on LeetCode](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 74



\## Problem

A list called nums should contain every integer from 0 to n - 1 exactly once, but two numbers sneaked in an extra time, so each of them appears twice and the list has n + 2 elements. Return an array of size two containing the two repeated numbers, in any order.



\*\*Examples:\*\*

\- nums = \[0,1,1,0] → \[0,1]

\- nums = \[0,3,2,1,3,2] → \[2,3]

\- nums = \[7,1,5,4,3,4,6,0,9,5,8,2] → \[4,5]



\*\*Constraints:\*\*

\- 2 <= n <= 100

\- nums.length == n + 2

\- 0 <= nums\[i] < n

\- The input is generated such that nums contains exactly two repeated elements



\## Approach

Every value is between 0 and n - 1, so a frequency array can be indexed directly by the value. Go through nums once and increase the count at freq\[nums\[i]]. Then scan the frequency array and collect every index whose count is 2. Since exactly two numbers are repeated, and each appears exactly twice, the answer has exactly two entries.



The frequency array is created with nums.size() entries, which is n + 2, so it is always large enough for values up to n - 1.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over nums and one pass over the frequency array

\- \*\*Space:\*\* O(n) - for the frequency array



\## Key Learning

When the values are guaranteed to lie in a small range starting at 0, they can be used directly as array indices, which replaces a hash map with a plain array and makes every lookup O(1). The same problem can also be solved with O(1) extra space, for example by sorting and comparing neighbors, or by marking visited values with a sign flip inside nums itself, which is worth practicing next. With n at most 100, the frequency array is the simplest and clearest choice.

