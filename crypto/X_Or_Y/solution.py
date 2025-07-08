# Loop through each of the two lines
for enc in open("src/enc.txt").read().rstrip().split():
    current_char = 0

    key = []
    ciphertext_before_shift = []

    # Loop through every second character, excluding the last
    for i in range(0, len(enc) - 2, 2):
        # XOR the current block of 2 hex digits with the previous 2
        current_char ^= int(enc[i:i+2], 16)
        
        # XOR the first three bytes to get the key
        if i // 2 < 3:
            RCR_ascii = ord("RCR"[i // 2])
            key.append(RCR_ascii ^ current_char)

        # Collect all these characters together
        ciphertext_before_shift.append(current_char)

    # Now XOR with the key, looping mod 3
    for i in range(len(ciphertext_before_shift)):
        print(chr(ciphertext_before_shift[i] ^ key[i % 3]), end="")
    print(" <- possible solution\n\n")