# Abdul Bari's Algorithms playlist
## 1. Introduction to Algorithms
### What is an algorithm?
- An algorithm is a step-by-step procedure for solving a computational problem.
### Differences between an algorithm and a program
| Algorithm | Program 
|:-----|:------:|
| Written at design time | Written at implementation time   |  
| Mainly about domain knowledge | Mainly around the programming itself   |  
| Can use any language to describe (prefer mathematical notion when possible) | Described using the programming language   |  
| Platform independant | Depends on underlying hardware, OS and language used   |  
| We typically analyze the algorithm for quality | We test the program for quality |  
## 1.1 Priori Analysis and Posteriori Testing
### What is priori analysis?
- It is the act of analysing the algorithm by studying it in greater detail. The resulting findings are the time and space consumed by thatt algorithm in terms of some mathematical function.
### What is posteriori testing?
* It is the act of testing the implemented program to track how much time it takes to complete as well as the amount of memory it is consuming.
## 1.2 Characteristics of Algorithms
1. Algorithms can take 0 or more inputs.
2. Algorithms must generate atleast 1 output.
3. Algorithms are definite and leave no room for amiguity.
4. Algorithms, similar to mathematical functions, have definite limits, starting and stopping at definite points.
5. Every statement in an algorithm have an effective purpose.
## 1.3 How to write and Analyze Algorithms
```
Algorithm swap(a, b)
{
    temp = a;
    a = b;
    b = a;
}
```
* We write algorithms with lose pseudocode.
    - No declartions
    - No types
* Writing style is loose, no definite syntax.
    - We can use BEGIN and END instead of { }
    - We can use := or even <- instead of =
* As long as it is readable and understandable, it is fine.
### Criteria for analyzing an algorithm
1. Time in terms of a mathematical function, not watch time.
2. Space in terms of a mathematical function, not actual byte size.
3. Network consumption, for a procedure involving networks.
4. Electrical power consumption, specifically for embedded / small-sized devices.
5. How many CPU registers are being used, in case of device driver code or lower-level system code.
### What is the time and space analysis for the above algorithm?
- Every simple, direct statement in an algorithm takes 1 unit of time.
    - The above algorithm uses 3 simple, direct statements, so let the time function be f(n), f(n) = 3.
    - It is important to highlight that this is rudimentary analysis, and is not meant to reflect the speed of actual machine code. That is deeper analysis handled in the programming phase.
- For space analysis, the amount of variables used is indicative of the amount of space required for this algorithm to run.
    - Again, this is merely rudimentary analysis and is not reflective of how much bytes are actually required to implement this algorithm.
    - In this example, we have 3 variables: a, b and temp. let the space function be s(t), s(t) = 3 words. "Word" expresses some arbitrary data type.
- Whenever a time or space function results in a constant number, we say this this algorithm has a time or space **complexity** order of 1, usually represented as **O(1)**. More on this later.
## 1.4 Frequency Count Method
This is a method that can be helpful in finding a time complexity of an algorithm.
### Example 1
```
// A is an array of elements
// n is the size of the array
Algorithm sum(A, n)
{
    s = 0; // -> 1

    // i = 0 -> 1
    // i < n -> n + 1
    // i++ -> n
    for(i = 0; i < n; i++) -> n + 1
    {
        s = s + A[i]; -> n
    }
    return s; -> 1
}
```
- The time complexity here can be found by assigning 1 unit of time for each statement.
- If a statement is repeated for a certain number of times, we include that in our calculation.
- For a for loop, we set **i = 0** 1 time, we increment **i** for **n** times, and we check the condition for **n + 1** times, because we still have to check that last time that breaks the loop. So, in total we have **2n + 2**, but because this is rudimentary, we do not care much about the exact aggregate for the loop, and you will find that even doing so does not yield a different result for the analysis stage, so we will say that is **n + 1** for for loops, which is generally a safe bet.
- In total: **1 + n + 1 + n + 1 = 2n + 3.** Notice 2 things:
    1. The result of our frequency count method is a polynomial.
    2. The degree of that polynomial is 1.

    Results that satisfy both of the above conditions are said to be "**Order of n**" represented as **O(n)**, more on this later.
- For space complexity, we have **A, n, s, i**. The caveat is that **A** is an array of size **n**, so it represents **n** words instead of 1, combined with **n, s, i** each representing 1 word: s(n) = n + 3. Again, the result is a polynomial of the first degree, meaning space complexity is also an "**Order of n**" or **O(n)**.
### Exanple 2
```
// This algorithm adds 2 square matrices and stores the result in C
Algorithm add(A, B, n)
{
    for(i = 0; i < n; i++) -> n + 1
    {
        for(j = 0; j < n; j++) -> n(n + 1)
        {
            C[i, j] = A[i, j] + B[i, j]; -> n(n)
        }
    }
}
```
- The outer loop itself takes **n + 1** units, the trick here is that everything inside the loop also takes **n** units, and since there is an inner loop, which by itself takes **n + 1** units and executes by the outer **n** times, the inner loop ultimately takes **n * (n + 1)** times, and this is why hot nested loops require finesse. Now, for the statement inside the inner loop, that itself executes for **n** times of the inner loop, as well as repeats **n** times based on the outer loop, resulting in **n * n** units.
- The total result of this is: **(n + 1) + n(n + 1) + n(n) = 2n^2 2n + 1**
    - The degree of this polynomial is 2, so we say that this is **O(n^2)**
- For space complexity, here are our variables:
    - A -> n^2 words
    - B -> n^2 words
    - C -> n^2 words
    - n -> 1 word
    - i -> 1 word
    - j -> 1 word

    So, **S(n) = 3n^2 + 3**, yielding **O(n^2)**.
## Example 3
```
Algorithm multiply(A, B, n)
{
    for(i = 0; i < n; i++) -> n + 1
    {
        for(j = 0; j < n; j++) -> n(n + 1)
        {
            C[i, j] = 0; -> n^2
            for(k = 0; k < n; k++) -> n^2(n + 1)
            {
                c[i, j] = c[i, j] + A[i, k] * B [k, j]; -> n^3
            }
        }
    }
}
```
- The time function here, calculated as before is: **n + 1 + n^2 + n + n^2 + n^3 + n^2 + n^3 = 2n^3 + 3n^2 + 2n + 1**. This is a polynomial of the 3rd degree, yielding **O(n^3)**.
- The systemic idea when analyzing loops is: **Remember that each statement inside a loop that executes *n* times itself executes *n* times**.
- For space complexity, we have:
    - A -> n^2 words
    - B -> n^2 words
    - C -> n^2 words
    - i -> 1 word
    - n -> 1 word
    - j -> 1 word
    - k -> 1 word

    Therefore, **S(n) = 3n^2 + 4** yielding a space complexity of **O(n^2)**.