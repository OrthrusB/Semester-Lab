import math
from random import randint

# Function to calculate GCD (for completeness, though not used directly here)
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to factorize a number into prime factors
def prime_factors(n):
    factors = {}
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors[i] = factors.get(i, 0) + 1
    if n > 1:
        factors[n] = 1
    return factors

# Function to find a primitive root modulo p (assumes p is prime)
def find_primitive_root(p):
    if p < 2:
        return None
    if p == 2:
        return 1
    phi = p - 1
    factors = prime_factors(phi)
    for g in range(2, p):
        is_primitive = True
        for q in factors:
            exponent = phi // q
            if pow(g, exponent, p) == 1:
                is_primitive = False
                break
        if is_primitive:
            return g
    return None

# Diffie-Hellman key exchange simulation
def diffie_hellman(p):
    # Step 1: Find a primitive root g modulo p
    g = find_primitive_root(p)
    if g is None:
        print(f"Could not find a primitive root for p = {p}")
        return
    
    print(f"Prime modulus p = {p}, Primitive root g = {g}")
    
    # Step 2: Alice and Bob choose private keys (random integers < p)
    alice_private = randint(1, p - 1)
    bob_private = randint(1, p - 1)
    print(f"Alice's private key = {alice_private}")
    print(f"Bob's private key = {bob_private}")
    
    # Step 3: Compute public keys
    alice_public = pow(g, alice_private, p)  # g^(alice_private) mod p
    bob_public = pow(g, bob_private, p)      # g^(bob_private) mod p
    print(f"Alice's public key = {alice_public}")
    print(f"Bob's public key = {bob_public}")
    
    # Step 4: Exchange public keys and compute shared secret
    alice_shared = pow(bob_public, alice_private, p)  # (bob_public)^(alice_private) mod p
    bob_shared = pow(alice_public, bob_private, p)    # (alice_public)^(bob_private) mod p
    print(f"Alice's computed shared secret = {alice_shared}")
    print(f"Bob's computed shared secret = {bob_shared}")
    
    # Step 5: Verify they match
    if alice_shared == bob_shared:
        print(f"Success! Shared secret is {alice_shared}")
    else:
        print("Error: Shared secrets do not match!")

# Main function to test
def main():
    # Test with a small prime (in practice, use a large prime)
    test_primes = [17, 23]
    for p in test_primes:
        print("\n--- Diffie-Hellman Key Exchange ---")
        diffie_hellman(p)

if __name__ == "__main__":
    main()