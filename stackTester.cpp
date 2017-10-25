// Programmer: Max Goshay
// Programmer's ID: 252053
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

template <typename V>
class Stack
{
	int cap;
	int siz;
	V dummy;
	V* values;
	void capacity(int);
	
public:
	Stack(int = 2); // default constructor
	Stack(const Stack<V>&); // copy c
	~Stack() { delete[] values; } //destructor
	Stack<V>& operator=(const Stack<V>&);
	void push(const V&);
	void pop();
	V& peek(){ return values[siz-1];}
	bool empty(){if (siz == 0) return true;
	  else return false;
	}
  int size() const { return siz; }
  void clear(){ siz = 0; }
  int capacity() const { return cap; }
};

//push
template <typename V>
void Stack<V>::push(const V& val){
  if (cap == siz)
  capacity(siz*2);
  if (cap > siz)
  values[siz] = val;
  siz++;
}

//set cap private function
template <typename V>
void Stack<V>::capacity(int cap) {
	V* temp = new V[cap];
	int limit = min(cap, this->cap);
	for (int i = 0; i < limit; i++)
		temp[i] = values[i];
	for (int i = limit; i < cap; i++)
		temp[i] = V();
	delete[] values;
	values = temp;
	this->cap = cap;
}

//pop
template <typename V>
void Stack<V>::pop(){
 if (siz > 0)siz--;
}

//constructor
template <typename V>
Stack<V>::Stack(int cap)
{
	this->cap = cap;
	siz = 0;
	values = new V[cap];
	for (int i = 0; i < cap; i++) {
		values[i] = V();
	}
}
//copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V> & original) {
	cap = original.cap;
	size = original.size;
	values = new V[cap][1];
	dummy = V();
	for (int i = 0; i < cap; i++)
		values[i] = original.values[i];
	dummy = original.dummy;
}
//operator =
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>&
	original) {
	if (this != &original)
	{
		delete[] values;
		siz = original.siz;
		cap = original.cap;
		values = new V[cap];
		for (int i = 0; i < cap; i++)
			values[i] = original.values[i];
		dummy = original.dummy;
	}
	return *this;
}


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
