/*Generate random numbers between 0-33, ten thousand times, then print how many duplicates of each number
you have generated -- print in ascending order.*/
#include<iostream>
#include<array>
#include<algorithm>
#include <chrono>

void GenerateAndStore(std::array<std::pair<int,int>,34> &a){
  //create indexing
@@ -23,8 +24,14 @@ bool CustomCompare(const std::pair<int,int> &p1, const std::pair<int,int> &p2){
  return p1.second < p2.second;
}
int main(){
  auto start = std::chrono::steady_clock::now();

  std::array<std::pair<int,int>,34> numbers;
  GenerateAndStore(numbers);
  std::sort(numbers.begin(),numbers.end(),CustomCompare);
  PrintArray(numbers);

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

}