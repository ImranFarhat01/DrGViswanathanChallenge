# 836. Rectangle Overlap

🔗 [View on LeetCode](https://leetcode.com/problems/rectangle-overlap/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 16

## Problem
An axis-aligned rectangle is represented as [x1, y1, x2, y2], where (x1, y1) is the bottom-left corner and (x2, y2) is the top-right corner. Two rectangles overlap only if the area of their intersection is positive; touching at corners or edges does not count as overlapping. Given two rectangles, return true if they overlap, false otherwise.

**Examples:**
- rec1 = [0,0,2,2], rec2 = [1,1,3,3] → true
- rec1 = [0,0,1,1], rec2 = [1,0,2,1] → false
- rec1 = [0,0,1,1], rec2 = [2,2,3,3] → false

**Constraints:**
- rec1.length == 4
- rec2.length == 4
- -10^9 <= rec1[i], rec2[i] <= 10^9
- rec1 and rec2 represent valid rectangles with non-zero area

## Approach
Two rectangles overlap only if they overlap on both the x-axis and the y-axis simultaneously. Instead of directly checking for overlap, it's easier to check the conditions under which they definitely do NOT overlap on each axis, and combine those.

On the x-axis, the rectangles don't overlap if rec2's left edge is at or past rec1's right edge, or rec2's right edge is at or before rec1's left edge. The same logic applies independently on the y-axis. If neither of these no-overlap conditions is true on either axis, the rectangles overlap.

## Complexity
- **Time:** O(1) - a fixed number of comparisons regardless of input values
- **Space:** O(1) - no extra data structures used

## Key Learning
Marked as easy, but took several attempts to get right due to edge cases around rectangles that only touch at an edge or corner (which should NOT count as overlapping). This problem is less about coding and more about correctly translating a geometric definition into strict comparisons: using >= and <= instead of > and < in the no-overlap conditions is what correctly excludes edge-touching cases from being called overlaps. A good reminder that some "easy" problems test mathematical precision and edge-case thinking far more than they test coding ability.
