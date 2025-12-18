import hashlib

# Function to compute SHA-256 hash
def compute_sha256(input_string):
    # Create a new sha256 hash object
    sha256_hash = hashlib.sha256()
    
    # Convert the input string to bytes and update the hash object
    sha256_hash.update(input_string.encode('utf-8'))
    
    # Get the hexadecimal representation of the hash
    hash_result = sha256_hash.hexdigest()
    
    return hash_result

# Example usage
input_text = "Hello, SHA-256!"
hash_value = compute_sha256(input_text)

# Print the results
print(f"Input: {input_text}")
print(f"SHA-256 Hash: {hash_value}")

# Demonstrate that same input always gives same output
input_text2 = "Hello, SHA-256!"
hash_value2 = compute_sha256(input_text2)
print(f"\nSame Input: {input_text2}")
print(f"SHA-256 Hash: {hash_value2}")

# Different input produces different hash
input_text3 = "Hello, SHA-256?"
hash_value3 = compute_sha256(input_text3)
print(f"\nDifferent Input: {input_text3}")
print(f"SHA-256 Hash: {hash_value3}")