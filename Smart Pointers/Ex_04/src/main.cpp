#include <iostream>

using namespace std;

template <typename T>
struct AutoPtr
{
    T *m_data;
    AutoPtr(T *data = nullptr) : m_data(data) {}
    ~AutoPtr() { delete m_data; }

    // Copy constructor
    // Do deep copy of a.m_ptr to m_ptr
    AutoPtr(const AutoPtr &ptr)
    {
        m_data = new T;
        this->m_data = ptr.m_data;
    }
    // Copy assignment
    // Do deep copy of a.m_ptr to m_ptr
    AutoPtr &operator=(const AutoPtr &ptr)
    {
        // Self Checking
        if (&ptr == this)
            return *this;

        delete m_data;
        m_data = new T;
        m_data->m_data = ptr.m_data;
        return *this;
    }

    AutoPtr( AutoPtr&& ptr)
    {
        m_data = ptr.m_data;
        ptr.m_data = nullptr;
    }

    AutoPtr &operator=( AutoPtr&& ptr)
    {
        // Self Checking
        if (this == &ptr)
            return *this;

        delete m_data;
        m_data = ptr.m_data;
        ptr.m_data = nullptr;
        return *this;
    }

    T& operator*() const { return *m_data};
    T* operator->() const { return m_data}
};

struct Resource
{
    Resource() { cout << "Constructing Resource" << endl; }
    ~Resource() { cout << "Destroying Resource" << endl; }
};

AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource);
    return res; // this return value will invoke the move constructor
}

int main()
{
    AutoPtr<Resource> mainres;
    mainres = generateResource(); // this assignment will invoke the move assignment

    return 0;
}