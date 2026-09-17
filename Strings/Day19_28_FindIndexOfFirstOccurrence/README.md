# 28. Find the Index of the First Occurrence in a String

🔗 [View on LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 19

## Problem
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

**Examples:**
- haystack = "sadbutsad", needle = "sad" → 0
- haystack = "leetcode", needle = "leeto" → -1

**Constraints:**
- 1 <= haystack.length, needle.length <= 10^4
- haystack and needle consist of only lowercase English characters

## Approach
Try every possible starting position i in haystack where needle could begin (only positions where there are at least m characters left, hence i <= n - m). At each candidate position, first quickly check if the first character matches; if not, skip immediately without further comparison. If it does match, compare the rest of needle character by character against haystack starting at i. If all m characters match, i is a valid starting index and gets returned immediately. If no position works after checking all candidates, return -1.

## Complexity
- **Time:** O(n * m) in the worst case, where n is the length of haystack and m is the length of needle, since each starting position can require up to m comparisons
- **Space:** O(1) - no extra data structures used

## Key Learning
This brute-force approach is simple and works within the given constraints, but it's not the asymptotically optimal solution. Algorithms like KMP (Knuth-Morris-Pratt) achieve O(n + m) by avoiding redundant comparisons using a precomputed failure function, worth revisiting for a deeper understanding of string matching, especially since this exact problem lists KMP, Z-Algorithm, and Boyer-Moore as related topics.
