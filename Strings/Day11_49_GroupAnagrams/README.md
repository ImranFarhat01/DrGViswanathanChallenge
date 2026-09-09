\# 49. Group Anagrams



🔗 \[View on LeetCode](https://leetcode.com/problems/group-anagrams/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 11



\## Problem

Given an array of strings strs, group the anagrams together. The answer can be returned in any order.



\*\*Examples:\*\*

\- strs = \["eat","tea","tan","ate","nat","bat"] → \[\["bat"],\["nat","tan"],\["ate","eat","tea"]]

\- strs = \[""] → \[\[""]]

\- strs = \["a"] → \[\["a"]]



\*\*Constraints:\*\*

\- 1 <= strs.length <= 10^4

\- 0 <= strs\[i].length <= 100

\- strs\[i] consists of lowercase English letters



\## Approach

All anagrams of each other produce the exact same string when their characters are sorted (e.g. "eat", "tea", and "ate" all sort to "aet"). This sorted string can be used as a canonical key to group anagrams together.



For each string in strs, create a sorted copy of it and use that as a key in a hash map, pushing the original (unsorted) string into the map's value list for that key. Once every string has been processed, each value in the map is a group of anagrams. Collect all the map's values into the final answer.



\## Complexity

\- \*\*Time:\*\* O(n \* k log k) - for n strings each of length up to k, sorting each string takes O(k log k), done n times

\- \*\*Space:\*\* O(n \* k) - the hash map stores every string across all its keys



\## Key Learning

Finding a canonical representation for a group of equivalent items (here, the sorted version of a string) is a common pattern for grouping problems. Instead of comparing every pair of strings to check if they're anagrams (which would be far more expensive), each string is mapped to a single "fingerprint," and everything sharing the same fingerprint automatically belongs together.

