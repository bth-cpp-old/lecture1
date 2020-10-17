#include <iostream>
#include <fstream>
#include <string>

void extract_list(const std::string& file_name, int** list, int& length)
{
    std::string line;
    std::ifstream file(file_name.c_str());

    // First line is length of list
    getline(file, line);
    length = std::stoi(line);

    // Allocate memory to fit the list
    (*list) = new int[length]; 

    // Read each line and append its content
    // to the list.
    for (int i = 0; i < length; ++i)
    {
        getline(file, line);
        (*list)[i] = std::stoi(line);
    }
    file.close();
}

void bubble_sort(int* list, const int& length)
{
    // Iterate the list backwards.
    // Skip last element to avoid out of range, 
    // as inner loop "touches" two elements at a time.
    for (int i = length - 1; i > 0; --i)
    {
        // Iterate from start to i
        for (int j = 0; j < i; ++j)
        {
            // If current element is larger than
            // the next element, swap them.
            if (list[j] > list[j+1])
            {
                list[j+1] += list[j];
                list[j] = list[j+1] - list[j];
                list[j+1] = list[j+1] - list[j];
            }
        }
    }
}

void store_list(const std::string& file_name, const int* list, const int& length)
{
    // Open a file to write the list to
    std::ofstream file(file_name);

    // First line is length of list
    file << length;

    // Write the rest of the list,
    // one element per row
    for (int i = 0; i < length; ++i)
    {
        file << "\n" << list[i];
    }
    file.close();
}

int main(int argc, char *argv[])
{
    int* list;
    int length;
    std::string file_name(argv[1]);
    
    extract_list(file_name, &list, length); // Allocates memory
    bubble_sort(list, length);

    file_name = argv[2];
    store_list(file_name, list, length);

    // Deallocate memory
    delete[] list;

    return 0;
}