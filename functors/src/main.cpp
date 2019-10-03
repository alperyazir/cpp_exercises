/* Functors are objects that acting like functions with using operator()*/ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct MyIncrementFunctor
{
    int num;
    MyIncrementFunctor(int num) : num(num) {}
    int operator()(int inc_val) { return inc_val + num; }
};

int increment(int i)
{
    return ++i;
}
int main()
{
    vector<int> vec{1, 2, 3, 4};

    // Using with a function object
    // What if we wanto increment with different value?
    // Write another function? no Just use Functors :)
    transform(begin(vec), end(vec), ostream_iterator<int>(cout, " "), increment);

    cout << endl;
    //using Functors
    int inc_val = 5;
    transform(begin(vec), end(vec), ostream_iterator<int>(cout," "), MyIncrementFunctor(inc_val));

    return 0;
}