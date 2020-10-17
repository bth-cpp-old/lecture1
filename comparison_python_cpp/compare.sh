#!/bin/bash

# Compile cpp program
clang++ -std=c++11 sort_cpp.cpp -o sort_cpp.a
clang++ -std=c++11 -o3 sort_cpp.cpp -o sort_cpp_opt.a

# Generate random list
python3 gen_list_file.py list.txt $1

# Sort with cpp
printf "\nSorting $1 elements with C++:"
time ./sort_cpp.a list.txt cpp_sorted_list.txt

# Sort with cpp
printf "\nSorting $1 elements with C++ (optimized):"
time ./sort_cpp_opt.a list.txt cpp_sorted_list_opt.txt

# Sort with python
printf "\nSorting $1 elements with Python:"
time python3 sort_python.py list.txt python_sorted_list.txt

# Cleanup
rm cpp_sorted_list.txt
rm cpp_sorted_list_opt.txt
rm python_sorted_list.txt
rm list.txt
rm sort_cpp.a
rm sort_cpp_opt.a
