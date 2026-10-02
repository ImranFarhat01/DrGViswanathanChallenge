\# 22. Generate Parentheses



🔗 \[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 34



\## Problem

Given n pairs of parentheses, generate all combinations of well-formed (valid) parentheses strings.



\*\*Examples:\*\*

\- n = 3 → \["((()))","(()())","(())()","()(())","()()()"]

\- n = 1 → \["()"]



\*\*Constraints:\*\*

\- 1 <= n <= 8



\## Approach

Build strings character by character using backtracking, tracking how many open and close brackets have been used so far. At each step, there are two choices: add an opening bracket, allowed only if fewer than n opens have been used so far, or add a closing bracket, allowed only if the count of closes is still less than the count of opens (ensuring the string never becomes invalid mid-construction, since a close bracket always needs an unmatched open bracket before it).



When the current string reaches length 2n, it's a complete, valid combination, so it gets added to the result. After exploring both the "add open" and "add close" branches at a given position, backtrack by removing the last character before returning, so the next branch starts from a clean state.



\## Complexity

\- \*\*Time:\*\* O(4^n / sqrt(n)) - this corresponds to the nth Catalan number, which counts the total number of valid parentheses combinations; the algorithm only ever explores valid partial strings, so no wasted work is done on invalid branches

\- \*\*Space:\*\* O(n) for the recursion depth and the current string being built, excluding the space needed to store the final result itself



\## Key Learning

The key constraint that keeps every generated string valid throughout construction, not just at the end, is allowing a close bracket only when close < open. This single condition prevents ever creating an invalid prefix like ")(" during the backtracking process, meaning every leaf of the recursion tree that reaches length 2n is guaranteed to be a valid combination, no post-validation needed. This is a classic example of pruning invalid states early rather than generating everything and filtering afterward.

