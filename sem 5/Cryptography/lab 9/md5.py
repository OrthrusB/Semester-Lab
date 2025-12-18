import hashlib

def generate_md5_hash(input_string):
    """
    Generate MD5 hash value from input string.
    
    Args:
        input_string (str): The input string to hash
        
    Returns:
        str: Hexadecimal representation of the MD5 hash
    """
    # Create an MD5 hash object
    md5_hash = hashlib.md5()
    
    # Convert the input string to bytes and update the hash object
    md5_hash.update(input_string.encode('utf-8'))
    
    # Return the hexadecimal representation of the hash
    return md5_hash.hexdigest()

def generate_md5_hash_file(file_path):
    """
    Generate MD5 hash value from a file's contents.
    
    Args:
        file_path (str): Path to the file
        
    Returns:
        str: Hexadecimal representation of the MD5 hash
    """
    # Create an MD5 hash object
    md5_hash = hashlib.md5()
    
    try:
        # Open file in binary mode
        with open(file_path, 'rb') as file:
            # Read the file in chunks to handle large files efficiently
            chunk_size = 8192
            while chunk := file.read(chunk_size):
                md5_hash.update(chunk)
        return md5_hash.hexdigest()
    except FileNotFoundError:
        return "Error: File not found"
    except Exception as e:
        return f"Error: {str(e)}"

def main():
    # Test with string input
    test_strings = [
        "Hello, World!",
        "Python Programming",
        "MD5 Hash Example"
    ]
    
    print("MD5 Hash Values for Strings:")
    print("-" * 40)
    for test_string in test_strings:
        hash_value = generate_md5_hash(test_string)
        print(f"Input: {test_string}")
        print(f"MD5 Hash: {hash_value}")
        print("-" * 40)
    
    # Example with file (uncomment and modify path to test)
    # file_path = "example.txt"
    # file_hash = generate_md5_hash_file(file_path)
    # print(f"File: {file_path}")
    # print(f"MD5 Hash: {file_hash}")

if __name__ == "__main__":
    main()