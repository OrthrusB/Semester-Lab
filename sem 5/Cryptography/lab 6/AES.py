from Crypto.Cipher import AES
import binascii
import os

def pad(text):
    """PKCS#5/PKCS#7 padding to ensure text length is a multiple of 16 bytes"""
    padding_len = 16 - (len(text) % 16)
    padding = chr(padding_len) * padding_len
    return text + padding

def unpad(text):
    """Remove PKCS#5/PKCS#7 padding"""
    padding_len = ord(text[-1])
    return text[:-padding_len]

def aes_encrypt(plaintext, key):
    key = key.ljust(16, b'\0')[:16]  # Ensure 16-byte key for AES-128
    iv = os.urandom(16)  # Random 16-byte IV
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_text = pad(plaintext).encode()
    encrypted_text = cipher.encrypt(padded_text)
    return binascii.hexlify(iv + encrypted_text).decode()  # Hex string output

def aes_decrypt(ciphertext, key):
    key = key.ljust(16, b'\0')[:16]  # Ensure 16-byte key for AES-128
    ciphertext = binascii.unhexlify(ciphertext)  # Convert hex to bytes
    iv, encrypted_text = ciphertext[:16], ciphertext[16:]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_text = cipher.decrypt(encrypted_text).decode()
    return unpad(decrypted_text)  # Remove padding

# Custom message and key
key = b"MySecretKey12345"  # 16-byte key
plaintext = "BABIN RANA"

# Encryption
ciphertext = aes_encrypt(plaintext, key)
print(f"Ciphertext: {ciphertext}")

# Decryption
decrypted_text = aes_decrypt(ciphertext, key)
print(f"Decrypted text: {decrypted_text}")