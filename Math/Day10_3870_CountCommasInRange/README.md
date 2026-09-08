\# 3870. Count Commas in Range



🔗 \[View on LeetCode](https://leetcode.com/problems/count-commas-in-range/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 10



\## Problem

Given an integer n, return the total number of commas used when writing all integers from 1 to n (inclusive) in standard number formatting, where a comma is inserted after every three digits from the right, and numbers with fewer than 4 digits contain no commas.



\*\*Examples:\*\*

\- n = 1002 → 3 ("1,000", "1,001", "1,002" each contribute one comma)

\- n = 998 → 0 (all numbers have fewer than 4 digits)



\*\*Constraints:\*\*

\- 1 <= n <= 10^5



\## Approach

A number gets one comma for every group of three digits beyond the first, from the right. A 4 to 6 digit number gets exactly one comma, a 7 to 9 digit number gets two commas, and so on. So instead of formatting every number and counting commas directly, count how many numbers in the range qualify for at least one comma, then how many qualify for at least two, and so on, adding them all up.



A number qualifies for at least k commas if it has at least 3k+1 digits, meaning it's at least 10^(3k). So for each threshold (1000, 1000000, 1000000000, ...), count how many numbers from that threshold up to n exist (n - threshold + 1), and sum this across all thresholds that are still within range.



\## Complexity

\- \*\*Time:\*\* O(log n) - the loop only runs as many times as there are comma thresholds within range, which grows very slowly

\- \*\*Space:\*\* O(1) - only a running total is tracked



\## Key Learning

Rather than simulating the actual comma placement for every number, the problem reduces to counting how many numbers cross each "comma threshold" (1000, a million, a billion, and so on). Each threshold contributes independently to the total, so the answer is just a sum over a small number of thresholds instead of a loop over every number up to n.

