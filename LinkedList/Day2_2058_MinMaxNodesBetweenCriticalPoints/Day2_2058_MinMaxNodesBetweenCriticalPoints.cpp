# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

🔗 [View on LeetCode](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 2

## Problem
A critical point in a linked list is a node that is either a local maxima (strictly greater than both neighbors) or a local minima (strictly smaller than both neighbors). A node can only be a critical point if it has both a previous and a next node.

Given the head of a linked list, return [minDistance, maxDistance] representing the minimum and maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

**Examples:**
- head = [3,1] → [-1,-1] (no critical points)
- head = [5,3,1,2,5,1,2] → [1,3]
- head = [1,3,2,2,3,2,2,2,7] → [3,3]

**Constraints:**
- The number of nodes is in the range [2, 10^5]
- 1 <= Node.val <= 10^5

## Approach
Traverse the list once, tracking the previous, current, and next node values along with the current node's position. Whenever a node qualifies as a local maxima or minima:
- If it's the first critical point found, record its position (as both the first and previous critical point position).
- Otherwise, compute the distance from the last critical point and update the minimum distance if it's smaller.

The maximum distance is simply the position of the last critical point minus the position of the first one, since critical points are found in order during a single pass.

## Complexity
- **Time:** O(n) - single pass through the list
- **Space:** O(1) - only a few pointers and counters used

## Key Learning
Minimum distance between critical points only needs to be checked against the *immediately previous* critical point, since critical points are discovered in increasing position order during the traversal - no need to store all of them. Maximum distance, by contrast, only needs the very first and very last critical point positions.