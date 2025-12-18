import numpy as np

def encryptMessage(plainText, key):
    cipherText = ''
    keylen = int(np.ceil(len(plainText) / len(key)))
    key *= keylen  # Repeat key to match plaintext length
    count = 0
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index + shifter) % 26
            cipherText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count].lower())  # Ensure key is lowercase
            shiftedIndex = (index + shifter) % 26
            cipherText += upperCase[shiftedIndex]
            count += 1
        else:
            cipherText += letter
            count += 1
    return cipherText

def decryptMessage(cipherText, key):
    plainText = ''
    keylen = int(np.ceil(len(cipherText) / len(key)))
    key *= keylen
    count = 0
    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index - shifter) % 26
            plainText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count].lower())
            shiftedIndex = (index - shifter) % 26
            plainText += upperCase[shiftedIndex]
            count += 1
        else:
            plainText += letter
            count += 1
    return plainText

upperCase = [chr(i) for i in range(65, 91)]  # A-Z
lowerCase = [chr(j) for j in range(97, 123)]  # a-z

# Custom message and key
message = "Babin Rana"
key = "code"

# Encryption
cipherText = encryptMessage(message, key)
print(f"Your encrypted Message: {cipherText}")

# Decryption
plainText = decryptMessage(cipherText, key)
print(f"Your hidden message is: {plainText}")