\# 709. To Lower Case



🔗 \[View on LeetCode](https://leetcode.com/problems/to-lower-case/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 81



\## Problem

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.



\*\*Examples:\*\*

\- s = "Hello" → "hello"

\- s = "here" → "here"

\- s = "LOVELY" → "lovely"



\*\*Constraints:\*\*

\- 1 <= s.length <= 100

\- s consists of printable ASCII characters



\## Approach

Go through the string one character at a time and build a new string. If the character is an uppercase letter (between 'A' and 'Z'), convert it by computing its offset from 'A' and adding that offset to 'a', so 'C' becomes 'c'. Any other character, including lowercase letters, digits, spaces and symbols, is copied unchanged.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over the string

\- \*\*Space:\*\* O(n) - for the output string



\## Key Learning

The range check is what keeps the other characters safe. The input can contain any printable ASCII character, and a shortcut such as adding 32 to every character would corrupt digits and symbols. In ASCII, every uppercase letter is exactly 32 below its lowercase version, which is why s\[i] - 'A' + 'a' works, and the same result can be written as s\[i] + 32 inside the range check. The standard library also provides tolower(), and the whole function can be done in place by changing s itself and returning it, which saves the extra string.

