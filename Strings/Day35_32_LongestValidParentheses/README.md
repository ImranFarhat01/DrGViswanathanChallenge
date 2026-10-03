# 32. Longest Valid Parentheses

🔗 [View on LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)

- **Platform:** LeetCode
- **Difficulty:** Hard
- **Day:** 35

## Problem
Given a string containing only '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

**Examples:**
- s = "(()" → 2
- s = ")()())" → 4
- s = "" → 0

**Constraints:**
- 0 <= s.length <= 3 * 10^4
- s[i] is '(' or ')'

## Approach
A single left-to-right scan using open/close counters isn't enough on its own. Consider "(()": scanning left to right, close never exceeds open, so the counters never reset, but open also never equals close at any point except possibly missing the valid "()" buried inside unless the counts happen to align, meaning some valid substrings get missed when there are more opens than closes overall. The fix is to run the scan twice, once left to right and once right to left, with the reset condition flipped for each direction.

Left to right: track open and close counts while scanning. Whenever open equals close, the current substring is balanced, so update the answer with open * 2. If close ever exceeds open, the current prefix can never become valid (extra unmatched closing brackets), so reset both counters to start fresh from the next position.

Right to left: the symmetric case. Here, having more opens than closes while scanning backward means there are unmatched opens that can't be matched moving in this direction, so reset in that case instead. This catches valid substrings that the left-to-right pass missed, like the "()" at the end of "(()", where opens exceed closes overall but a valid substring still exists within the excess.

## Complexity
- **Time:** O(n) - two linear passes through the string
- **Space:** O(1) - only a few counters used, no stack or extra array

## Key Learning
A single-direction counting approach has a blind spot: it can only detect invalidity from one type of imbalance (too many closes in a left-to-right scan), but misses substrings that are valid internally even when the overall prefix has excess opens. Running the same logic in both directions, with the reset condition mirrored, covers both blind spots simultaneously without needing a stack-based approach, achieving O(1) space instead of the O(n) a stack-based solution would typically require.
