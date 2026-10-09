# 1541. Minimum Insertions to Balance a Parentheses String

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 41

## Problem
A parentheses string is balanced if every '(' has a corresponding pair of two consecutive right parentheses '))', and the '(' comes before its '))'. Given a string s of '(' and ')', return the minimum number of insertions (of either '(' or ')') needed to make s balanced.

**Examples:**
- s = "(()))" → 1
- s = "())" → 0
- s = "))())(" → 3

**Constraints:**
- 1 <= s.length <= 10^5
- s consists of '(' and ')' only

## Approach
Treat '(' as an opener and '))' as a single closer. Keep a counter open for unmatched '(' seen so far, and a counter ans for insertions made.

For every '(', increment open. For every ')', look at the next character:
- If the next character is also ')', the two form a complete '))' closer, so skip over both by advancing the index.
- If the next character is not ')' (or the string ends), only a single ')' is present, so one ')' must be inserted to complete the pair, which adds 1 to ans.

Once a full '))' closer is available, it needs a '(' to match. If open > 0, use one of the unmatched '(' by decrementing open. Otherwise there is nothing to match against, so a '(' must be inserted, which adds 1 to ans.

After the scan, every '(' still left in open has no closer at all, and each one needs '))' inserted, which costs 2 insertions per leftover '('. So the final answer is ans + 2 * open.

## Complexity
- **Time:** O(n) - single pass through the string, with the index sometimes advancing by two
- **Space:** O(1) - only two counters used

## Key Learning
The twist compared to the usual parentheses problems is that a closer is two characters wide, so the scan has to look ahead one character to decide whether a ')' is a full closer or a lonely half. Handling the three cases separately (a full '))' with a match, a full '))' with no match, and a lonely ')' that needs a partner inserted) keeps the logic clean, and the leftover opens at the end cost 2 each because every one of them still needs a complete '))'.
