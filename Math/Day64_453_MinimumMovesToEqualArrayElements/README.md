\# 453. Minimum Moves to Equal Array Elements



🔗 \[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 64



\## Problem

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal. In one move, you can increment n - 1 elements of the array by 1.



\*\*Examples:\*\*

\- nums = \[1,2,3] → 3 (\[1,2,3] → \[2,3,3] → \[3,4,3] → \[4,4,4])

\- nums = \[1,1,1] → 0



\*\*Constraints:\*\*

\- n == nums.length

\- 1 <= nums.length <= 10^5

\- -10^9 <= nums\[i] <= 10^9

\- The answer is guaranteed to fit in a 32-bit integer



\## Approach

Incrementing n - 1 elements by 1 changes the gaps between elements in exactly the same way as decrementing the one element that was left out. So the problem is the same as: in each move, decrease one element by 1, and find the number of moves needed to make all elements equal.



Under that view, nothing should ever go below the current minimum, so every element has to come down to the minimum value. An element x needs x - min moves, and the total is the sum over all elements of (x - min), which equals sum - n \* min. So the answer comes from one pass to find the minimum and add up the elements.



\## Complexity

\- \*\*Time:\*\* O(n) - one pass to find the minimum and one to compute the sum

\- \*\*Space:\*\* O(1) - only a few variables



\## Key Learning

Changing the point of view turned a confusing operation into a simple one. Raising n - 1 elements is the same as lowering one element relative to the others, so the final target is the minimum, and the answer is the total distance from the minimum. Two implementation details matter. The sum can reach about 10^14, so it must be stored in a long long. And the variable should not be named min, because that hides std::min inside the function.

