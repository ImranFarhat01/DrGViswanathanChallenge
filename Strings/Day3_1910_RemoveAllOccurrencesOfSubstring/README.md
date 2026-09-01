# 1910. Remove All Occurrences of a Substring

🔗 [View on LeetCode](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 3

## Problem
Given strings s and part, repeatedly find the leftmost occurrence of part in s and remove it, until no occurrences remain. Return the final string.

**Examples:**
- s = "daabcbaabcbc", part = "abc" → "dab"
- s = "axxxxyyyyb", part = "xy" → "ab"

**Constraints:**
- 1 <= s.length <= 1000
- 1 <= part.length <= 1000
- s and part consist of lowercase English letters

## Approach
Repeatedly search for part within s using find(). Whenever a match is found, erase it in place using erase(). Continue until find() returns string::npos, meaning no more occurrences exist. Since removing one occurrence can expose a new occurrence formed by the surrounding characters joining together, the search must restart from the beginning each time rather than continuing from where the last match ended.

## Complexity
- **Time:** O(n^2 / m) in the worst case - each erase can shift up to n characters, and this can happen up to n/m times
- **Space:** O(1) extra - modifies the string in place

## Key Learning
Removing a substring can create a brand new match by joining the characters on either side of the removed section - the search always has to restart from the beginning of the string, not from the removal point, to catch these newly formed occurrences.
