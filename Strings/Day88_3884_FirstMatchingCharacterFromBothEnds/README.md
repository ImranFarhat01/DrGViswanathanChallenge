# 3884. First Matching Character From Both Ends

🔗 [View on LeetCode](https://leetcode.com/problems/first-matching-character-from-both-ends/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 88

## Problem
Given a string s of length n consisting of lowercase English letters, return the smallest index i such that s[i] == s[n - i - 1]. If no such index exists, return -1.

**Examples:**
- s = "abcacbd" → 1 (s[1] and s[5] are both 'b')
- s = "abc" → 1 (the two compared positions coincide at the middle, so both characters are 'b')
- s = "abcdab" → -1 (no pair of mirrored positions matches)

**Constraints:**
- 1 <= n == s.length <= 100
- s consists of lowercase English letters

## Approach
The character at index i has a mirror partner at index n - i - 1, measured from the other end. Go through the indices from left to right and compare each character with its mirror. The first index where they match is the smallest valid one, so return it immediately. If the loop finishes without a match, return -1.

## Complexity
- **Time:** O(n) - one pass, with an early return on the first match
- **Space:** O(1) - no extra memory

## Key Learning
The comparison is symmetric: if s[i] == s[n - i - 1], then index n - i - 1 would match too. So any match in the second half has a mirror in the first half that was already found, which means looping only up to the middle (i <= n / 2) gives the same answer in half the iterations. For a string of odd length, the middle index compares a character with itself, so it always matches, and the answer for odd n can never be -1. That is why the second example, "abc", returns 1. Only even length strings can return -1.
