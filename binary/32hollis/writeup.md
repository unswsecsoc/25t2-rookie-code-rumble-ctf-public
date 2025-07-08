# Writeup for `32hollis`

|    author   | category | value |
|-------------|----------|-------|
| mbvsthewrld |  binary  |   50  |

2hollis is back in Sydney, but I slept through my alarms and now I'm in a dogfight for the last ticket to his concert. Can you win the auction and get it for me? Oh also buy me a pen, I wanna get something signed.
You can run the code [here](https://cgi.cse.unsw.edu.au/~cs1521/mipsy/) and open the documentation [here](https://cgi.cse.unsw.edu.au/~cs1521/24T2/resources/mips-guide.html). There is also a VS Code extension with functionality similar to the website except for the added benefit of convenient breakpoints. The decompiled code and data views will come in handy to visualise the memory layout.


| cost |                                                                    content                                                                     |
|------|------------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Try your hand at breaking the program. Look for any edge cases that haven't been accounted for in the code, then test it out on the MIPSY IDE. |

## Files

- [src/chal.c](src/chal.c): Translation of the source code in C, to help understand the code a little better for those new to assembly.
- [src/chal.s](src/chal.s): Challenge source code.
- [Dockerfile](Dockerfile): Dockerfile.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

As hinted in the name of the challenge and the description and randomly throughout the source code, the main idea here was exploiting an integer overflow vulnerability when dealing with adding unsigned integers.
Specifically, the `addu` instruction in MIPS allows for integer wraparound, which lets us win the auction by making the rival’s bid go negative. This only happens if we bid 2^31 - 1 (i.e. 2147483647), the largest signed 32-bit integer.
When the rival bids one more, it'll trigger this.

### Walkthrough

Bid $2147483647.

### Flag(s)

- `RCR{h0ll1s_s1GN_MY_inT3g3r_plzd10c42}`

</details>
