\# 2469. Convert the Temperature



🔗 \[View on LeetCode](https://leetcode.com/problems/convert-the-temperature/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 65



\## Problem

Given a non-negative floating point number celsius, rounded to two decimal places, convert it to Kelvin and Fahrenheit and return the result as an array \[kelvin, fahrenheit]. Answers within 10^-5 of the actual answer are accepted.



\- Kelvin = Celsius + 273.15

\- Fahrenheit = Celsius \* 1.80 + 32.00



\*\*Examples:\*\*

\- celsius = 36.50 → \[309.65000, 97.70000]

\- celsius = 122.11 → \[395.26000, 251.79800]



\*\*Constraints:\*\*

\- 0 <= celsius <= 1000



\## Approach

Apply the two given formulas directly. Compute celsius + 273.15 for Kelvin and celsius \* 1.80 + 32.00 for Fahrenheit, then return them in that order in a vector of doubles.



\## Complexity

\- \*\*Time:\*\* O(1) - two arithmetic expressions

\- \*\*Space:\*\* O(1) - the output always has exactly two values



\## Key Learning

The only things to watch are the return order (Kelvin first, then Fahrenheit) and the data type. Decimal values like 0.1 cannot be stored exactly in binary floating point, so tiny rounding errors are normal, which is why the problem accepts answers within 10^-5. Using double instead of float keeps the error far below that tolerance. The same result can be written in one line as return {celsius + 273.15, celsius \* 1.80 + 32.00};.

