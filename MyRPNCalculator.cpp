// Programmer: Max Goshay
// Programmer's ID: 252053
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

bool opCheck(string val){
      if( val == "+")return true;
      if( val == "/")return true;
      if (val == "-")return true;
      if (val == "*")return true;
      return false;
}

bool quitCheck(string val){
      if( val == "q"|| val == "Q")return true;
      return false;
}

void calc(string val,double topValue, double secondValue,Stack<double> &calcStack){
      if( val == "+"){calcStack.push(topValue+secondValue);}
      else if( val == "/"){calcStack.push(secondValue/topValue);}
      else if (val == "-"){calcStack.push(secondValue-topValue);}
      else if (val == "*"){calcStack.push(topValue*secondValue);}
}

void stackOutput(Stack<double> &calcStackCopy){
  cout << "\n--Stack--\n"; 
  for (int i = calcStackCopy.size(); i > 0; i--){
  cout << calcStackCopy.peek() << " ";
  calcStackCopy.pop();}
  cout << endl << endl;
}

int main (){
  Stack<double> calcStack;
  Stack<double> calcStackCopy;
      
  cout << "Input values for calculations\n";
  for (int i = 1; i < 2;) {
    string value;
    cin >> value;
    if (quitCheck(value))break;
    if (opCheck(value)){
      if (calcStack.size() == 0)continue;
      double topValue = calcStack.peek();
      calcStack.pop();
      double secondValue= calcStack.peek();
      calcStack.pop();
      calc(value,topValue,secondValue,calcStack);
      cout << calcStack.peek() << endl;
    }
    else calcStack.push(atof(value.c_str()));
    calcStackCopy = calcStack;
    stackOutput(calcStackCopy);
  }
  return 0;
}
