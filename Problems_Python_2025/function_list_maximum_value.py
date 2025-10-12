def find_max(lst):
    max_value = lst[0]
    for num in lst:
        if num > max_value:
            max_value = num
    return max_value

numbers = [3, 9, 7, 15, 6, 5]
print(find_max(numbers))  # Output: 15