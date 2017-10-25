// Programmer: Max Goshay
// Programmer's ID: 252053
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack.TestDriver.h"

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
