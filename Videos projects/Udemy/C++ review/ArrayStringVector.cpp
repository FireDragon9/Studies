#include <iostream> 
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
  
  //vector is similar to std::string, but can store data of any single type 

  //the type of the data is a aprameter of the class 
  vector<int> vec{4, 3, 2, 1}; //vec is a vector of int 

 vec.push_back(6); 

  return 0;
}
