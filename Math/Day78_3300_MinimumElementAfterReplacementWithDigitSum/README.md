\# 3300. Minimum Element After Replacement With Digit Sum



🔗 \[View on LeetCode](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 78



\## Problem

Given an integer array nums, replace each element with the sum of its digits, then return the minimum element of the resulting array.



\*\*Examples:\*\*

\- nums = \[10,12,13,14] → 1 (the array becomes \[1,3,4,5])

\- nums = \[1,2,3,4] → 1 (single digit numbers stay the same)

\- nums = \[999,19,199] → 10 (the array becomes \[27,10,19])



\*\*Constraints:\*\*

\- 1 <= nums.length <= 100

\- 1 <= nums\[i] <= 10^4



\## Approach

There is no need to build the replaced array. For each number, compute its digit sum by repeatedly taking the last digit with % 10, adding it to a running sum, and dropping it with / 10. Compare that digit sum with the smallest one seen so far and keep the smaller. After the last element, the smallest digit sum is the answer.



\## Complexity

\- \*\*Time:\*\* O(n \* d), where d is the number of digits in each element. Since nums\[i] is at most 10^4, d is at most 5, so this is effectively O(n)

\- \*\*Space:\*\* O(1) - only a few integer variables



\## Key Learning

Replacing every element and then finding the minimum is the same as finding the minimum of the digit sums, so the replaced array never has to exist. Tracking a running minimum while computing each digit sum saves a whole pass and the extra memory. The modulo and division loop is the same digit extraction building block used in earlier problems, such as the index and digit sum problem from Day 26, and it keeps showing up in digit based questions.

