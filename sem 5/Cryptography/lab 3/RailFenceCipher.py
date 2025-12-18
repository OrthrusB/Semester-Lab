def encryptMessage(message, key):
    cipherText = ''
    c = 0  # Column index
    r = 0  # Row index
    i = 0  # Message index
    down = True
    # Create a matrix with 'key' rows and message length columns
    matrix = [[None for _ in range(len(message))] for _ in range(key)]
    
    # Fill the matrix in a zigzag pattern
    while c < len(message):
        matrix[r][c] = message[i]
        if down:
            r += 1
        else:
            r -= 1
        if r + 1 == key:  # Switch direction at bottom
            down = False
        elif r == 0:  # Switch direction at top
            down = True
        c += 1
        i += 1
    
    # Print the matrix for visualization (optional)
    for row in matrix:
        print(row)
    
    # Read off the non-None characters row by row
    for row in matrix:
        for item in row:
            if item is not None:
                cipherText += item
    
    return cipherText

# Custom message and key
message = "BABIN RANA"
key = 3

# Encryption
cipherText = encryptMessage(message, key)
print(f"Original Message: {message}")
print(f"Encrypted Message: {cipherText}")