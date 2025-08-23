#include <iostream>

#include "list.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;


int main (int argc, char *argv[]) {
  
  /*Aloca os bytes sizeof(Node), 
   * executa o constructor Node e 
   * Atribui o endereço do novo objeto Node a newPtr*/
  //se nenhuma memoria estiver disponivel, new lança um bad_alloc

  Queue<int> intQueue; //cria Queue de inteiros

  cout << "Processing an integer Queue\n";

  for(int i = 0; i<3;i++){

    intQueue.enqueue(i);
    intQueue.printQueue();

  }//for

  int dequeueInteger; //armazena inteiro desenfileirado

  //desenfileira inteiros de intQueue 
  while(!intQueue.isQueueEmpty()){
    intQueue.dequeue(dequeueInteger);
    cout << dequeueInteger << " dequeued\n";
    intQueue.printQueue();
  }//while

  Queue<double> doubleQueue;
  double value = 1.1;

  cout << "Processing a double queue\n";

  //enfileira valores de ponto flutuante em doubleQueue
  for(int j = 0; j < 3; j++){

    doubleQueue.enqueue(j);
    doubleQueue.printQueue();
    value += 1.1;

  }

  double dequeueDouble; //armazena double desenfileirado

  while(!doubleQueue.isQueueEmpty()){

    doubleQueue.dequeue(dequeueDouble);
    cout << dequeueDouble << " dequeued\n";
    doubleQueue.printQueue();

  }


  return 0;
}
