# Implementation for the palindrome check:
def is_palindrome(s):
    # Remove spaces and convert to lowercase
    cleaned_s = ''.join(s.split()).lower()
    return cleaned_s == cleaned_s[::-1]
    

# Example usage
print(is_palindrome("A man a plan a canal Panama"))  # Output: True
print(is_palindrome("Hello"))  # Output: False