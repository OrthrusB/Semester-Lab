# Define the alphabets
upperCase = []
lowerCase = []
for i in range(65, 91):  # A-Z
    upperCase.append(chr(i))
for j in range(97, 123):  # a-z
    lowerCase.append(chr(j))

def encryptMessage(plainText, key):
    cipherText = ''
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shiftedIndex = (index + key) % 26
            cipherText += lowerCase[shiftedIndex]
        elif letter in upperCase:
            index = upperCase.index(letter)
            shiftedIndex = (index + key) % 26
            cipherText += upperCase[shiftedIndex]
        else:
            cipherText += letter
    return cipherText

def decryptMessage(cipherText, key):
    plainText = ''
    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shiftedIndex = (index - key) % 26
            plainText += lowerCase[shiftedIndex]
        elif letter in upperCase:
            index = upperCase.index(letter)
            shiftedIndex = (index - key) % 26
            plainText += upperCase[shiftedIndex]
        else:
            plainText += letter
    return plainText

# Example message and key
message = "Babin Rana"
key = 7

# Encryption
cipherText = encryptMessage(message, key)
print(f"Others will see: {cipherText}")

# Decryption
plainText = decryptMessage(cipherText, key)
print(f"Hidden Message seen by receiver: {plainText}")

