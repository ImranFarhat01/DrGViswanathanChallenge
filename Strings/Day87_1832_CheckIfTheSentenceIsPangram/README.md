\# 1832. Check if the Sentence Is Pangram



🔗 \[View on LeetCode](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 87



\## Problem

A pangram is a sentence in which every letter of the English alphabet appears at least once. Given a string sentence that contains only lowercase English letters, return true if it is a pangram, and false otherwise.



\*\*Examples:\*\*

\- sentence = "thequickbrownfoxjumpsoverthelazydog" → true

\- sentence = "leetcode" → false



\*\*Constraints:\*\*

\- 1 <= sentence.length <= 1000

\- sentence consists of lowercase English letters



\## Approach

Use a frequency array with one slot for each of the 26 letters. Go through the sentence once and increase the count at index ch - 'a' for every character. After that, check all 26 slots. If any slot is still 0, that letter never appeared, so the sentence is not a pangram. If every slot is at least 1, it is a pangram.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over the sentence, plus a fixed loop over 26 letters

\- \*\*Space:\*\* O(1) - the frequency array always has 26 entries



\## Key Learning

The question only asks whether each letter appears, not how many times, so a count is more than is needed. A boolean array, or a single integer used as a bitmask (mask |= 1 << (ch - 'a')), is enough, and the sentence is a pangram when the mask equals (1 << 26) - 1. With the bitmask version, the loop can also stop early once all 26 bits are set. The constraints guarantee lowercase letters only, which is why ch - 'a' is always a valid index between 0 and 25.

