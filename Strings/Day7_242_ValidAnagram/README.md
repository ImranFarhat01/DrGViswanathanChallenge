# 242. Valid Anagram

🔗 [View on LeetCode](https://leetcode.com/problems/valid-anagram/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 7

## Problem
Given two strings s and t, return true if t is an anagram of s, false otherwise.

**Examples:**
- s = "anagram", t = "nagaram" → true
- s = "rat", t = "car" → false

**Constraints:**
- 1 <= s.length, t.length <= 5 * 10^4
- s and t consist of lowercase English letters

**Follow-up:** What if the inputs contain Unicode characters?

## Approach
Two strings are anagrams of each other only if they have the exact same character frequency. First check if the lengths differ, in which case they can't be anagrams. Otherwise, use a single frequency array of size 26 (one slot per lowercase letter), incrementing counts for characters in s and decrementing for characters in t at the same time in one pass. If s and t are true anagrams, every character's net count should return to zero. A final pass checks that all 26 slots are zero.

**Follow-up thought:** For Unicode characters, a fixed size 26 array no longer works since the character set is far larger and not contiguous in a simple way. A hash map (character to count) would replace the array, trading the O(1) fixed-size lookup for a more flexible but slightly slower hash-based lookup.

## Complexity
- **Time:** O(n) - one pass to build frequency differences, one constant pass (26 iterations) to verify
- **Space:** O(1) - the frequency array is a fixed size of 26 regardless of input size

## Key Learning
Combining the increment and decrement into a single frequency array during one pass avoids building two separate frequency arrays and comparing them afterward. Since both operations touch the same underlying array, the comparison is reduced to checking that everything nets out to zero.
