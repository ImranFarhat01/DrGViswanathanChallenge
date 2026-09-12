\# 1876. Substrings of Size Three with Distinct Characters



🔗 \[View on LeetCode](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 14



\## Problem

A string is good if it has no repeated characters. Given a string s, return the number of good substrings of length three, counting every occurrence even if the same substring repeats.



\*\*Examples:\*\*

\- s = "xyzzaz" → 1 (only "xyz" is good among "xyz", "yzz", "zza", "zaz")

\- s = "aababcabc" → 4 (good substrings: "abc", "bca", "cab", "abc")



\*\*Constraints:\*\*

\- 1 <= s.length <= 100

\- s consists of lowercase English letters



\## Approach

Slide a fixed-size window of length 3 across the string. For each window position, check whether all three characters inside it are distinct by counting character frequencies in a 26-size array. If every character appears at most once, the window is a good substring, and the count increases.



\## Complexity

\- \*\*Time:\*\* O(n) overall, since each window check is O(1) (fixed at 3 characters and 26 letters), and the window slides across the string once

\- \*\*Space:\*\* O(1) - the frequency array is a fixed size of 26 regardless of input size



\## Key Learning

Since the window size is fixed at exactly 3, checking distinctness with a small frequency array is cheap and doesn't need to grow or shrink dynamically like a variable-size sliding window would. This makes the fixed-window case simpler than the general sliding window pattern, since there's no need to add or remove elements incrementally, each window can just be checked fresh.

