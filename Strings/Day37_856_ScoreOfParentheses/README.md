\# 856. Score of Parentheses



🔗 \[View on LeetCode](https://leetcode.com/problems/score-of-parentheses/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 37



\## Problem

Given a balanced parentheses string s, return its score, defined recursively: "()" has score 1, AB (two balanced strings concatenated) has score A + B, and (A) has score 2 \* A.



\*\*Examples:\*\*

\- s = "()" → 1

\- s = "(())" → 2

\- s = "()()" → 2



\*\*Constraints:\*\*

\- 2 <= s.length <= 50

\- s consists of only '(' and ')'

\- s is a balanced parentheses string



\## Approach

Track the current nesting depth using an open counter. Whenever a "()" pair is found (detected by checking that the character right before the current ')' is '(', meaning this is an innermost, empty pair), that pair contributes 2^depth to the total score, where depth is the current nesting level after this closing bracket is processed (open is decremented before the check, so it reflects the depth of the pair that just closed).



Every "()" found anywhere in the string contributes independently based on how deeply it's nested, and the final score is the sum of all these contributions. This works because of how the scoring rule composes: a pair nested k levels deep ends up contributing 2^k regardless of what's around it, since each enclosing pair doubles the contribution of everything inside it.



\## Complexity

\- \*\*Time:\*\* O(n) - single pass through the string

\- \*\*Space:\*\* O(1) - only a couple of counters used, no stack needed



\## Key Learning

The recursive scoring rule (empty pair = 1, nesting doubles, concatenation adds) can be flattened into a simple observation: every innermost "()" pair contributes exactly 2^depth to the total score, where depth is how deeply nested it is. This avoids needing to actually build a recursive structure or use a stack to track partial sums, since depth alone fully determines each pair's contribution, and contributions from different pairs simply add together.

