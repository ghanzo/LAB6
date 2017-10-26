// Programmer: Max Goshay
// Programmer's ID: 252053
#define _CRT_SECURE_NO_WARNINGS
#ifndef stackTester
#define stackTester
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
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
	bool empty(){if (siz == 0) return true;else return false;}
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
#endif