
/*• Write a function template which receives two of any shapes from yesterday’s assignment, compares them, and
prints out the result.*/
#include "shape.h"
#include "assignment1.h"

int main(){
  int size = 6;
  Shape * shapes[size]{
    new Triangle(5,23),
    new Rectangle(2,4),
    new Rectangle(2,4),
    new Circle(5),
    new Circle(10),
    new Square(10)
  };

  for (size_t i = 0; i < size; i++) 
    for (size_t j = i + 1; j < size; j++) {
    CompareShapes<Shape>(*shapes[i],*shapes[j]);
  }    

  for(size_t i=0;i<size;i++)
    delete shapes[i];
return 0;
} 