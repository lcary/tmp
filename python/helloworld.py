message = "Fibonacci Series"
print("=" * len(message))
print(message)
print("=" * len(message) + "\n")

def fib(n):
    print("n={}".format(n))
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else:
        value = fib(n - 1) + fib(n - 2)
        return value


# n = raw_input('Please input the maximum number of values to print: ')
# int_series = map(fib, range(int(n)))
# str_series = map(str, int_series)

# print("Here are the Fibonacci numbers from 1 to {}".format(n))
# print(" ".join(str_series))

print("Value:%s" % fib(10))
