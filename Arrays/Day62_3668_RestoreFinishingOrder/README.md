\# 3668. Restore Finishing Order



🔗 \[View on LeetCode](https://leetcode.com/problems/restore-finishing-order/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 62



\## Problem

Given an array order that lists every participant ID from 1 to n in the order they finished a race, and an array friends containing the IDs of your friends (sorted in increasing order), return your friends' IDs in the order they finished.



\*\*Examples:\*\*

\- order = \[3,1,2,5,4], friends = \[1,3,4] → \[3,1,4]

\- order = \[1,4,5,3,2], friends = \[2,5] → \[5,2]



\*\*Constraints:\*\*

\- 1 <= n == order.length <= 100

\- order contains every integer from 1 to n exactly once

\- 1 <= friends.length <= min(8, n)

\- 1 <= friends\[i] <= n

\- friends is strictly increasing



\## Approach

The finishing order is already stored in order, so the task is to filter it. Walk through order from the first finisher to the last. For each participant, check whether their ID appears in friends, and if it does, add it to the answer. Because order is scanned from first place to last, the friends come out in finishing order automatically. The inner loop stops as soon as a match is found.



\## Complexity

\- \*\*Time:\*\* O(n \* f), where f is the number of friends. Since f is at most 8, this is effectively O(n)

\- \*\*Space:\*\* O(f) for the output array



\## Key Learning

Filtering a sequence while keeping its order only needs a membership check, no sorting. The tiny size of friends (at most 8) makes the nested loop perfectly fine. For larger inputs, mark the friends in a boolean array of size n + 1 first, so each membership check becomes a single array lookup and the whole solution runs in true O(n) time.

