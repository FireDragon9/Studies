#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template<typename QUEUETYPE>
class Queue : private List<QUEUETYPE>{

  public:
    //enqueue chama função membro List insertAtBack
    void enqueue(const QUEUETYPE& data){
      this->insertAtBack(data);
    }

    //denqueue chama a função membro list removeFromFront
    bool dequeue(QUEUETYPE& data){
      return this->removeFromFront(data);
    }
    
    //isQueueEmpty chama a função-membro List isEmpty
    bool isQueueEmpty() const{
      return this->isEmpty();
    }

    //printQueue chamam a função membro print
    void printQueue()const{
      this->print();
    }

};

#endif
