# 301. Remove Invalid Parentheses

🔗 [View on LeetCode](https://leetcode.com/problems/remove-invalid-parentheses/)

- **Platform:** LeetCode
- **Difficulty:** Hard
- **Day:** 39

## Problem
Given a string s containing lowercase letters and parentheses, remove the minimum number of invalid parentheses to make the string valid. Return all unique valid strings achievable with that minimum number of removals, in any order.

**Examples:**
- s = "()())()" → ["(())()","()()()"]
- s = "(a)())()" → ["(a())()","(a)()()"]
- s = ")(" → [""]

**Constraints:**
- 1 <= s.length <= 25
- s consists of lowercase English letters and '(' and ')'
- At most 20 parentheses in s

## Approach
For every character in s, there are essentially two choices if it's a parenthesis: keep it, or remove it (letters are always kept, since the problem only concerns removing invalid parentheses). Explore both choices recursively for every parenthesis character, building up a candidate string curr and tracking the running balance (open) of unmatched open brackets along the way. If the balance ever goes negative, that branch is invalid and pruned immediately, since it means more closing brackets than matching opens at that point.

At the end of the string, a candidate is only accepted if the balance is exactly 0 (every open bracket matched). Among all valid candidates discovered, track the maximum length found and keep only the candidates that reach that maximum length, since the problem asks for the minimum number of removals, which corresponds to the maximum possible remaining length. A set is used to automatically avoid duplicate strings, since different removal choices can produce the same resulting string.

## Complexity
- **Time:** O(2^p * n) in the worst case, where p is the number of parentheses characters (each one branches into keep/remove) and n is the string length (for building/copying strings at each step); bounded by the given constraint of at most 20 parentheses
- **Space:** O(2^p * n) - for storing all valid results of maximum length plus the recursion depth

## Key Learning
"Minimum number of removals" is equivalent to "maximum remaining length among all valid strings achievable," which reframes the problem from an optimization search into a straightforward generate-everything-then-filter-for-the-best approach. Since only parentheses characters create branching decisions (letters are always kept), the exponential factor in complexity depends only on the parentheses count, not the full string length, which is exactly why the constraint caps parentheses at 20 rather than capping the whole string length that tightly.sss
