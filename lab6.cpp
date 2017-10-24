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
	bool empty();
  int size() const { return siz; }
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

//is empty?
template <typename V>
bool Stack<V>::empty(){
 if (siz == 0) return true;
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

void operatorParser(Stack<double> &kobe, Stack<char> &kober){
  while (kober.size() > 0){
        int value1 = kobe.peek();
        kobe.pop();
        int value2 = kobe.peek();
        kobe.pop();
    switch(kober.peek()) {
      case '+' : 
        cout << value1+value2 << "\t= " << value1 << "\t+" << value2 << "\n";
        break;
      case '/' : cout << value2/value1 << "\t= " << value2 << "\t/" << value1 << "\n";
        break;
      case '-' : 
        cout << value2-value1 << "\t= " << value2 << "\t-" << value1 << "\n";
        break;
      case '*' :
        cout << value2*value1 << "\t= " << value2 << "\t*" << value1 << "\n";
        break;
    }
        kober.pop();
  }
};

int main (){
  Stack<double> kobe;
  Stack<char> kober;
  
  cout << "Input values for calculations\n";
  for (int i = 1; i < 7; i++ ) {
    if (i % 3 == 0){
      char operation;  
      cin >> operation;
      kober.push(operation);
      continue;
    }
    double integer;
    cin >> integer;
    kobe.push(integer);
  }
  operatorParser(kobe, kober);
  
  return 0;
}
