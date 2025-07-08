import random

## MY TOP SECRET KEY :P
KEY = "key"

## Make a 32 byte flag and a secret decoy of the same length :P
FLAG = "RCR{y_1s_x0r_n0T_s4f3r_bRuH_s4d}"
DECOY = ''.join([chr(random.randint(0, 255)) for i in range(32)])

def encrypt(text):
    etext = ''
    i = 0

    ## XOR every characters one at a time
    for char in text:
        encoded = ord(char) ^ ord(KEY[i % 3])

        etext += f"{encoded:02x}"
        i += 1

    etext = int(etext, 16)
    etext = (etext ^ (etext << 8))
    return hex(etext)[2:]

messages = [encrypt(FLAG), encrypt(DECOY)]

with open('enc.txt', 'w') as f:
    i = random.randint(0, 1)

    ## Make sure I write the messages to output file in a random order
    f.write(messages[i])
    f.write('\n')
    f.write(messages[(i + 1) % 2])