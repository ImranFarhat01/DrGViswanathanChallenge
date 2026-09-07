# 5. Longest Palindromic Substring

🔗 [View on LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 9

## Problem
Given a string s, return the longest palindromic substring in s.

**Examples:**
- s = "babad" → "bab" ("aba" is also valid)
- s = "cbbd" → "bb"

**Constraints:**
- 1 <= s.length <= 1000
- s consists of only digits and English letters

## Approach
A substring from index i to j is a palindrome if the characters at both ends match (s[i] == s[j]) and everything strictly between them is also a palindrome. This gives a natural recursive definition, which is memoized to avoid recomputation: t[i][j] stores whether the substring from i to j is a palindrome, computed once and reused.

The base case is i >= j, which is always a palindrome (empty string or single character). Otherwise, the substring is a palindrome only if the outer characters match and the inner substring (i+1, j-1) is also a palindrome.

Using this memoized check, iterate over every possible substring (all i, j pairs) and track the longest one found where isPalindrome returns true.

## Complexity
- **Time:** O(n^2) - checking all substrings, with each individual palindrome check being O(1) after memoization
- **Space:** O(n^2) - for the memoization table t[1001][1001]

## Key Learning
Palindrome checking has natural overlapping subproblems: checking if (i, j) is a palindrome depends on already knowing whether (i+1, j-1) is a palindrome. Memoizing this recursive relationship turns what would be repeated O(n) checks for every substring into a one-time O(1) lookup after the first computation, bringing the total substring-checking cost down from what would otherwise be much higher.
