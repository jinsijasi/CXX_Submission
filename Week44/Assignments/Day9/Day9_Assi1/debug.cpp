/*In the course demo repository, there is a file under Day9/Assignment folder called 1.cpp – fix its issues.*/
#include <iostream>

const size_t SIZE = 10;

int function() {
    return std::rand();
}
int *fillArray() {
    //int a[SIZE];
    int *a = new int[SIZE];
    size_t i = SIZE;// YOU ARE NOT SUPPOSE TO CHANGE THIS    
    //for (; i >-1; --i) {
    for(; i > 0; --i)
    {
       // a[i] = function();  
       a[i-1]   = function();   
    }
    return a;    
}
//void printArray(int a[SIZE]) {  
void printArray(int *a)  
{    
    for (size_t i = 0; i < SIZE; i++) {
        //std::cout << *a+i << std::endl;
        std::cout << *(a+i) << std::endl;
    }   
    delete [] a; 
}
void printBool (bool _b) {
   // if (_b = true) {
    if (_b == true) {
        std::cout << "VALUE is TRUE" << std::endl;        
    //} else if (_b = false)    {
     } else if (_b == false)    {
        std::cout << "VALUE is FALSE" << std::endl;        
    }    
}
// YOU ARE NOT ALLOWED TO CHANGE THE RETURN TYPE
//void resizeForMe(char *a, size_t _newSize) {
void resizeForMe(char *&a, size_t _newSize) {
    //delete a;
    delete[] a;
    a = new char[_newSize];
}


int main() {
    printArray(fillArray());
    printBool(false);
    char *a = new char[SIZE];        
    for (size_t i = 0; i<SIZE; i++) i%2 ? a[i] = 'A' : a[i] = 'D';
    a[SIZE-1] = 0x00;
    std::cout << "Size is: " << a << std::endl;
    resizeForMe(a,100);
    for (size_t i = 0; i<1000; i++) i%2 ? a[i] = 'B' : a[i] = 'C';
    a[100-1] = 0x00;
    std::cout << "Size is: " << a << std::endl;
    delete [] a;
    return 0;
}