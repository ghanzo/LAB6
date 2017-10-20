
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
class DynamicArray
{
	int cap;
	V dummy;
	V* values;
public:
	DynamicArray(int = 2); // default constructor
	DynamicArray(const DynamicArray<V>&); // copy c
	~DynamicArray() { delete[] values; } //destructor
	DynamicArray<V>& operator=(const DynamicArray<V>&);
	int capacity() const { return cap; }
	void capacity(int); // setter cap
	V operator [] (int) const; //getter
	V& operator [] (int); //setter
};
//constructor
template <typename V>
DynamicArray<V>::DynamicArray(int cap)
{
	this->cap = cap;
	values = new V[cap];
	for (int i = 0; i < cap; i++) {
		values[i] = V();
	}
}
//copy constructor
template <typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V> & original) {
	cap = original.cap;
	values = new V[cap][1];
	dummy = V();
	for (int i = 0; i < cap; i++)
		values[i] = original.values[i];
	dummy = original.dummy;
}
//operator =
template <typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>&
	original) {
	if (this != &original)
	{
		delete[] values;
		cap = original.cap;
		values = new V[cap];
		for (int i = 0; i < cap; i++)
			values[i] = original.values[i];
		dummy = original.dummy;
	}
	return *this;
}
//set capacity
template <typename V>
void DynamicArray<V>::capacity(int cap) {
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
//getter []
template <typename V>
V DynamicArray<V>::operator[ ](int index) const
{
	if (index < 0) return dummy;
	if (index >= cap) return dummy;
	return values[index];
}
//setter []
template <typename V>
V& DynamicArray<V>::operator[ ](int index)
{
	if (index < 0) return dummy;
	if (index >= cap) capacity(index * 2);
	return values[index];
}

//|||||||||||||||||||||||||||||||||||||||||||||||||

//|||||||||||||||||||||||||||||||||||||||||||||||||

//|||||||||||||||||||||||||||||||||||||||||||||||||

template <typename V>
class Stack {
  private:
  int cap;
  int size;
	V dummy;
	V* values;
  void capacity(int);
  
  public:
  Stack(); // may have a defaulted parameter
  Stack(const Stack<V>&); // copy constructor
  ~Stack(){ delete[] values; }
  Stack<V>& operator=(const Stack<V>&);
  void push(const V&);
  V& peek(){ return values[size-1];}
  void pop(){ if (!empty())size--;}
  int size() const { return size; }
  bool empty() const {if (size == 0) return true;}
  void clear(){size = 0;}
};

template <typename V>
void Stack<V>::push(const V& val){
  if (cap == size)
  capacity(size+1);
  if (cap > size)
  values[size] = val;
  size++;
}

//constructor
template <typename V>
Stack<V>::Stack(int cap)
{
	this->cap = cap;
	size = 0;
	values = new V[cap];
	for (int i = 0; i < cap; i++) {
		values[i] = V();
	}
}

//copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V> & original) {
  this.size = original.size;
	cap = original.cap;
	values = new V[cap][1];
	dummy = V();
	for (int i = 0; i < cap; i++)
		values[i] = original.values[i];
	dummy = original.dummy;
}

//set capacity
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

//operator =
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>&
	original) {
	if (this != &original)
	{
		delete[] values;
		this.size = original.size;
		cap = original.cap;
		values = new V[cap];
		for (int i = 0; i < cap; i++)
			values[i] = original.values[i];
		dummy = original.dummy;
	}
	return *this;
}

int main()
{
  Stack <int> test1(10);

  
  
	return 0;
}
