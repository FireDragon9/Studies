#include <iostream>

#include <fstream>

#include <map>

using namespace std;

bool check(string textToSearch, ifstream& data){
  string text;
  //will check everyline and then store in the text var
  while(getline(data, text)){
      
      //will check if there is the textToSearch in text 
      if(text.find(textToSearch) != string::npos){
        return true;
      }

  }

  return false;

}

int main (int argc, char *argv[]) {
  
  map<int, string> myPersonas;

  myPersonas[0] = "Arsene";
  myPersonas[1] = "Izanagi";
  myPersonas[2] = "Orpheus";

  ofstream file("personas.txt");

  file << "Personas: ";

  file.close();

  ifstream readFile("./personas.txt");

  if (check("Personas: ", readFile)){
    
    file.open("./personas.txt", ios::app);

    for (auto& [key, value] : myPersonas){

        file << value << '\t';

    }

    file.close();

  }

  

  return 0;
}
