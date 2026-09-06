# 13. Roman to Integer

🔗 [View on LeetCode](https://leetcode.com/problems/roman-to-integer/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 8

## Problem
Roman numerals use seven symbols (I, V, X, L, C, D, M) with fixed values (1, 5, 10, 50, 100, 500, 1000). Normally written largest to smallest left to right, but six subtractive cases exist: I before V or X, X before L or C, and C before D or M, which subtract the smaller value instead of adding it. Given a valid Roman numeral string, convert it to its integer value.

**Examples:**
- s = "III" → 3
- s = "LVIII" → 58 (L=50, V=5, III=3)
- s = "MCMXCIV" → 1994 (M=1000, CM=900, XC=90, IV=4)

**Constraints:**
- 1 <= s.length <= 15
- s contains only I, V, X, L, C, D, M
- s is guaranteed to be a valid Roman numeral in the range [1, 3999]

## Approach
Map each symbol to its integer value using a hash map. Walk through the string once, and at each character, compare its value to the value of the character right after it. If the current character's value is smaller than the next one's, it's a subtractive case (like IV or IX), so subtract it instead of adding it. Otherwise, add it normally. Since the last character never has a "next" character, it always falls into the addition case by default, since the bounds check on i + 1 fails.

## Complexity
- **Time:** O(n) - single pass through the string, where n is at most 15
- **Space:** O(1) - the hash map has a fixed size of 7 entries regardless of input

## Key Learning
Instead of writing separate logic to detect the six specific subtractive pairs (IV, IX, XL, XC, CD, CM), a simpler general rule captures all of them at once: whenever a smaller value comes right before a larger one, it should be subtracted rather than added. This turns six special cases into a single comparison.
