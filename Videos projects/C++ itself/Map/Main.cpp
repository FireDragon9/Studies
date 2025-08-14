#include <iostream>
#include <map>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
  
  //Associates string with another string 
  //The key is ALWAYS data type
  //The value can be a complex data type
  
  //It organize automatic
  //
  //keys have to be unique
  //values have not to be unique
  //
  map<string, string> myDictionary;
  myDictionary.insert(pair<string, string>("Banana", "die Banane"));
  myDictionary.insert(pair<string, string>("Strawberry", "die Erdbeere"));
  myDictionary.insert(pair<string, string>("Apple", "der Apfel"));
  myDictionary.insert(pair<string, string>("Orange", "die Orange, die Apfselsine"));

  myDictionary["strawberry"]="Die Erdbeere";

  myDictionary.clear();
  
  cout << myDictionary.size() << endl;

  for(auto pair:myDictionary){
    cout<<pair.first<<" - " << pair.second << endl;
  }

  return 0;
}
