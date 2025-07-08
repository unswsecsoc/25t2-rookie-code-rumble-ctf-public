# Writeup for `example challenge`

|      author     | category | value |
|-----------------|----------|-------|
|    krishtilani  |    pwn   |  500  |

sample description

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Overwrite RBP to be some address close to GOT.
Name variable is set at RBP-0x70, obtain a libc leak through the %s.
Use a one gadget to pop a shell (for some reason ret2system didnt work for me)

### Walkthrough

1. Overwrite rbp, with 0x404110 and ret to main+213
2. Obtain _IO_2_1_stdin_ leak, and then set one gadget conditions correctly to pop a shell.

### Flag(s)

- RCR{rbp_f1nn4_b3_7w34k1n9_4f73r_7h053_p1v07s}

</details>
