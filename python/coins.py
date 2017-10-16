from collections import Counter
"""
I would recommend that you check out the `Counter()` class in the `collections` library of Python's stdlib:

https://docs.python.org/2/library/collections.html#collections.Counter

### Using Counters To Keep Tally

Think of the Counter object as an overpowered dictionary, designed for keeping tally. It seems nice for the use case of keeping tally of different coins types in a data store:

    coin_store = Counter({'nickles': 25, 'dimes': 25, 'quarters': 25, 'ones': 0, 'fives': 0})
    print(coin_store)  # Counter({'nickles': 25, 'dimes': 25, 'quarters': 25, 'ones': 0, 'fives': 0})
    coin_store['nickles'] += 1
    print(coin_store)  # Counter({'nickles': 26, 'dimes': 25, 'quarters': 25, 'ones': 0, 'fives': 0})

### Merging Counters

For the question of finding "a way to manipulate one dictionary based on the input of a second dictionary" we can create a dictionary that contains all keys and values from one data store updated with the keys and values from another:

    def update_store(coin_store1, coin_store2):
        """Updates the contents of a coin store with values from another store."""
        for coin_type, coin_num in coin_store2.items():
            coin_store1[coin_type] += coin_num
        return coin_store1

    coin_store = Counter({'nickles': 6, 'dimes': 5, 'quarters': 10})
    update_store(coin_store, Counter({'quarters': 5, 'ones': 3, 'fives': 10}))
    print(coin_store)  # Counter({'quarters': 15, 'fives': 10, 'nickles': 6, 'dimes': 5, 'ones': 3})

Note: whatever update function you use requires error handling for invalid coin types and values.

### Dictionaries in Python

It's probably worth spending some time to understand the different operations supported by dictionaries, perhaps starting with `.get()`, and moving on to `.update()` and `.copy()`, etc. See them all here:

https://docs.python.org/2/library/stdtypes.html#mapping-types-dict

This should answer your question, and will hopefully get you interested in exploring the other types of collections offered in Python's stdlib as well. Best of luck!
"""

coin_store = Counter({'nickles': 25, 'dimes': 25, 'quarters': 25, 'ones': 0, 'fives': 0})
print(coin_store)  # Counter({'nickles': 25, 'dimes': 25, 'quarters': 25, 'ones': 0, 'fives': 0})
coin_store['nickles'] += 1
print(coin_store)  # Counter({'nickles': 26, 'dimes': 25, 'quarters': 25, 'ones': 0, 'fives': 0})

def update_store(coin_store1, coin_store2):
    """Updates the contents of a coin store with values from another store."""
    for coin_type, coin_num in coin_store2.items():
        coin_store1[coin_type] += coin_num
    return coin_store1

coin_store = Counter({'nickles': 6, 'dimes': 5, 'quarters': 10})
update_store(coin_store, Counter({'quarters': 5, 'ones': 3, 'fives': 10}))
print(coin_store)  # Counter({'quarters': 15, 'fives': 10, 'nickles': 6, 'dimes': 5, 'ones': 3})
