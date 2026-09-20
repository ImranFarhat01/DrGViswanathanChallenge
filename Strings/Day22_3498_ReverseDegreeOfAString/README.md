\# 3498. Reverse Degree of a String



🔗 \[View on LeetCode](https://leetcode.com/problems/reverse-degree-of-a-string/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 22



\## Problem

Given a string s, calculate its reverse degree. For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed), and sum these products across the entire string.



\*\*Examples:\*\*

\- s = "abc" → 148 (26\*1 + 25\*2 + 24\*3)

\- s = "zaza" → 160 (1\*1 + 26\*2 + 1\*3 + 26\*4)



\*\*Constraints:\*\*

\- 1 <= s.length <= 1000

\- s contains only lowercase English letters



\## Approach

For each character, its reversed-alphabet value can be computed directly as 26 - (character - 'a'), since 'a' maps to 26, 'b' to 25, and so on down to 'z' mapping to 1. Multiply this value by the character's 1-indexed position in the string (i + 1, since the loop uses 0-indexing), and add it to a running total.



\## Complexity

\- \*\*Time:\*\* O(n) - single pass through the string

\- \*\*Space:\*\* O(1) - only a running total tracked



\## Key Learning

Reversed alphabet positions don't need a lookup table or explicit mapping; they can be computed directly with simple arithmetic (26 - offset from 'a'), since the reversal is just a linear transformation of the normal alphabet position. Recognizing when a mapping is a simple formula instead of reaching for a table or array is a small but useful habit.

