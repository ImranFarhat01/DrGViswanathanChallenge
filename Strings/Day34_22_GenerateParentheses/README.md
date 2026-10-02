# 22. Generate Parentheses

🔗 [View on LeetCode](https://leetcode.com/problems/generate-parentheses/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 34

## Problem
Given n pairs of parentheses, generate all combinations of well-formed (valid) parentheses strings.

**Examples:**
- n = 3 → ["((()))","(()())","(())()","()(())","()()()"]
- n = 1 → ["()"]

**Constraints:**
- 1 <= n <= 8

## Approach
Build strings character by character using backtracking, tracking how many open and close brackets have been used so far. At each step, there are two choices: add an opening bracket, allowed only if fewer than n opens have been used so far, or add a closing bracket, allowed only if the count of closes is still less than the count of opens (ensuring the string never becomes invalid mid-construction, since a close bracket always needs an unmatched open bracket before it).

When the current string reaches length 2n, it's a complete, valid combination, so it gets added to the result. After exploring both the "add open" and "add close" branches at a given position, backtrack by removing the last character before returning, so the next branch starts from a clean state.

## Complexity
- **Time:** O(4^n / sqrt(n)) - this corresponds to the nth Catalan number, which counts the total number of valid parentheses combinations; the algorithm only ever explores valid partial strings, so no wasted work is done on invalid branches
- **Space:** The recursion stack and the string buffer being built each take O(n), since the maximum recursion depth and string length are both 2n. However, the result vector stores every valid combination, and there are C(n) of them (the nth Catalan number, approximately 4^n / n^1.5), each of length 2n. Multiplying the count of strings by their length gives a total output size of O(4^n / sqrt(n)), which dominates the O(n) auxiliary space. So: auxiliary space (excluding output) is O(n), and total space (including output) is O(4^n / sqrt(n)).

## Key Learning
The key constraint that keeps every generated string valid throughout construction, not just at the end, is allowing a close bracket only when close < open. This single condition prevents ever creating an invalid prefix like ")(" during the backtracking process, meaning every leaf of the recursion tree that reaches length 2n is guaranteed to be a valid combination, no post-validation needed. This is a classic example of pruning invalid states early rather than generating everything and filtering afterward.

Also worth being precise about space complexity here: the recursion stack and string buffer are only O(n), but the actual output (every valid combination of length 2n) grows exponentially, at O(4^n / sqrt(n)), matching the Catalan number count of results. When a problem's output size itself grows combinatorially, the space complexity is usually dominated by the output, not the auxiliary structures used to build it.
