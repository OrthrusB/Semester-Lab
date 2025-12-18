import math

def additive_inverse(a, m):
    """Finds the additive inverse of 'a' under modulo 'm' """
    return (-a) % m

def gcd_extended(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x1, y1 = gcd_extended(b % a, a)
        x = y1 - (b // a) * x1
        y = x1
        return gcd, x, y

def multiplicative_inverse(a, m):
    gcd, x, _ = gcd_extended(a, m)
    if gcd != 1:
        return None  # No inverse exists if a and m are not coprime
    else:
        return x % m

def is_relatively_prime(a, b):
    return math.gcd(a, b) == 1

# Example inputs
a, m = 3, 7

# Output results
print(f"Additive inverse of {a} mod {m}: {additive_inverse(a, m)}")
print(f"Multiplicative inverse of {a} mod {m}: {multiplicative_inverse(a, m)}")
print(f"Are {a} and {m} relatively prime? {is_relatively_prime(a, m)}") 