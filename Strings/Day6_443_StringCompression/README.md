\# 443. String Compression



🔗 \[View on LeetCode](https://leetcode.com/problems/string-compression/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 6



\## Problem

Given an array of characters chars, compress it in place: for each group of consecutive repeating characters, append the character followed by the group's length if the group has more than one character, or just the character alone if the group's length is 1. Group lengths of 10 or more get split across multiple characters. Return the new length of the array after compression. Must use only constant extra space.



\*\*Examples:\*\*

\- chars = \["a","a","b","b","c","c","c"] → 6, chars becomes \["a","2","b","2","c","3"]

\- chars = \["a"] → 1, chars stays \["a"]

\- chars = \["a","b","b",...,"b"] (12 b's) → 4, chars becomes \["a","b","1","2"]



\*\*Constraints:\*\*

\- 1 <= chars.length <= 2000

\- chars\[i] is a lowercase English letter, uppercase English letter, digit, or symbol



\## Approach

Walk through chars once, counting how many times each character repeats consecutively. Whenever a different character is encountered, write the previous character to a result string, followed by its count only if the count is greater than 1 (a count of 1 gets appended as digits automatically, which is wrong per the problem's rules). After the loop ends, handle the final group separately since the loop only writes a group when it detects a change to the next character.



Once the compressed result is built as a separate string, copy it back into the original chars array, overwriting the first ans.length() positions. The returned length tells the caller how many of those positions are meaningful.



\## Complexity

\- \*\*Time:\*\* O(n) - single pass to count groups, plus a copy-back pass of at most n characters

\- \*\*Space:\*\* O(n) for the intermediate result string in this implementation - though the compressed result is always the same size or smaller than the input, so the string never exceeds O(n) even though the problem statement asks for O(1) extra space, which would require writing directly into chars using two pointers instead of a separate buffer



\## Key Learning

The trickiest part isn't the compression logic itself, it's handling the last group. Since the loop only writes a completed group when it detects the \*next\* character is different, the very last group in the array never triggers that condition and has to be written manually after the loop ends.

