\# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings



🔗 \[View on LeetCode](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 30



\## Problem

Given a valid parentheses string seq, split it into two disjoint subsequences A and B (not necessarily contiguous) such that both A and B are valid parentheses strings and together they use every character of seq. Choose the split so that max(depth(A), depth(B)) is as small as possible. Return an array where answer\[i] = 0 if seq\[i] belongs to A, and 1 if it belongs to B. Any valid answer is accepted.



\*\*Examples:\*\*

\- seq = "(()())" → \[0,1,1,1,1,0]

\- seq = "()(())()" → \[0,0,0,1,1,0,1,1]



\*\*Constraints:\*\*

\- 1 <= seq.size <= 10000



\## Approach

The minimum possible max depth is achieved by splitting the nesting levels as evenly as possible between A and B. The simplest way to do this is to alternate by depth: every "(" at an odd nesting depth goes to one string, and every "(" at an even nesting depth goes to the other.



Walk through seq keeping a running depth count. On an opening bracket, increase the depth and assign the bracket to group (depth % 2), then push that group onto a stack. On a closing bracket, pop the stack and give the ")" the same group as its matching "(", which guarantees both A and B stay valid parentheses strings. Decrease the depth after each closing bracket.



\## Complexity

\- \*\*Time:\*\* O(n) - single pass through seq

\- \*\*Space:\*\* O(n) - for the stack and the answer array



\## Key Learning

The problem statement is confusing, but the idea behind it is simple: to keep the maximum depth of both strings as small as possible, spread the nesting levels evenly by alternating groups with depth parity. Since any valid answer is accepted, the output may differ from the sample output while still being correct (the sample shows \[0,1,1,1,1,0] while this solution produced \[1,0,0,0,0,1], and both are valid). The stack can also be removed entirely by computing the group of a closing bracket directly from the current depth before decrementing it, which brings the extra space down to O(1) beyond the answer array.

