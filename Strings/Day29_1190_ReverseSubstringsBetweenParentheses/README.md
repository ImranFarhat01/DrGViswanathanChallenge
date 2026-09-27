# 1190. Reverse Substrings Between Each Pair of Parentheses

🔗 [View on LeetCode](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 29

## Problem
Given a string s that consists of lowercase letters and parentheses, reverse the strings in each pair of matching parentheses, starting from the innermost one. The result should not contain any brackets.

## Approach
Use a stack to track the index of every opening parenthesis encountered. Whenever a closing parenthesis is found, pop the most recent opening parenthesis's index off the stack, this gives the matching pair. Reverse the substring strictly between these two indices in place, directly within the original string.

Because the reversal happens as soon as each closing parenthesis is found, and the stack always gives the innermost still-open pair, nested parentheses get reversed from the inside out automatically without any special-casing: an inner reversal happens first, and when the outer closing parenthesis is later processed, it simply reverses the already-processed (and already correctly reversed) inner content along with everything else in its range, which is exactly the correct final result for nested reversals.

Once every parenthesis pair has been processed and reversed, do a final pass over the string, keeping only the lowercase letters and discarding all leftover parentheses, to produce the bracket-free final answer.

## Complexity
- **Time:** O(n^2) in the worst case, since each reversal can cost up to O(n), and there can be up to O(n) reversals for deeply nested parentheses
- **Space:** O(n) - for the stack of indices and the final answer string

## Key Learning
Reversing directly in the original string as each closing bracket is encountered naturally handles nested parentheses correctly, without needing any explicit recursion or special handling for nesting depth. The stack of indices does the coordination: because reversals happen innermost-first (since the innermost closing bracket is always encountered before its enclosing one), each subsequent outer reversal operates on content that's already correctly resolved.
