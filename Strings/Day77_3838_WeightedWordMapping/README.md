\# 3838. Weighted Word Mapping



🔗 \[View on LeetCode](https://leetcode.com/problems/weighted-word-mapping/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 77



\## Problem

Given an array of lowercase words and an integer array weights of length 26, where weights\[i] is the weight of the i-th lowercase letter, the weight of a word is the sum of the weights of its characters. For each word, take its weight modulo 26 and map the result to a letter in reverse alphabetical order (0 maps to 'z', 1 maps to 'y', and so on up to 25 mapping to 'a'). Return the string formed by joining the mapped letters of all words, in order.



\*\*Examples:\*\*

\- words = \["abcd","def","xyz"], weights = \[5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2] → "rij"

\- words = \["a","b","c"], weights = all 1 → "yyy"

\- words = \["abcd"], weights = \[7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5] → "g"



\*\*Constraints:\*\*

\- 1 <= words.length <= 100

\- 1 <= words\[i].length <= 10

\- weights.length == 26

\- 1 <= weights\[i] <= 100

\- words\[i] consists of lowercase English letters



\## Approach

For each word, add up the weights of its characters, using ch - 'a' as the index into weights. Take that sum modulo 26 to get a remainder between 0 and 25. The reverse alphabet mapping sends remainder 0 to 'z', 1 to 'y', and so on, so the mapped letter is simply 'z' minus the remainder. Append that letter to the answer, and repeat for every word in order.



\## Complexity

\- \*\*Time:\*\* O(L), where L is the total number of characters across all words, since every character is visited once

\- \*\*Space:\*\* O(n) for the output string, where n is the number of words, and O(1) extra otherwise



\## Key Learning

The reverse alphabet mapping needs no lookup table. Because letters are consecutive in ASCII, 'z' - rem gives the right letter directly, in the same way that ch - 'a' turns a letter into an index. Check with the first example: the word "abcd" has weight 34, 34 % 26 = 8, and 'z' - 8 is 'r'. Looping with const string\& avoids copying each word, which matters more for long strings than for these small inputs. The largest word weight is 10 \* 100 = 1000, so int is safe.

