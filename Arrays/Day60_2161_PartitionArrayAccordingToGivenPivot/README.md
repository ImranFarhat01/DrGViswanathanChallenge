# 2161. Partition Array According to Given Pivot

🔗 [View on LeetCode](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 60

## Problem
Given a 0-indexed integer array nums and an integer pivot, rearrange nums so that every element less than pivot comes first, every element equal to pivot comes in the middle, and every element greater than pivot comes last. The relative order of the elements less than pivot, and of the elements greater than pivot, must stay the same as in the original array. Return the rearranged array.

**Examples:**
- nums = [9,12,5,10,14,3,10], pivot = 10 → [9,5,3,10,10,12,14]
- nums = [-3,4,3,2], pivot = 2 → [-3,2,4,3]

**Constraints:**
- 1 <= nums.length <= 10^5
- -10^6 <= nums[i] <= 10^6
- pivot equals an element of nums

## Approach
Because the relative order must be preserved, an in-place swap based partition (like the one in quicksort) is not suitable, since it can reorder elements within a group. Instead, build the answer in order from three groups.

Scan the array once, in order, and push every element smaller than pivot into one list and every element greater than pivot into another. Then scan again and append every element equal to pivot after the smaller ones. Finally, append the greater list at the end. Each group keeps the order in which its elements appeared, and the groups are placed in the required order: smaller, equal, greater.

## Complexity
- **Time:** O(n) - two linear passes over the array plus one concatenation
- **Space:** O(n) - the two helper lists together hold all the elements

## Key Learning
The word "stable" is what decides the approach here. Standard in-place partitioning is fast but not stable, so it breaks the ordering rule. Collecting the groups separately, in the order they are seen, keeps the relative order automatically. The equal elements could also be counted instead of copied, since they are all identical: count them in the first pass, then append that many copies of pivot. That removes the second scan and still gives a single O(n) pass.
