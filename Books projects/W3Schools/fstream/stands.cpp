#include <cstdio>
#include <iostream>
#include <fstream>

#include <map>

#include <sstream>

using namespace std;

bool check(ifstream& file, string value){

  string text;

  while(getline(file, text)){

    if(text.find(value) != string::npos){
      return true;
    }

  }

  return false;

}


int main (int argc, char *argv[]) {

  map<int, string>myStands;

  myStands[0] = "Star Platinum";
  myStands[1] = "Crazy Diamond";
  myStands[2] = "Golden Experience";
  myStands[3] = "Stone Free";
  myStands[4] = "Tusk";
  myStands[5] = "Soft&Wet";
  myStands[6] = "November Rain";

  ofstream file("Stands");

  file << "Stands: ";

  file.close();

  ifstream read("Stands");

    if (check(read, "Stands: ")){
      
      file.open("Stands", ios::app);

      for(auto&[key, value] : myStands){

        file << value << '\t'; 

      }
    }


  file.close();

  stringstream something;

  something << read.rdbuf();

  string bro;

  bro = something.str();

  const char* aaa;

  
  read.close();

  aaa = bro.c_str();

  cout << aaa << endl;




  return 0;
}
