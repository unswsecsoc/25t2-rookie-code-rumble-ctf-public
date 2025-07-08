# Writeup for `example challenge`

|      author     | category | value |
|-----------------|----------|-------|
|    krishtilani  |    pwn   |  400  |

sample description

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Stack contains several return addresses, we just need overwrite any one of them to be win.
Need to leak PIE ... read will not insert a null byte or newline char in payload, so puts will clobber and leak stack.

### Walkthrough

1. Overwrite RIP to be (call vuln) in main, this should give a PIE leak.
2. We now have another overflow, so set current RIP to itself and overwrite the next RIP to be win.

### Flag(s)

- RCR{h3y_h0w_d1d_y0u_g37_7hr0ugh_0ur_150l4710n_un17}

</details>
