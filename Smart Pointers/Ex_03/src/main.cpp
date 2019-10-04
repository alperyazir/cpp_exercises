/*
 // R-value references and L-value references
 // B, E, G wont compile
*/ 
#include<iostream>
using namespace std;
int main()
{
	int x;
 
	// l-value references
	int &ref1 = x; // A
	int &ref2 = 5; // B
 
	const int &ref3 = x; // C
	const int &ref4 = 5; // D
 
	// r-value references
	int &&ref5 = x; // E
	int &&ref6 = 5; // F
 
	const int &&ref7 = x; // G
	const int &&ref8 = 5; // H
	
	return 0;
}