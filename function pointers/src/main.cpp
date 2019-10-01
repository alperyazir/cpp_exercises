#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test_for_function_pointer(int value)
{
    cout << "Hello " << value << endl;
}

bool match(const std::string str)
{
    return str.size() == 3;
}

int count_string(vector<std::string> vec, bool (*tempFnc)(string))
{
    int count = 0;
    for (auto &i : vec)
        if (tempFnc(i))
            count++;
    return count;
}

int main()
{
    test_for_function_pointer(66);
    // Definition of a function pointer
    void (*pfunc)(int) = test_for_function_pointer;
    pfunc(67);

    vector<string> vec{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    // using function pointer in STL algorithm
    cout << count_if(vec.begin(), vec.end(), match) << "\n";
    // using function pointer in custom definition
    cout << count_string(vec, match) << "\n";
}