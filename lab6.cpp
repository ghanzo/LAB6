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

bool opCheck(string val){
      if( val == "+"){return true;}
      if( val == "/")return true;
      if (val == "-")return true;
      if (val == "*")return true;
      return false;
}

bool quitCheck(string val){
      if( val == "q"|| val == "Q")return true;
      return false;
}

void calc(string val,double val1, double val2,Stack<double> &kobe){
      if( val == "+"){kobe.push(val1+val2);}
      else if( val == "/"){kobe.push(val2/val1);}
      else if (val == "-"){kobe.push(val2-val1);}
      else if (val == "*"){kobe.push(val1*val2);}
}

void stackOutput(Stack<double> &kobeCopy){
  cout << "\n--Stack--\n"; 
  for (int i = kobeCopy.size(); i > 0; i--){
  cout << kobeCopy.peek() << " ";
  kobeCopy.pop();}
  cout << endl << endl;
}

int main (){
  Stack<double> kobe;
  Stack<double> kobeCopy;
  
  cout << "Input values for calculations\n";
  
  for (int i = 1; i < 2;) {
    string joo;
    cin >> joo;
    if (quitCheck(joo))break;
    if (opCheck(joo)){
      double val1 = kobe.peek();
      kobe.pop();
      double val2= kobe.peek();
      kobe.pop();
      calc(joo,val1,val2,kobe);
      cout << kobe.peek() << endl;
    }
    else kobe.push(atof(joo.c_str()));
    kobeCopy = kobe;
    stackOutput(kobeCopy);
  }
  return 0;
}
