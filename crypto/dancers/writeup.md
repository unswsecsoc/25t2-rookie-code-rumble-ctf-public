# Writeup for `dancers`

|  author  | category | value |
|----------|----------|-------|
| dprakosa |  crypto  |  100  |

You have discovered a mysterious letter filled with strange drawings of dancers... What could it possibly mean?... Enclose your flag with RCR{} and use underscores between words.

## Files

- [src/message.png](src/message.png): The mysterious letter with strange drawings of dancers.
- [src/guide.png](src/guide.png): A guide seemingly mapping each dancer to a letter.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

The flag is encrypted with the Sherlock Holmes' [dancing man cipher](https://rumkin.com/tools/cipher/dancing-men/). Don't worry if you couldn't figure this out; we provided a guide that allows you to easily substitute each stick figure with the corresponding letter!

### Walkthrough

1. Go through each stick figure left to right, top to bottom in [message.png](message.png).
2. Replace each stick figure with letter that it's labeled with around a box in [guide.png](guide.png).
3. Enclose the string with the flag format as `RCR{<decrypted message here>}`.

### Flag(s)

- `RCR{master_cipher_detective}`

</details>
