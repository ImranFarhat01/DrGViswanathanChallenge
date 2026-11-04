\# 904. Fruit Into Baskets



🔗 \[View on LeetCode](https://leetcode.com/problems/fruit-into-baskets/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 67



\## Problem

A row of fruit trees is given as an array fruits, where fruits\[i] is the type of fruit tree i produces. You have two baskets, and each basket holds only one type of fruit (with no limit on quantity). You pick exactly one fruit from every tree, starting at any tree of your choice and moving right, and you must stop at the first tree whose fruit does not fit in your baskets. Return the maximum number of fruits you can pick.



\*\*Examples:\*\*

\- fruits = \[1,2,1] → 3

\- fruits = \[0,1,2,2] → 3 (start at the second tree and pick \[1,2,2])

\- fruits = \[1,2,3,2,2] → 4 (pick \[2,3,2,2])



\*\*Constraints:\*\*

\- 1 <= fruits.length <= 10^5

\- 0 <= fruits\[i] < fruits.length



\## Approach

The rules mean the answer is the length of the longest subarray that contains at most two distinct values. Use a sliding window with two pointers, l and r, and a hash map that stores how many fruits of each type are inside the window.



Move r one step at a time and add fruits\[r] to the map. If the map now holds more than two types, remove one fruit from the left end: decrease the count of fruits\[l], erase that type from the map when its count reaches 0, and move l forward. Whenever the map holds at most two types, the window is valid, so update the answer with its length r - l + 1.



\## Complexity

\- \*\*Time:\*\* O(n) - r moves once per step and l moves at most once per step, with O(1) average hash map work each time

\- \*\*Space:\*\* O(n) in the worst case for this exact version, because the window can stay invalid for several steps and the map can temporarily hold many types. Using a while loop instead of an if (see below) keeps the map at no more than 3 types, which gives O(1) space.



\## Key Learning

This solution shrinks the window with an if instead of a while, so the window never gets smaller. It only slides forward when it is invalid and only grows when it is valid, and the answer is updated only when the window really is valid. This works because the window length always equals the longest valid window seen so far, so it can only grow when a longer valid window appears. The trade-off is that the window may stay invalid for a few steps, so the map can hold extra types. The more standard version, while (mpp.size() > 2), shrinks the window until it is valid again and keeps the map tiny. Both are correct, and knowing why the if version works makes the trick easier to trust.

