// Programmer: Max Goshay
// Programmer's ID: 252053
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.TestDriver.h"
#include <iostream>

int main (){
  
        cout << endl << "||||||Testing Stack with double||||||" << endl;
	Stack <double> a(100);
	assert(100 == a.capacity());
	cout << "Pass!!" << endl;
	cout << "\nTesting ::capacity\n";
	cout << "EXPECTED: 100\n";
	cout << "ACTUAL: " << a.capacity() << endl;
	assert(100 == a.capacity());
	cout << "Pass!!" << endl;

	// set capacity test
	cout << "\nTesting capacity growth\n";
	Stack <double> f(1);
	cout << "Expected: 1 \nActual: " << f.capacity() << endl;
	assert(f.capacity() == 1);
	cout<<"pushing 2 values grows cap by 2x\n"; 
	f.push(12);
	f.push(2);
	cout << "Expected: 2 \nActual: " << f.capacity() << endl;
        assert(f.capacity() == 2);
	cout << "Pass!!" << endl;

	// Object assignment
	cout << "\nTesting object assignment\n";
	a.push(5.5);
	Stack <double> e(1);
	for (int i = 0; i < 10; i++){
	  a.push(5+i);
	}
	e = a;
	assert(a.size()==e.size());
	assert(a.capacity() == e.capacity());
	for (int i = 0; i < 5; i++){
		assert(a.peek() == e.peek());
	  a.pop();
	  e.pop();
	}
	cout << "Pass!!" << endl;
	
	// testing size
	cout << "\nTesting size()\n";
	cout << "a.size() = " << a.size() << endl;
	a.pop();
	cout << "After pop() Expected: 5 \nActual: " << a.size() << endl;
	assert(a.size() == 5);
		a.push(1);
	cout << "After push() Expected: 6 \nActual: " << a.size() << endl;
	assert(a.size() == 6);
	
	// testing pop
	cout << "\nTesting pop()\n";
	cout << "push 2, then 1\n";
	a.push(2);
	a.push(1);
	cout << "a.peek() = " << a.peek() << endl;
	a.pop();
	cout << "After pop() Expected: 2 \nActual: " << a.peek() << endl;
	assert(a.peek() == 2);
	cout << "Pass\n" ;
	
	// testing push
	cout << "\nTesting push()\n";
	cout << "push 2\n";
	a.push(2);
	cout << "After push() Expected: 2 \nActual: " << a.peek() << endl;
	assert(a.peek() == 2);
	cout << "Pass\n" ;
	
	// testing peek
	cout << "\nTesting peek()\n";
	cout << "push 2\n";
	a.push(2);
	cout << "After push() Expected: 2 \nActual: " << a.peek() << endl;
	assert(a.peek() == 2);
	cout << "Pass\n" ;

	// testing clear
	cout << "\nTesting clear()\n";
	a.clear();
	cout << "After clear() size Expected: 0 \nActual: " << a.size() << endl;
	assert(a.size() == 0);
	cout << "Pass\n" ;

        // testing empty
	cout << "\nTesting empty()\n";
	a.clear();
	cout << "Expected: 1 \nActual: " << a.empty() << endl;
 	assert(a.empty() == 1);
 	a.push(23);
 	assert(a.empty() == 0);
	cout << "Pass\n" ;

  return 0;
}
