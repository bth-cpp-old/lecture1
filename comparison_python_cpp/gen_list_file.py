import sys
from random import randint

file_name = sys.argv[1]
list_length = int(sys.argv[2])

file = open(file_name, "w")

file.write(str(list_length))
for i in range(list_length):
    file.write(f"\n{randint(0, 1000)}")
file.close()
