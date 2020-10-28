/*Write a program which takes a positive number from user, 
and then fill in a 3-dimensional array of size [8,9,11]
with random positive numbers smaller than the one user has 
provided – pretty print the array.*/

#include <iostream>
#include <random>

const unsigned int index_i = 8, index_j = 9 , index_k = 11;

void print2darray(unsigned int x[][index_k], unsigned int m)
{
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < index_k; j++)
        {
            std::cout<< '\t' << x[i][j];
        }
        std::cout << std::endl;
    }
}


int main() 
{
    unsigned int input;
    std::cout<<"Enter positive integer between 1 and 100" <<std::endl;
    std::cin>> input;

    unsigned int arr_3d[8][9][11];

    //Define array with random integers
    for(int i = 0; i < index_i; i++)
    {
        for(int j = 0; j < index_j; j++)
        {
            for(int k =0; k < index_k; k++)
            {
            arr_3d[i][j][k] = rand() % input;
            }

        }
    }

    //pretty print array
    for(int i = 0; i < index_i; i++)
    {
        std::cout << '[' << std:: endl;
        print2darray(arr_3d[i], index_j);
        if(i < index_i-1)
        {
            std::cout<< ",";
        }
        std::cout << std::endl;
    }
}
   