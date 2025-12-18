import numpy as np

# Function to calculate the inverse of a matrix modulo 26
def mod_inverse(matrix, mod):
    det = int(np.round(np.linalg.det(matrix))) % mod
    det_inv = pow(det, -1, mod)  # Modular multiplicative inverse
    matrix_adj = np.round(det * np.linalg.inv(matrix)).astype(int) % mod
    return (det_inv * matrix_adj) % mod

# Function for Hill cipher encryption
def hill_encrypt(plaintext, key):
    mod = 26
    n = len(key)
    # Remove spaces and pad the plaintext to a multiple of the key size
    plaintext = plaintext.replace(" ", "")
    while len(plaintext) % n != 0:
        plaintext += 'X'  # Padding with 'X'
    # Convert plaintext to numerical values
    plaintext_numbers = [ord(char) - ord('A') for char in plaintext.upper()]

    # Encrypt the message
    ciphertext_numbers = []
    for i in range(0, len(plaintext_numbers), n):
        block = np.array(plaintext_numbers[i:i + n])
        encrypted_block = np.dot(key, block) % mod
        ciphertext_numbers.extend(encrypted_block)
    # Convert numerical ciphertext back to letters
    ciphertext = ''.join(chr(num + ord('A')) for num in ciphertext_numbers)
    return ciphertext

# Function for Hill cipher decryption
def hill_decrypt(ciphertext, key):
    mod = 26
    n = len(key)
    # Calculate the inverse of the key matrix modulo 26
    key_inv = mod_inverse(key, mod)

    # Convert ciphertext to numerical values
    ciphertext_numbers = [ord(char) - ord('A') for char in ciphertext.upper()]

    # Decrypt the message
    decrypted_numbers = []
    for i in range(0, len(ciphertext_numbers), n):
        block = np.array(ciphertext_numbers[i:i + n])
        decrypted_block = np.dot(key_inv, block) % mod
        decrypted_numbers.extend(decrypted_block)
    # Convert numerical decrypted message back to letters
    decrypted_text = ''.join(chr(num + ord('A')) for num in decrypted_numbers)
    return decrypted_text

# Example usage
if __name__ == "__main__":
    # Custom message and key
    message = "BABIN RANA"
    key_matrix = np.array([[3, 2], [5, 7]])  # 2x2 matrix key

    # Encryption
    encrypted = hill_encrypt(message, key_matrix)
    print(f"Original Message: {message}")
    print(f"Encrypted: {encrypted}")

    # Decryption
    decrypted = hill_decrypt(encrypted, key_matrix)
    print(f"Decrypted: {decrypted}") 