#include "Personas.h"

personaList::~personaList(){

  //while the head has something other than nullptr
  for(Personas* p; !isEmpty();){
   
    p = head->next; //makes p go and keep the next value in head 
    delete head; //delete  the head
    head = p; //and makes the head now what was the next value 

  } 

}

void personaList::addToHead(string name){

  //creating a new persona to put it on head; the first Persona 
  head = new Personas(name, head);
  if (tail == 0) tail = head;


}

void personaList::addToTail(string name){

  if (tail != 0){ //if the list is not empty

    tail->next = new Personas(name); //add the persona to the tail/end of the list 
    tail = tail->next; //makes the next of the persona we just add be the tail/end of the list

  }else{ //else it is empty
  
    head = tail = new Personas(name); 

  } 

}

string personaList::deleteFromHead(){

  string el = head->name;

  Personas* tmp = head;

  if (head == tail){ //if only one persona in the list
    head = tail = 0;
  }

  delete tmp;
  return el;

}

string personaList::deleteFromTail(){

  string el = tail->name;

  if (head == tail){ //if only one node in the list 
    head = tail = 0;
  }else{ //if more than one node in the list 

    Personas* tmp; //finding the predecessor of current tail 
    //starting with tmp being head 
    //while the next Persona is not the current tail 
    //then the tmp is the next Persona
    for(tmp = head; tmp->next != tail; tmp = tmp->next);
    delete tail;
    tail->next = 0;

  }

  return el;
}
