# 921. Minimum Add to Make Parentheses Valid

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 38

## Problem
Given a parentheses string s, in one move you can insert a parenthesis at any position. Return the minimum number of insertions needed to make s valid.

**Examples:**
- s = "())" → 1
- s = "(((" → 3

**Constraints:**
- 1 <= s.length <= 1000
- s[i] is '(' or ')'

## Approach
Track two counters: size (unmatched open brackets seen so far) and open (closing brackets encountered that had no matching open bracket available). For every '(', increment size. For every ')', try to match it against an existing unmatched open bracket first, by decrementing size if size > 0; if there's no unmatched open bracket available (size is 0), this ')' can never be matched by anything already seen, so it increments open instead, representing a closing bracket that will need an inserted '(' before it.

At the end, size holds the number of unmatched opening brackets remaining (each needing a corresponding ')' inserted after it), and open holds the number of unmatched closing brackets encountered (each needing a corresponding '(' inserted before it). The total minimum insertions needed is simply the sum of these two counts.

## Complexity
- **Time:** O(n) - single pass through the string
- **Space:** O(1) - only two counters used, no stack needed

## Key Learning
This problem doesn't actually need a stack, even though it looks like a typical parentheses matching problem. Since every '(' looks identical to every other '(' (there's no distinguishing information attached to track beyond "it's unmatched"), a simple counter suffices in place of a stack whenever positions are open; counting is interchangeable with tracking, so a stack is only truly necessary when something more than "exists or doesn't" needs to be remembered per bracket, such as its position.
