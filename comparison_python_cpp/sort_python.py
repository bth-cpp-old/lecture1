import sys
from random import randint

def extract_list(file_name):
    
    file = open(file_name, "r")

    # First line is length of list
    list_length = int(file.readline())

    # Read each line and append its content
    # to the list.
    lst = []
    for _ in range(list_length):
        lst.append(int(file.readline()))

    file.close()
    return lst

def bubble_sort(lst : list):
    length = len(lst)

    # Iterate the list backwards.
    # Skip last element to avoid out of range, 
    # as inner loop "touches" two elements at a time.
    for i in range(length-1, 0, -1):

        # Iterate from start to i
        for j in range(0, i):

            # If current element is larger than
            # the next element, swap them.
            if lst[j] > lst[j+1]:
                lst[j+1] += lst[j]
                lst[j] = lst[j+1] - lst[j]
                lst[j+1] = lst[j+1] - lst[j]

def store_list(file_name : str, lst : list):
    file = open(file_name, "w")
    length = len(lst)

    # First line is length of list
    file.write(str(length))

    # Write the rest of the list,
    # one element per row
    for nr in lst:
        file.write(f"\n{nr}")
    file.close()

def main():

    file_name = sys.argv[1]

    lst = extract_list(file_name)
    bubble_sort(lst)

    file_name = sys.argv[2]
    store_list(file_name, lst)


if __name__ == "__main__":
    main()