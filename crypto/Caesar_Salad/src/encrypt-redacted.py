import random

FLAG = 'RCR{REDACTED}'
LOWER_LETTERS = 'abcdefghijklmnopqrstuvwxyz'
UPPER_LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


## Rotate every letter by k amounts!!!
def caesarShift(message, k):
    encoded_message = ''

    ## Encode each character:
    ##      - Replace spaces with '0'
    ##      - Shift each character by k, looping around if we have to
    ##      - Case is maintained
    for character in message:
        if character == '{' or character == '}':
            encoded_message += '0'
        elif character.islower():
            letter_position = LOWER_LETTERS.index(character)
            encoded_message += LOWER_LETTERS[(letter_position + k) % 26]    ## Shift the letter by k characters
        elif character.isupper():
            letter_position = UPPER_LETTERS.index(character)
            encoded_message += UPPER_LETTERS[(letter_position + k) % 26]    ## Shift the letter by k characters
        else:
            encoded_message += character                                    ## Leave other characters as they are
    
    return encoded_message

## Pass the message through 100 Caesar shifts!
def encodeMessage(message):
    secret_keys = []
    
    ## You'll never break my encryption!!!
    ## 100 secret keys means 26^100 possible outcomes!!!!
    for i in range(100):
        secret_keys.append(random.randint(1, 25))
    
    encoded_text = message
    for key in secret_keys:
        encoded_text = caesarShift(encoded_text, key)
    
    return encoded_text

## Get my encoded message!!
print(encodeMessage(FLAG))