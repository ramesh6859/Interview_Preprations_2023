# Create a Python function that mimics the behaviour of the range() function but works with floating-point numbers?

def float_range(start, stop, step):
    while start < stop:
        yield round(start, 10)  # rounding to avoid floating-point precision errors
        start += step

for num in float_range(0.5, 5.5, 0.5):
    print(num)