# 1816. Truncate Sentence

🔗 [View on LeetCode](https://leetcode.com/problems/truncate-sentence/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 71

## Problem
A sentence is a list of words separated by a single space, with no leading or trailing spaces, and each word contains only English letters. Given a sentence s and an integer k, truncate s so that it contains only its first k words, and return the result.

**Examples:**
- s = "Hello how are you Contestant", k = 4 → "Hello how are you"
- s = "What is the solution to this problem", k = 4 → "What is the solution"
- s = "chopper is not a tanuki", k = 5 → "chopper is not a tanuki"

**Constraints:**
- 1 <= s.length <= 500
- k is in the range [1, the number of words in s]
- s consists of only lowercase and uppercase English letters and spaces
- The words in s are separated by a single space
- There are no leading or trailing spaces

## Approach
Words are separated by exactly one space, so the number of spaces seen so far tells how many words are complete. Walk through the sentence one character at a time and count the spaces. The moment the k-th space appears, k words have already been copied, so stop before copying that space. Every other character is appended to the answer.

If k equals the total number of words, there are only k - 1 spaces in the sentence, so the counter never reaches k and the whole sentence is returned, which is exactly what example 3 expects.

## Complexity
- **Time:** O(n) - one pass over the string
- **Space:** O(n) - for the output string

## Key Learning
Counting separators is a simple way to count words when the format is guaranteed to be clean. The check happens before appending, so the k-th space is never added and the result has no trailing space. A close alternative is to find the position of the k-th space and return s.substr(0, position), or to use a stringstream to read k words, but the single pass with a counter needs no extra tools and handles the "k equals the number of words" case with no special code.
