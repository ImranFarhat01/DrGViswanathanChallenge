\# 567. Permutation in String



🔗 \[View on LeetCode](https://leetcode.com/problems/permutation-in-string/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 4



\## Problem

Given two strings s1 and s2, return true if s2 contains a permutation of s1 as a substring, false otherwise.



\*\*Examples:\*\*

\- s1 = "ab", s2 = "eidbaooo" → true ("ba" is a permutation of "ab")

\- s1 = "ab", s2 = "eidboaoo" → false



\*\*Constraints:\*\*

\- 1 <= s1.length, s2.length <= 10^4

\- s1 and s2 consist of lowercase English letters



\## Approach

A permutation of s1 has the exact same character frequency as s1, just rearranged. So instead of checking permutations directly, build a frequency count of s1, then slide a fixed-size window of the same length across s2, maintaining a frequency count of the current window.



At each window position, compare the two frequency arrays. If they match, the current window is a permutation of s1. Sliding the window one step forward is done by incrementing the count of the new character entering the window and decrementing the count of the character leaving it, avoiding recomputation from scratch each time.



\## Complexity

\- \*\*Time:\*\* O(n \* 26) which simplifies to O(n), where n is the length of s2, since each window comparison checks 26 fixed letters

\- \*\*Space:\*\* O(1) - two fixed size arrays of 26 integers regardless of input size



\## Key Learning

Checking for a permutation as a substring doesn't require generating permutations at all - comparing character frequency counts is enough, since a permutation only rearranges characters without changing how many of each there are. Sliding window frequency counting turns an otherwise expensive comparison into a constant time update at each step.

