import math
from random import randint

# Function to calculate GCD
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
    
    # For p = 2, the only primitive root is 1
    if p == 2:
        return 1

    # Compute phi(p) = p - 1
    phi = p - 1
    
    # Get prime factors of p - 1
    factors = prime_factors(phi)
    
    # Test numbers from 2 to p-1
    for g in range(2, p):
        is_primitive = True
        # Check g^((p-1)/q) != 1 mod p for each prime factor q
        for q in factors:
            exponent = phi // q
            if pow(g, exponent, p) == 1:
                is_primitive = False
                break
        if is_primitive:
            return g
    return None  # Shouldn't happen for a prime p

# Main function to test
def main():
    # Test with some prime numbers
    test_primes = [5, 7, 11, 13, 17]
    
    for p in test_primes:
        root = find_primitive_root(p)
        if root is not None:
            print(f"Primitive root modulo {p} is {root}")
            # Verify by printing powers (optional)
            powers = [pow(root, i, p) for i in range(1, p)]
            print(f"Powers of {root} mod {p}: {powers}")
        else:
            print(f"No primitive root found for {p} (should not happen for prime)")

if __name__ == "__main__":
    main()