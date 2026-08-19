# Abdul Bari's Algorithms playlist
Kindly support Abdul Bari; He's helped countless engineers to ramp up their algo game!

[Playlist Source](https://youtube.com/playlist?list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&si=BANU3m-emLN1aG5B)
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
* We write algorithms with loose pseudocode.
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
### Example 2
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
### Example 3
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
## 1.5.1 Time Complexity #1
### Example 1
```
for(int i = 0; i < n; i++) // n + 1
{
    statement; // n
}
```
- In such a case, we only really care about how many times the inner statements execute, in this case it is **n** times, therefore **O(n)**.
### Example 2
```
for(int i = n; i > 0; i--)
{
    statement; // n
}
```
- It does not matter what the loop does, incremenet or decrement, the amount of steps is still **n**.
### Example 3
```
for(int i = 1; i < n; i = i + 2)
{
    statement; // n / 2
}
```
- This is different, notice we have cut the number of steps by half, through incrementing at twice the speed, essentially.
- So **f(n) = n / 2**, but the degree of this polynomial is **n**. This is actually still classified as **O(n)**.
### Example 4
```
for(int i = 0; i < n; i++) // n + 1
{
    for(int j = 0; j < n; j++) // n * (n + 1)
    {
        statement; // n * n
    }
}
```
- Revisiting this again, the way of thinking here is: **The number of repitions in the outermost loop influences the inner statements, this is hierarchical until we derive the simple, direct statements' frequency.**
- This is **O(n^2)**, as established previously.
### Example 5
```
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < i; j++)
    {
        statement;
    }
}
```
- To analyze this logically, let us trace our values:

    | i | j | statement execution times |
    |:---:|:---:|:--------------------------:|
    | 0 | 0 | 0 |
    | 1 | 0 | 1 |
    | 2 | 0,1 | 2 |
    | 3 | 0,1,2 | 3 |
    | n | 0,1,2,...,n | n |

    Each row here is an iteration, so we can say that our statement executed **1 + 2 + 3 + 4 + 5 + .... + n**  times. Mathematically, this is a series representable by the following function: **f(n) = n(n+1) / 2**. This polynomial is of the 2nd degree. So the time complexity here is still O(n^2) despite the implementation difference.
### Example 6
```
p = 0
for(int i = 1; p <= n; i++)
{
    p = p + i;
}
```
- Lets trace this like before:

    | i | p |
    |:-:|:-:|
    |1|0 + 1 = 1|
    |2|1 + 2 = 3|
    |3|3 + 3 = 6|
    |k|6 + 7 + 8 + ... + k|

    There is a very subtle detail here that bears emphasising, the reason why we didn't include the number of executions of the statement is that **we don't know.** Observe the stopping condition, we require p <= n, so we will only stop when p > n, right? Can you reliably answer when exactly p > n occurs? The answer to this, **at the algorithm analysis stage** is no.
    
    It is important to appreeciate this idea that for algorithm analysis, we do not possess all the facts, because naturally we do not infer any implementation details other than the broad steps needed to be taken. We can make an abstract mathematical assumption, that by the time p > n, i has executed for **k** times, this means that p itself has had a series of sums up to **k**.

    Since we can express that series in a different form, we can say that **p = k(k+1) / 2**

    Therefore after the final iteration, **k(k+1) / 2 > n**

    Multiply by 2: **k(k+1) > 2n**

    Move to quadratic form: **k^2 + k - 2n > 0**

    Solve for the positive root: **k > ((8n + 1)^0.5 - 1) / 2**

    We have managed to solve for **k**, at the conversion point from negative to positive; In algorithm analysis, we care less about the constants in the expression, and care more about the growth of the variable factor. If we imagine that **n** has grown so large that the other factors in the equation are negligible, we can say: **k = Phi(n^0.5)**. Where **Phi** wraps all of our constants, and in this way we have defined the relation between **k** and **n**.

    This concept, of thematically stripping away the noise around the variable factor, is know as the **asymptotic form** of our relation. It has the neat property of simmering down the equation to the most important idea: **Our resulting polynomial has a degree of 0.5, a square root**.

    That is why, for this algorithm, we say that the time complexity is O(ROOT(n)). Considering the mathematical significance here, we can see that this does a lot less work than an O(n) solution. 