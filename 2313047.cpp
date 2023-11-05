#include  <iostream>
#include  <vector>

using namespace std;

// a function to store a value in a memory


void storeMemory(vector<float>& memory, float value) {

  
  if (memory.size() < 5) { // Check if memory is full
   
   
   
    memory.push_back (value); // add value to memory
    
  
    cout << "Value stored in memory.\n";
 
 }
 
 
  else {
   
   
    cout << "Memory is full.\n";
 
 
  }


}

// a function to view the memory

void viewMemory(vector <float> & memory) {
  
  
  cout << "Memory: ";
  
 
 
  for (float x : memory) {    // Loop through memory vactor
    cout << x << " ";         // Print each value
 
 
  }
 
 
  cout << "\n";

}

// a function to reset the memory


void resetMemory(vector<float>& memory) {
  
  
  memory.clear();   // Clear the memary 
 
  cout << "Memory reset.\n";
}



// a function to perform arithmetic operatios

float calculate(float num0, float num1, char op) {
  
 
  switch (op) {     // Check the operator
   



             // operators
   
    case '+': return num0 + num1;   // Addition
    case '-': return num0 - num1;   // Subtraction
    case '*': return num0 * num1;   // Multiplcation
    case '/': return num0 / num1;   // Division


    default: return 0;              // Invalid operator
 
  }



}


int main() {
  
 
  vector<float> memory;      // a vector to store up to 5 values in memory
  float num0, num1, result;  // Variables to store operands and result
  char op, choice;           // Variables to store   operator and user choice
  bool flag = true;          // A flag to control the loop

  
  
  
  while (flag) {    // Loop until user exts
   
    cout << "Enter an operator (+, -, *, /) or a command (view memory, reset memory, off): ";
    
    cin >> op;     // Read the operator or commad

    
    
    
    if (op == '+' || op == '-' || op == '*' || op == '/') {   // If operator is valid
      
      cout << "Enter two numbers: ";
      
      cin >> num0 >> num1;    // read the  numbers

      
   
      result = calculate (num0, num1, op) ; // Calculte the result

      cout << "The result is: " <<  result << "\n" ;  // Print the result

      cout << "Do you want to store the result in memory? (y/n): ";
           cin >> choice;  // read the user choice




                            // store memory

      
      if (choice == 'y' || choice == 'Y') {  // If user wants  to store the result 
              
              storeMemory(memory, result);  // Store the result in memory
      }
    
                             
                             // value in  memory
   
    } 
    else if (op == 'm') {    // If user wants to store a value in memory
      cout << "Enter a number: ";
      cin >> num0;       // Read the number

      storeMemory(memory, num0);   // Store the number in memory
   
   
                     
                      // view memory

    }
    else if (op == 'v') {    // If user wants to view the memory
      viewMemory(memory);    // View the memory
   
   
                    
                     //   reset memory

    }
    else if (op == 'r') {   // If user wants to reset the memory
      resetMemory(memory);  // reset the  memory
   
   
   
                      //  exit the cal
   
    }
    else if (op == 'o') {   // If user wants to  exit
      cout << "Calculator is off.\n"; // Print a  message
      flag = false;         // Set flag to false to end  loop
   
   
  
                        // invalid operator
  
    }
    else {     // If operator or  command  is invalid
      cout << "Error! Invalid input.\n";    // Print  an error m essage
   
   
    }
  }

  
  
  return 0;

}
