def are_anagrams(str1, str2):
    # Convert both strings to lowercase to make the check case-insensitive
    str1 = str1.lower()
    str2 = str2.lower()
    # Compare the sorted characters of both strings
    return sorted(str1) == sorted(str2)

# Example usage
print(are_anagrams("listen", "silent"))  # Output: True
print(are_anagrams("hello", "world"))    # Output: False
