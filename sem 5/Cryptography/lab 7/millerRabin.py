from random import randint
import math

def miller_rabin(n, a):
    # Handle base cases
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False

    # Write n-1 as 2^k * m where m is odd
    k = 0
    m = n - 1
    while m % 2 == 0:
        m //= 2
        k += 1

    # Witness test
    T = pow(a, m, n)  # a^m mod n
    if T == 1 or T == n - 1:
        return True
    
    for _ in range(k - 1):
        T = pow(T, 2, n)  # T^2 mod n
        if T == n - 1:
            return True
        if T == 1:
            return False
    return False

def main():
    n = 5
    a = randint(1, n - 1)
    isprime = miller_rabin(n, a)
    print(f"n = {n}, a = {a}")
    if isprime:
        print(f"{n} is probably prime")
    else:
        print(f"{n} is composite")

if __name__ == "__main__":
    main()