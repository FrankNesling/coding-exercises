import random

def binary_search(theList, begin, end, element):
    mid = begin + int((end-begin)/2)

    if (end - begin < 1):
        if (element == theList[mid]):
            return mid
        return None
    elif (element < theList[mid]):
        return binary_search(theList, begin, mid, element)
    elif (element > theList[mid]):
        return binary_search(theList, mid + 1, end, element)
    elif (element == theList[mid]):
        if (theList[mid-1] == theList[mid]):    # for duplicates, m-1>0 is guaranteed by the first if check
            return binary_search(theList, begin, mid-1, element)
        return mid


# random input
list_length = random.randint(1, 100)
random_numbers = [random.randint(1, 100) for _ in range(list_length)]
random_numbers.sort()

random_element = random.randint(1, 100)

# informative display
print("A list of 1-100 elements (possible duplicates) between 1-100 is randomly generated. Then another number between 1-100 is randomly selected. It does not need to be in the list.")
print(list_length)
print(random_numbers)
print(random_element)
print("\n")


# calculation
idx = binary_search(random_numbers, 0, len(random_numbers)-1, random_element)

# ouput
if (idx == None):
    print("Element not in the list :(")
elif (random_numbers[idx] != random_element):
    print("Something went wrong...")
else:
    print(f'List[{idx+1}] = {random_element} = {random_numbers[idx]}')

print("Getting the first element of duplicates might, in worst case (all elements are the same), result in O(n) complexity. Without duplicates, or not necessarily the first of the dupliactes, it is O(log n).")