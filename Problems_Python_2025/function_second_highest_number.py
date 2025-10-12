# write a Python program to find the second-highest number in a list?

def second_highest(numbers):
    first, second = float('-inf'), float('-inf')
    for num in numbers:
        if num > first:
            second = first
            first = num
        elif first > num > second:
            second = num
    return second

numbers = [12, 35, 1, 10, 34, 1]
print(second_highest(numbers))  # Output: 34
