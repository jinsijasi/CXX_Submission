/*We want to generate 1024 random integers, then given a new random number; find two integers which are the
closest to the given number (smaller, and bigger) with less than twelve lookups.*/

#include<iostream>
#include<array>
#include<algorithm>
#include<chrono>

void FillArray(std::array<int,1024> &a){
  for(int i=0;i<1024;i++){
@@ -73,16 +74,19 @@ void PrintResult(std::pair<int,int> p, int r){
  std::cout << "The random number was: "              << r << std::endl;
}
int main(){
  auto start = std::chrono::steady_clock::now();

  std::array<int,1024> random_numbers;
  FillArray(random_numbers);
  std::sort(random_numbers.begin(),random_numbers.end());
  PrintArray(random_numbers);
  //PrintArray(random_numbers);
  int r = rand();

  //int r = 2113903881;
  //int r = INT32_MAX-2;

  std::pair<int,int> result = FindClosest(random_numbers,r);
  std::cout << "------------------------------" << std::endl;
  PrintResult(result,r);


  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
} 