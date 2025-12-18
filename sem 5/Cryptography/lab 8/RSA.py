# Program to encrypt and decrypt a message using RSA Algorithm

def generate_keys(p, q):
    """
    Generate RSA public and private keys from two prime numbers p and q.
    
    Args:
        p (int): First prime number
        q (int): Second prime number
    
    Returns:
        tuple: (public_key, private_key) where public_key = (e, n) and private_key = (d, n)
    """
    n = p * q  # Modulus for both keys
    phi = (p - 1) * (q - 1)  # Euler's totient function φ(n)
    e = 17  # Public exponent, chosen such that gcd(e, phi) == 1
    d = pow(e, -1, phi)  # Private exponent, modular inverse of e modulo phi
    return (e, n), (d, n)

def encrypt(message, public_key):
    """
    Encrypt a message using the RSA public key.
    
    Args:
        message (str): The plaintext message to encrypt
        public_key (tuple): RSA public key (e, n)
    
    Returns:
        list: List of ciphertexts (integers)
    """
    e, n = public_key
    # Convert each character to its ASCII value and encrypt: c = m^e mod n
    ciphertexts = [pow(ord(char), e, n) for char in message]
    return ciphertexts

def decrypt(ciphertexts, private_key):
    """
    Decrypt a list of ciphertexts using the RSA private key.
    
    Args:
        ciphertexts (list): List of encrypted integers
        private_key (tuple): RSA private key (d, n)
    
    Returns:
        str: Decrypted plaintext message
    """
    d, n = private_key
    # Decrypt each ciphertext to its ASCII value and convert to character: m = c^d mod n
    decrypted_chars = [chr(pow(c, d, n)) for c in ciphertexts]
    return ''.join(decrypted_chars)

if __name__ == "__main__":
    # Hardcoded prime numbers for demonstration
    p = 61
    q = 53
    print(f"Using primes p = {p} and q = {q}")
    
    # Generate RSA keys
    public_key, private_key = generate_keys(p, q)
    print(f"Public key: {public_key}")
    print(f"Private key: {private_key}")
    
    # Get message from user
    message = input("Enter message to encrypt: ")
    
    # Encrypt the message
    ciphertexts = encrypt(message, public_key)
    print("Encrypted ciphertexts:", ' '.join(map(str, ciphertexts)))
    
    # Decrypt the ciphertexts
    decrypted_message = decrypt(ciphertexts, private_key)
    print("Decrypted message:", decrypted_message)