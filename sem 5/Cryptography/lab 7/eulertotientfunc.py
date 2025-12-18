import collections

def prime_factors(n):
    i=2
    factors=[]
    while i*i<=n:
        if n%i:
            i+=1
        else:
            n//=i
            factors.append(i)
    if n>1:
        factors.append(n)

    e=collections.Counter(factors)
    return dict(e)

def etf(m):
    factors=prime_factors(m)
    prdt=1

    for key in factors:
        p=int(key)
        e=int(factors[key])
        prdt=prdt*(p**e-p**(e-1))
    return prdt

import collections

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    e = collections.Counter(factors)
    return dict(e)

def etf(m):
    factors = prime_factors(m)
    prdt = 1
    for key in factors:
        p = int(key)
        e = int(factors[key])
        prdt = prdt * (p**e - p**(e-1))
    return prdt

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def main():
    test_numbers = [12, 9, 7, 20]
    for num in test_numbers:
        result = etf(num)
        print(f"φ({num}) = {result}")

        # Find a number 'a' coprime to 'num'
        a = 1
        while gcd(a, num) != 1:
            a += 1
        
        # Test Euler's theorem: a^φ(m) ≡ 1 (mod m) if a and m are coprime
        if pow(a, result, num) == 1:
            print(f"With a = {a}, {a}^{result} ≡ 1 (mod {num}), confirming {a} and {num} are coprime")
        else:
            print(f"With a = {a}, {a}^{result} ≢ 1 (mod {num}), something went wrong")

if __name__ == "__main__":
    main()

