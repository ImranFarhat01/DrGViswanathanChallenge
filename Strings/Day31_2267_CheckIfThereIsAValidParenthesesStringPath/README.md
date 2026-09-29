\# 2267. Check if There Is a Valid Parentheses String Path



🔗 \[View on LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Hard

\- \*\*Day:\*\* 31



\## Problem

Given an m x n grid of parentheses, find whether there exists a path from the top-left cell to the bottom-right cell (moving only down or right) such that the parentheses along the path form a valid parentheses string.



\*\*Examples:\*\*

\- grid = \[\["(","(","("],\[")","(",")"],\["(","(",")"],\["(","(",")"]] → true

\- grid = \[\[")",")"],\["(","("]] → false



\*\*Constraints:\*\*

\- m == grid.length

\- n == grid\[i].length

\- 1 <= m, n <= 100

\- grid\[i]\[j] is either '(' or ')'



\## Approach

A parentheses string is valid only if, scanned left to right, the count of unmatched open brackets never goes negative and ends at exactly zero. Track this "balance" (cntLeft) as a third dimension of state alongside the cell position, since the same cell can be reached with different balances depending on the path taken so far.



Use recursion with memoization: solve(i, j, cntLeft) explores moving down or moving right from the current cell, updating the balance based on whether the current cell is '(' or ')'. If the balance ever goes negative, that path is immediately invalid and pruned. At the destination cell, the path is valid only if the balance has returned to exactly zero. Memoize results per (i, j, cntLeft) to avoid recomputing the same state multiple times, since many different paths can reach the same cell with the same balance.



Two early exits short-circuit obviously impossible cases before recursion even starts: if the string must start with ')' or end with '(', it can never be valid, and if the total path length (m + n - 1) is odd, a valid parentheses string of odd length is impossible.



\## Complexity

\- \*\*Time:\*\* O(m \* n \* (m+n)) - the memoization table has O(m \* n \* (m+n)) distinct states (since balance is bounded by path length), each computed once

\- \*\*Space:\*\* O(m \* n \* (m+n)) - for the memoization table



\## Key Learning

When a path-validity problem depends on more than just position, here, the running balance of open versus closed brackets, that extra piece of state needs to become part of the memoization key itself. Treating (i, j) alone as the state would be wrong, since the same cell can be reached with different balances from different paths, and only some of those balances can still lead to a valid final path. Early impossibility checks (mismatched start/end characters, odd total length) are cheap wins that avoid wasting a full DFS on clearly unsolvable grids.

