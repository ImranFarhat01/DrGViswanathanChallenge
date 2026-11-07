# 771. Jewels and Stones

🔗 [View on LeetCode](https://leetcode.com/problems/jewels-and-stones/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 70

## Problem
Given a string jewels that lists the types of stones that are jewels, and a string stones that lists the stones you have, return how many of your stones are also jewels. Letters are case sensitive, so "a" and "A" are different types of stone.

**Examples:**
- jewels = "aA", stones = "aAAbbbb" → 3
- jewels = "z", stones = "ZZ" → 0

**Constraints:**
- 1 <= jewels.length, stones.length <= 50
- jewels and stones consist of only English letters
- All the characters of jewels are unique

## Approach
For every stone, check whether it matches any character in jewels, and count it if it does. Because all characters in jewels are unique, a stone can match at most one jewel type, so the count never goes up twice for the same stone and no early exit is needed.

## Complexity
- **Time:** O(n * m), where n = stones.length and m = jewels.length. With both capped at 50, this is tiny
- **Space:** O(1) - only a counter

## Key Learning
The nested loop is fine at this size, but the real pattern is a membership check. If the jewel types are stored first in a hash set or in a boolean array indexed by character, each stone can be checked with one lookup, and the whole solution drops to O(n + m). The uniqueness guarantee in the constraints is what makes the plain counting loop safe: without it, a duplicated jewel letter would count the same stone twice.
