/* Basics of Smart pointers*/

#include <iostream>

using namespace std;
template<class T>
struct Auto_ptr 
{
    T* m_data;
    Auto_ptr(T* data=nullptr) : m_data(data){}
    ~Auto_ptr() {delete m_data;}

    T& operator*() const {return *m_data;}
    T* operator->() const {return m_data;}
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
    Auto_ptr<Resource> res(new Resource());
    return 0;
}