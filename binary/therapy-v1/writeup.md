# Writeup for `example challenge`

|      author     | category | value |
|-----------------|----------|-------|
|    krishtilani  |    pwn   |  300  |

sample description

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Flag is on the stack in plaintext, and format string vuln.
%p through the stack, and then decode the relevant parts to obtain the flag.

### Walkthrough

1. send '%6$p %7$p %8$p %9$p' as those are the parts of the flag.
2. decode.

### Flag(s)

- RCR{p33kab00_f0rm47_s33_thr0ugh}

</details>
