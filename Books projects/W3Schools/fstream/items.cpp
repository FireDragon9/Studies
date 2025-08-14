#include <iostream>
#include <fstream>

#include <map>
#include <string>

using namespace std;

bool checkIfIsthere(string value, ifstream& data){

  string search;

  while(getline(data, search)){

    if (search.find(value) != string::npos){
      cout << "Value found.\n";
      return true;
    }

  }

  return false;

}


int main (int argc, char *argv[]) {

  map<int, const char*> myInv;

  myInv[0] = "Wooden Sword";
  myInv[1] = "Wooden Armor";

  //creating the file
  ofstream saveFile("items.txt");

  saveFile << "Items: ";

  saveFile.close();

  //reading to see if theres a Items topic
  ifstream readFile("items.txt");

  if (checkIfIsthere("Items: ", readFile)){

    saveFile.open("items.txt", std::ios::app);

    for(auto& [i, j] : myInv){

      saveFile << '\t' << '\t' << j;

    }

    saveFile.close();

  }


  return 0;
}

