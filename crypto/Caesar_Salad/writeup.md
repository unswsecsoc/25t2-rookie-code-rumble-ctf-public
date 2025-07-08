# Writeup for `Caesar Salad`

|  author  | category | value |
|----------|----------|-------|
| Williloo |  crypto  |  100  |

A single Caesar Cipher is easy to crack, so I've upped the security by using 100 of them! Try decode this `JUJ0z0o_v1v_qgM_tj3sc_lzJ0MyZ_eQ_l0HfGlUZ_3FUjqHlAgF?0`

## Files

- [src/encrypt-redacted.py](src/encrypt-redacted.py): A program that encrypts the (redacted) flag.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

The `caesarShift` function applies the Caesar cipher to some provided input text with some provided shift value (look up the Caesar cipher if you don't know what it is!). It also replaces `{` and `}` with `0`. If you have a hard time seeing this, you can always copy this function into your own Python program and test with some custom inputs (e.g. `caesarShift("AAAABBBB{}{}CCCC", 4)`).

Importantly, applying the Caesar shift multiple times will just apply one big Caesar shift that's the sum of all the shifts mod 26 (for example a shift of 10 followed by a shift of 25 will give a shift of 35, which is the same as a shift of 35 - 26 = 9). The program applies 100 different random Caesar shifts to our flag; this means it just applies one big Caesar shift to the flag.

Since there are only 26 possible Caesar shifts that can be applied, we just need to bruteforce them all. We find a shift of `k = 18` was used to encrypt the flag, so we can use `k = 8` to decrypt it.

### Walkthrough

Call `caesarShift("JUJ0z0o_v1v_qgM_tj3sc_lzJ0MyZ_eQ_l0HfGlUZ_3FUjqHlAgF?0", 8)` and replace the `0`'s with the appropriate braces.

### Flag(s)

- `RCR{h0w_d1d_yoU_br3ak_thR0UgH_mY_t0PnOtCH_3NCryPtIoN?}`

</details>
