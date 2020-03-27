#include <bits/stdc++.h>
using std::cout;
using std::string;

static size_t total_all;
static size_t total_fre;
void* operator new(size_t size)
{

	cout << "Allocation: " << size << " bytes.\n";
	total_all += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	total_fre += size;
	cout << "Deallocate: " << size << " bytes.\n";
	free(memory);
}

struct Foo
{
    int data;
};

int main()
{
    Foo *foo = new Foo;
    delete foo;

    cout << "Total Allocation: " << total_all << " - Total Deallocation: " << total_fre << "\n";
    return 0;
}