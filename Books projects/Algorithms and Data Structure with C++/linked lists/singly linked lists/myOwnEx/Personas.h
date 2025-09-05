#ifndef PERSONAS_H
#define PERSONAS_H

#include <iostream>
#include <string>

using namespace std;

class Personas{

  public:

    Personas(){
      next = 0;
    }

    Personas(string n, Personas* in = 0){
      
      name = n;
      next = in;

    }

    string name;
    Personas* next;
  
};

class personaList{

  private:
    //head is a pointer to the first persona 
    //tail is a pointer to the last persona
    Personas* head, *tail; 

  public:
    personaList(){
      head = tail = 0;
    }
    
    ~personaList();

    void addToHead(string name);
    void addToTail(string name);

    string deleteFromHead();
    string deleteFromTail();

    int isEmpty(){return head == 0;}

};

#endif
