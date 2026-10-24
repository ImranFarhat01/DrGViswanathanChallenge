# 2409. Count Days Spent Together

🔗 [View on LeetCode](https://leetcode.com/problems/count-days-spent-together/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 56

## Problem
Alice and Bob are in Rome on separate business trips. Given four strings arriveAlice, leaveAlice, arriveBob and leaveBob, each in the format "MM-DD", with both ends inclusive, return the number of days they are in Rome together. All dates are in the same non-leap year.

**Examples:**
- arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19" → 3 (August 16, 17 and 18)
- arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31" → 0

**Constraints:**
- All dates are in the format "MM-DD"
- Each arrival date is earlier than or equal to the matching leaving date
- All dates are valid dates in a non-leap year

## Approach
The time they spend together is the overlap of two intervals. The overlap starts at the later of the two arrivals and ends at the earlier of the two departures. Because every date is a fixed-width "MM-DD" string, comparing the strings alphabetically gives the same result as comparing the dates, so max() and min() work directly on the strings.

If the start is after the end, the intervals do not overlap and the answer is 0. Otherwise, convert both dates to a day of the year by adding the days in all the months before the current one, then return end - start + 1 (the +1 makes both ends inclusive).

## Complexity
- **Time:** O(1) - the loops run at most 12 times, regardless of the input
- **Space:** O(1) - a fixed array of 12 month lengths

## Key Learning
Two things make this short. First, fixed-width date strings sort the same way as dates, so no parsing is needed just to find the overlap. Second, the overlap of two intervals is always [max of starts, min of ends], and its length is end - start + 1 when that range is valid. Converting to a day of the year turns a calendar problem into plain subtraction, and since the year is not a leap year, February is always 28 days.
