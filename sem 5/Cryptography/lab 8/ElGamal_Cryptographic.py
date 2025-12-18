# Program to encrypt and decrypt a message using ElGamal Cryptographic System
from random import randint

# Function to find a primitive root modulo p
def find_primitive_root(p):
    """
    Find a primitive root modulo p (assumes p is prime).
    
    Args:
        p (int): Prime modulus
    
    Returns:
        int: A primitive root g modulo p, or None if not found
    """
    if p < 2:
        return None
    if p == 2:
        return 1
    phi = p - 1
    factors = {}
    n = phi
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors[i] = factors.get(i, 0) + 1
    if n > 1:
        factors[n] = 1
    
    for g in range(2, p):
        is_primitive = True
        for q in factors:
            if pow(g, phi // q, p) == 1:
                is_primitive = False
                break
        if is_primitive:
            return g
    return None

# Function to generate ElGamal keys
def generate_keys(p):
    """
    Generate ElGamal public and private keys.
    
    Args:
        p (int): Prime modulus
    
    Returns:
        tuple: (public_key, private_key) where public_key = (p, g, h) and private_key = x
    """
    g = find_primitive_root(p)  # Primitive root
    if g is None:
        raise ValueError(f"No primitive root found for p = {p}")
    
    x = randint(1, p - 2)  # Private key (1 < x < p-1)
    h = pow(g, x, p)       # Public key component h = g^x mod p
    
    public_key = (p, g, h)
    private_key = x
    return public_key, private_key

# Function to encrypt a message
def encrypt(message, public_key):
    """
    Encrypt a message using the ElGamal public key.
    
    Args:
        message (str): Plaintext message to encrypt
        public_key (tuple): ElGamal public key (p, g, h)
    
    Returns:
        list: List of ciphertext pairs [(c1, c2), ...]
    """
    p, g, h = public_key
    ciphertexts = []
    
    for char in message:
        m = ord(char)  # Convert character to ASCII value
        k = randint(1, p - 2)  # Random ephemeral key per character
        c1 = pow(g, k, p)      # c1 = g^k mod p
        c2 = (pow(h, k, p) * m) % p  # c2 = h^k * m mod p
        ciphertexts.append((c1, c2))
    
    return ciphertexts

# Function to decrypt a message
def decrypt(ciphertexts, public_key, private_key):
    """
    Decrypt a list of ciphertexts using the ElGamal private key.
    
    Args:
        ciphertexts (list): List of ciphertext pairs [(c1, c2), ...]
        public_key (tuple): ElGamal public key (p, g, h)
        private_key (int): ElGamal private key x
    
    Returns:
        str: Decrypted plaintext message
    """
    p, _, _ = public_key
    x = private_key
    decrypted_chars = []
    
    for c1, c2 in ciphertexts:
        s = pow(c1, x, p)  # Shared secret s = c1^x mod p
        m = (c2 * pow(s, -1, p)) % p  # m = c2 * s^{-1} mod p
        decrypted_chars.append(chr(m))  # Convert ASCII value to character
    
    return ''.join(decrypted_chars)

# Main execution
if __name__ == "__main__":
    # Use a small prime for demonstration (in practice, use a large prime)
    p = 23
    print(f"Using prime modulus p = {p}")
    
    # Generate ElGamal keys
    public_key, private_key = generate_keys(p)
    print(f"Public key: {public_key}")
    print(f"Private key: {private_key}")
    
    # Get message from user
    message = input("Enter message to encrypt: ")
    
    # Encrypt the message
    ciphertexts = encrypt(message, public_key)
    print("Encrypted ciphertexts:", ciphertexts)
    
    # Decrypt the ciphertexts
    decrypted_message = decrypt(ciphertexts, public_key, private_key)
    print("Decrypted message:", decrypted_message)