/* Basics of Move Semantics with copy constructor and assignment(=) operator */
#include <iostream>

using namespace std;
template <class T>
struct Auto_ptr
{
    T *m_data;
    Auto_ptr(T *data = nullptr) : m_data(data) {}
    ~Auto_ptr() { delete m_data; }

    T &operator*() const { return *m_data; }
    T *operator->() const { return m_data; }
   
    // Copy constructor that implements move semantics
    Auto_ptr(Auto_ptr &ptr)
    {
        m_data = ptr.m_data; // transfer our dumb pointer from the source to our local object
        ptr.m_data = nullptr; // make sure the source no longer owns the pointer
    }

    // An assignment operator that implements move semantics
    Auto_ptr &operator=(Auto_ptr &ptr)
    {
        // Self Checking
        if (&ptr == this)
            return *this;

        this->m_data = nullptr; // make sure we deallocate any pointer the destination is already holding first
        m_data = ptr.m_data;  // then transfer our dumb pointer from the source to the local object
        ptr.m_data = nullptr; // make sure the source no longer owns the pointer
        return *this;
    }

    bool is_null() const { return m_data == nullptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    Auto_ptr<Resource> res1(new Resource);
    Auto_ptr<Resource> res2; // Start as nullptr

    std::cout << "res1 is " << (res1.is_null() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.is_null() ? "null\n" : "not null\n");

    res2 = res1; // res2 assumes ownership, res1 is set to null

    std::cout << "Ownership transferred\n";

    std::cout << "res1 is " << (res1.is_null() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.is_null() ? "null\n" : "not null\n");

    return 0;
}