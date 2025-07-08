# Writeup for `Clink Clank`

|  author  |  category | value |
|----------|-----------|-------|
| Williloo | reversing |  100  |

Chugga Chugga Choo Choo! Steam trains are pretty ancient, so we've *gets hit by a train*

## Files

- [src/train](src/train): A compiled version of the below program... with the real flag...
- [src/obfuscated_train.c](src/obfuscated_train.c): Obfuscated C code of some program that generates IDs and checks from the user that they're correct. 

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

There's many ways to do this challenge ~~including `grep`ing for the flag prefix or running `strings` but we won't talk about this :D~~, but all methods that involve reversing center around the idea that the program is creating a linked list.

We can see this because the `xremesmiaslg` struct contains a pointer to another `xremesmiaslg` struct. To figure out how the values of the linked list node are populated, we observe these lines:
```c
        int bwkayyyhyfrc=dasuofisfidhfs->retcoxeoszlz;
        bwkayyyhyfrc=(bwkayyyhyfrc *173) % 213;
```

Each node's `bwkayyyhyfrc` field is set by the node creating function `vpasokdisascp`, which initially is given a value of `15`, after which point subsequent of `bwkayyyhyfrc` are passed into this function. Thus we can just calculate the sequence of carriage ID's by starting from `15`, calculating the next number as `(15 * 173) % 213 -> 39`, and then `(39 * 173) % 213` and so on.

### Walkthrough

1. Run the binary (you'll need a Linux machine/vm/emulator or WSL, or run it on a CSE computer).
2. Calculate the correct sequence of ID's from the above recurrence as `15, 39, 144, 204, 147`.
3. Input each of these numbers into each carriage ID input prompt.
4. Read the resulting flag after entering five numbers.

(you could also progressively bruteforce each carriage ID by repeatedly rerunning the program with a script since each of these numbers remain constant when executing the program)

### Flag(s)

- `RCR{kn0W_y0Ur_L1nK3D_L15Ts_w3lL}`

</details>
