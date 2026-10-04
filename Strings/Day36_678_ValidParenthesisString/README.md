\# 678. Valid Parenthesis String



🔗 \[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 36



\## Problem

Given a string s containing only '(', ')', and '\*', return true if s is valid. '(' must be matched by a later ')', every ')' needs a prior matching '(', and '\*' can act as '(', ')', or an empty string. Return whether the string can be interpreted as valid under some assignment of the '\*' characters.



\*\*Examples:\*\*

\- s = "()" → true

\- s = "(\*)" → true

\- s = "(\*))" → true

\- s = "(" → false



\*\*Constraints:\*\*

\- 1 <= s.length <= 100

\- s\[i] is '(', ')', or '\*'



\## Approach

Use recursion with memoization, tracking the current position i and the current count of unmatched open brackets (open). At each position: if the character is '(', increment open and move forward; if ')', decrement open and move forward; if '\*', branch into all three interpretations (as '(', as ')', or as empty) and succeed if any one of them leads to a valid completion. If open ever goes negative, this path is invalid and pruned immediately. At the end of the string, the path is valid only if open is exactly 0, meaning every bracket was matched.



An early exit handles a specific edge case: if the entire string consists of '\*' characters, it can always be made valid (by treating all of them as empty), so this is checked before running the full recursion.



\## Complexity

\- \*\*Time:\*\* O(n^2) - the memoization table has O(n) positions times O(n) possible open-bracket counts, giving O(n^2) distinct states, each computed once

\- \*\*Space:\*\* O(n^2) - for the memoization table



\## Key Learning

The presence of a wildcard character that can mean multiple things is a strong signal for trying all its interpretations via recursion, then memoizing on whatever state actually varies (here, position and open-bracket count) to avoid exponential blowup from re-exploring the same state repeatedly. Without memoization, branching three ways at every '\*' would make this exponential; with it, the state space collapses to a manageable quadratic size since open is always bounded between 0 and n.

