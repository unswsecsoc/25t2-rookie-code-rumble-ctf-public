# Writeup for `X Or Y?`

|  author  | category | value |
|----------|----------|-------|
| Williloo |  crypto  |  100  |

Which message is the real one :)??? Even if you know...can you break my XOR encryption!!!

## Files

- [src/encrypt-redacted.py](src/encrypt-redacted.py): A program which encrypts a redacted flag and key.
- [src/enc.txt](src/enc.txt): The encrypted output of the previous program with the real flag and key.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

First we should analyse what this program is doing: essentially, for two different texts (a flag and a decoy), it loops through each character, XORs it with a key, looping back on the key mod 3, concatenates the entire output together as hex and XORs it with itself shifted left 8 bits.

For example, if the key was "bag" and the flag was "RCR{mhm}", it would XOR (the ASCII values of) "R" and "b", "C" and "a", "R" and "g", then loop back on the key to XOR "{" with "b", "m" with "a", "h" with "g", loop back again and XOR "m" with "b" and "}" with "a" (stopping before it tries "g" again). Now, it will convert each XOR'd pair to a 2-length (zero padded) hex string (e.g. an ASCII value of 81 becomes "51", and "11" becomes "0b") and concatenates everything.

The whole string will be converted into an integer from base-16. Note that because `ord` always returns an 8-bit int, and the "{:02x}" format will always fit it into 2 bytes, the left-shifting by 8 and subsequent XOR will be perfectly align to XOR the previous characters. For example, let's suppose the XORing from the previous paragraph returns `[char1][char2]...[charn]`. Upon left shifting by 8 and XORing, we see that the lined up XOR will look like:

```
       [char1][char2]...       [charn]
[char1][char2][char3]...[charn]
```

This means the first two hex digits from our output string will be from the original XOR, and we can retrieve each subsequent character by XORing it with the previously retrieved one. Now, we can retrieve the key by noting that the flag must start with "RCR", so we can XOR each character with "R", "C" and "R" to get the key (a useful property of XOR is that if `A ^ B = C` then `A = B ^ C`). Now, we just apply the XOR to the rest of the string. As for which of the two strings in `enc.txt` is the FLAG, we can just try the decryption on both and see which yields a sensible output.

### Walkthrough

See [solution.py](solution.py)

### Flag(s)

- `RCR{y_1s_x0r_n0T_s4f3r_bRuH_s4d}`

</details>
