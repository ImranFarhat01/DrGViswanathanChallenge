# 2942. Find Words Containing Character

🔗 [View on LeetCode](https://leetcode.com/problems/find-words-containing-character/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 72

## Problem
Given a 0-indexed array of strings words and a character x, return an array of the indices of the words that contain the character x. The result may be returned in any order.

**Examples:**
- words = ["leet","code"], x = "e" → [0,1]
- words = ["abc","bcd","aaaa","cbc"], x = "a" → [0,2]
- words = ["abc","bcd","aaaa","cbc"], x = "z" → []

**Constraints:**
- 1 <= words.length <= 50
- 1 <= words[i].length <= 50
- x is a lowercase English letter
- words[i] consists only of lowercase English letters

## Approach
Go through the words one by one, and scan the characters of each word. As soon as a character equals x, record the index of that word and break out of the inner loop. The break matters because a word like "aaaa" contains x several times, and without it the same index would be added more than once. Words that never match are simply skipped, so an empty result comes out naturally when x appears nowhere.

## Complexity
- **Time:** O(n * m), where n is the number of words and m is the maximum word length. Both are at most 50 here
- **Space:** O(1) extra, apart from the output array

## Key Learning
The break after the first match is the key detail, since the question asks which words contain x, not how many times x appears. The inner loop can also be replaced by the built-in search words[i].find(x) != string::npos, which does the same job in a single line. Because the indices are collected while walking the array from left to right, the result also comes out already sorted.
