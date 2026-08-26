#include <iostream>
#include <vector>

// On passing std::vector:
// Rarely do we want to actually copy the entire vector, so we pass it's ref
// If we do not want to change the vector, we pass it as const
// We have to define the type of the vector or get a compile time error
// We can pass a generic type, or scope it down to a single type
template <typename T>
void print_vector_element(const std::vector<T>& vec)
{
    std::cout << vec[0] << '\n';
}

// std::vectors are move capable, this means that under certain
// conditions, instead of copying over their data to another vector,
// the latter just points to the data. Ownership 'moved' to the latter.
// the topic of move semantics is discussed here:
// https://www.learncpp.com/#Chapter22
// Not every class is move capable, but std::vector is.
std::vector<int> do_different_vector(const std::vector<int>& vec)
{
    // This is returned by value, but a deep copy doesn't happen between this
    // and the caller, rather ownership transfers to the caller.
    return(std::vector<int>{0, 5, vec[0]});
}

// Exercise:
// Write a program that:
// 1. Creates a vector<int>
// 2. Inserts 10 numbers
// 3. Prints them
// 4. Removes the last 3
// 5. Prints the result
// 6. Searches for a number
// 7. Inserts something at position 2
// 8. Deletes something at position 2
void exercise()
{
    std::vector<int> nums;
    nums.reserve(10);

    for (size_t i = 0; i < nums.capacity(); ++i)
    {
        nums.push_back((int)i + 1);
    }

    for (int num : nums)
    {
        std::cout << num << '\n';
    }

    nums.pop_back();
    nums.pop_back();
    nums.pop_back();

    for (int num : nums)
    {
        std::cout << num << '\n';
    }

    int target = 3;
    for (int num : nums)
    {
        if (num == target)
        {
            break;
        }
    }

    // positional insertion and deletion
    nums.insert(nums.begin() + 2, 44);
    nums.erase(nums.begin() + 2);
}

int main()
{
    // list constructor that allows us to construct container types
    // using an initializer list
    // More: https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
    std::vector<int> nums{ 2, 3, 4, 7 };

    // we can access elements using the subscript operator []
    std::cout << "Index 0: " << nums[0] << '\n';

    // Another constructor that can take the initial length of the vector
    std::vector<int> data(10);

    // size() returns the length of the array as a size_type, which is
    // just a typedef of size_t
    std::cout << "Length: " << nums.size() << '\n';

    // C++17 has std::size() which can be used, for containers, this just calls the
    // member size() function
    std::cout << "Length: " << std::size(nums) << '\n';

    // One issue with using the subscript operator [] for access is it does
    // not bounds checking, the at() member function provides this.
    // This just throws an exception if it's out of bounds.
    std::cout << "Index 3: " << nums.at(3) << '\n';

    // Since we can use the subscript operator [], we can traverse
    // a vector with a for loop.
    for (size_t i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << '\n';
    }

    // Example with range-based for loop
    for (int num : nums)
    {
        std::cout << num << '\n';
    }

    // We can use capacity() to know the vector's current capacity
    std::cout << "capacity: " << nums.capacity() << '\n';

    // We can use resize() to alter a vector's capacity and length
    nums.resize(10);

    // we can use reserve() to alet a vector's capacity only
    nums.reserve(100);

    // stack behavior with std::vector:
    // push_back() puts an element on top of the stack
    // emplace_back() uses perfect forwarding to add an element to the top of the stack
    // using some temporary object
    // pop_back() removes an element from the top of the tack
    // back() get the top element of the stack
    // front() get the bottom element of the stack
    // for more: https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/

    exercise();
    return(0);
}