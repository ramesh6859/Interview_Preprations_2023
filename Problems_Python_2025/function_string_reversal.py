# How would you reverse a string in Python without using built-in functions?
def reverse_string(s):
    reversed_str = ""
    for char in s:
        reversed_str = char + reversed_str
    return reversed_str

def reverse_string_second(s):
	return s[::-1]
    
print(reverse_string("hello"))
print(reverse_string_second("ramesh"))