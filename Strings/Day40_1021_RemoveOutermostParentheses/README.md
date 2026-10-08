# 1021. Remove Outermost Parentheses

🔗 [View on LeetCode](https://leetcode.com/problems/remove-outermost-parentheses/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 40

## Problem
A valid parentheses string is primitive if it is nonempty and cannot be split into two nonempty valid parentheses strings. Every valid string can be decomposed into primitive pieces, such as "(()())(())" into "(()())" and "(())". Given a valid parentheses string s, remove the outermost parentheses of every primitive piece and return the result.

**Examples:**
- s = "(()())(())" → "()()()"
- s = "(()())(())(()(()))" → "()()()()(())"
- s = "()()" → ""

**Constraints:**
- 1 <= s.length <= 10^5
- s[i] is either '(' or ')'
- s is a valid parentheses string

## Approach
Track the current nesting depth with a single counter, countLeft. The outermost parentheses of a primitive piece are exactly the ones that sit at depth 0 on the way in and depth 1 on the way out, so every other bracket belongs in the answer.

For each '(', check the depth before incrementing it. If the depth was already greater than 0, this bracket is not an outermost opener, so it gets added to the result. For each ')', check the depth before decrementing it. If the depth was greater than 1, this bracket is not an outermost closer, so it gets added to the result. The post-increment and post-decrement inside the conditions make the check and the update happen in a single expression.

## Complexity
- **Time:** O(n) - single pass through the string
- **Space:** O(1) auxiliary - only one counter is used, plus O(n) for the output string itself

## Key Learning
The primitive decomposition sounds like it needs a stack or explicit splitting, but a depth counter alone is enough. A bracket is outermost exactly when it opens from depth 0 or closes back to depth 0, so comparing the depth before the update tells you whether to keep it. The same depth-counter idea shows up in several parentheses problems, so it is worth recognizing as a reusable tool.
