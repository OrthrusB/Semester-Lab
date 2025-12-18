import numpy as np

def findIndex(matrix, letter):
    for r in range(5):
        for c in range(5):
            if matrix[r][c] == letter:
                return (r, c)
    return None

def generateMatrix(key):
    matrix = []
    key = key.upper().replace('J', 'I')  # Treat J as I
    for char in key:
        if char not in matrix and char.isalpha():
            matrix.append(char)
    for letter in 'ABCDEFGHIKLMNOPQRSTUVWXYZ':  # Exclude J
        if letter not in matrix:
            matrix.append(letter)
    keyMatrix = [[matrix[i * 5 + j] for j in range(5)] for i in range(5)]
    return keyMatrix

def encryptMessage(message, key):
    keyMatrix = generateMatrix(key)
    message = message.upper().replace(" ", "").replace("J", "I")
    message = list(message)
    cipherText = ''
    
    i = 0
    while i < len(message):
        digraph = [message[i]]
        if i + 1 < len(message):
            digraph.append(message[i + 1])
        else:
            digraph.append('X')
            i -= 1  # Adjust for single letter
        if digraph[0] == digraph[1]:
            digraph[1] = 'X' if digraph[0] != 'X' else 'Q'
            i += 1
        else:
            i += 2
        
        r1, c1 = findIndex(keyMatrix, digraph[0])
        r2, c2 = findIndex(keyMatrix, digraph[1])
        
        if r1 == r2:  # Same row
            cipherText += keyMatrix[r1][(c1 + 1) % 5]
            cipherText += keyMatrix[r2][(c2 + 1) % 5]
        elif c1 == c2:  # Same column
            cipherText += keyMatrix[(r1 + 1) % 5][c1]
            cipherText += keyMatrix[(r2 + 1) % 5][c2]
        else:  # Rectangle
            cipherText += keyMatrix[r1][c2]
            cipherText += keyMatrix[r2][c1]
    
    return cipherText

# Custom message and key
message = "Babin Rana"
key = "secure"

# Encryption
cipherText = encryptMessage(message, key)
print(f"Original Message: {message}")
print(f"Encrypted Message: {cipherText}")