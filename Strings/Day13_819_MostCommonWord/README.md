\# 819. Most Common Word



🔗 \[View on LeetCode](https://leetcode.com/problems/most-common-word/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 13



\## Problem

Given a string paragraph and an array of banned words, return the most frequent word in paragraph that is not banned. Words are case-insensitive, the answer should be returned in lowercase, and punctuation is ignored. It's guaranteed at least one non-banned word exists and the answer is unique.



\*\*Examples:\*\*

\- paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = \["hit"] → "ball"

\- paragraph = "a.", banned = \[] → "a"



\*\*Constraints:\*\*

\- 1 <= paragraph.length <= 1000

\- paragraph consists of English letters, spaces, or the symbols !?',;.

\- 0 <= banned.length <= 100

\- 1 <= banned\[i].length <= 10

\- banned\[i] consists of only lowercase English letters



\## Approach

First, lowercase the entire paragraph so word matching is case-insensitive. Then walk through the paragraph character by character, building up a word one letter at a time. Whenever a non-letter character is hit (space or punctuation), the word being built is complete, so it gets added to a frequency map and the builder resets. A final check after the loop catches the last word, since the loop only commits a word when it hits a non-letter character, and the paragraph might not end with punctuation.



Once every word's frequency is counted, remove every banned word from the map entirely, so it can never be picked as the answer. Finally, scan the remaining map for the word with the highest frequency.



\## Complexity

\- \*\*Time:\*\* O(p + b), where p is the length of paragraph and b is the total length of the banned array, since parsing is a single pass and removing banned words is proportional to how many there are

\- \*\*Space:\*\* O(w), where w is the number of unique words in the paragraph, for the frequency map



\## Key Learning

Manually parsing words out of a string by checking each character against the letter range avoids relying on string splitting utilities that might not handle mixed punctuation and spaces uniformly. The same "commit on boundary, then commit once more after the loop" pattern shows up anywhere characters are grouped by a separator, this isn't unique to this problem.

