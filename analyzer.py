"""Binary Search and Linear Search Analyzer by Grant Gravlee and William Pearce"""

import time
from stringdata import get_data


def main():
    data = get_data()
    search_and_time('not_here', data)
    search_and_time('mzzzz', data)
    search_and_time('aaaaa', data)


# searches through every element in given data for target
def linear_search(container, element):
    for i in range(len(container)):
        if container[i] == element:
            return i
    return -1


# 'divide and conquer' cuts sorted list into sections repeatedly, much faster than linear seach on sorted data
def binary_search(container, element):
    min_index = 0
    max_index = len(container) - 1
    while max_index >= min_index:
        mid_index = min_index + (max_index - min_index) // 2
        if element == container[mid_index]:
            return mid_index
        elif element < container[mid_index]:
            max_index = mid_index - 1
        elif element > container[mid_index]:
            min_index = mid_index + 1
    return -1


# uses time module to record time that a function takes to run, also returns the result of the function
def time_algo(func, *args):
    start_time = time.time()
    index = func(*args)
    end_time = time.time()
    return tuple([index, end_time - start_time])

# formats the result of the time_algo function


def search_and_time(target, data):
    print(f'Searching for: "{target}"')
    print('Linear search:')
    result = time_algo(linear_search, data, target)
    print('\tTarget index:', result[0])
    print('\tTime:', result[1])
    print('Binary search:')
    result = time_algo(binary_search, data, target)
    print('\tTarget index:', result[0])
    print('\tTime:', result[1])
    print()


if __name__ == '__main__':
    main()
