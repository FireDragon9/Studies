
#include <vector>

#include <string>

#include <iostream>

#include <algorithm>

using namespace std;

class Personas{

  private:

    string name;


  public:

    string getName(){ return name; };

    Personas(string pName){ name = pName; };
    
};

/////////

int main (int argc, char *argv[]) {

  Personas arsene("arsene");

  Personas pixie("pixie");

  Personas jackFrost("jack frost");

  //vector of personas 
  
  vector<Personas> avPersonas = {arsene, pixie, jackFrost};

  //iterator of personas 
  
  vector<Personas>::iterator myPersonas;

  vector<Personas>::iterator compendium;


  for (myPersonas = avPersonas.begin(); myPersonas != avPersonas.end(); ++myPersonas){

    cout << myPersonas->getName() << endl;


  }


  return 0;
}
