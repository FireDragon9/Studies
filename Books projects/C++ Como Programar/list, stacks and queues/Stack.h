#ifndef STACK_H
#define STACK_H

#include "list.h"

template<typename STACKTYPE>
class Stack : private List<STACKTYPE>{

  public:
    //push chama a função List insertAtFront
    void push(const STACKTYPE& data){
      this->insertAtfront(data);
    }

    //pop chama a função List Remove from front
    bool pop(STACKTYPE& data){
      return this->removeFromFront(data);
    }

    //isStackEmpty chama a função List isEmpty
    bool isStackEmpty() const{
      return this->isEmpty();
    }

    //printStack chama a função List print 
    void printStack() const{
      this->print();
    }

  private:
    List<STACKTYPE> stackList; //objeto List composto

}; //classe 

#endif
