\# 424. Longest Repeating Character Replacement



🔗 \[View on LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 33



\## Problem

Given a string s and an integer k, you can change any character of s to any other uppercase English letter, up to k times. Return the length of the longest substring containing the same letter achievable after these replacements.



\*\*Examples:\*\*

\- s = "ABAB", k = 2 → 4

\- s = "AABABBA", k = 1 → 4



\*\*Constraints:\*\*

\- 1 <= s.length <= 10^5

\- s consists of only uppercase English letters

\- 0 <= k <= s.length



\## Approach

A window is achievable if the number of characters that need to be replaced (window size minus the count of the most frequent character in the window) is at most k. Track a frequency array of the 26 letters within the current window, along with maxFreq, the highest frequency seen for any single letter in the window so far.



Expand the window with r, updating the frequency count and maxFreq. If the number of "non-majority" characters in the window (r - l + 1 - maxFreq) exceeds k, shrink the window from the left by one character. Whenever the window is valid (replacements needed <= k), update the answer with the current window size.



\## Complexity

\- \*\*Time:\*\* O(n) - amortized, since both l and r pointers move forward through the string a bounded number of times total, and frequency lookups/updates are O(1) over a fixed 26-letter alphabet

\- \*\*Space:\*\* O(1) - the frequency array has a fixed size of 26 regardless of input size



\## Key Learning

A subtle detail in this implementation: when the window shrinks, maxFreq is reset to 0 rather than being recalculated from the updated frequency array. This looks like a bug, since maxFreq could now be stale and too low for the current window, but it doesn't actually break correctness here, because the window's overall length only needs to grow or stay the same to still produce a correct final answer. The window never truly shrinks in net size across the full run; it only ever slides forward by the same amount it shrank, so an occasionally understated maxFreq just delays recognizing a valid window rather than producing a wrong final maximum. Worth being cautious with this pattern though, since it depends on this exact "window never shrinks net" property holding, which isn't true for every sliding window problem.

