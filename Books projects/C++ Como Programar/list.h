#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "listnode.h"

using std::cout;

template<typename NODETYPE>
class List{

  public:
    List();
    ~List();

    void insertAtfront(const NODETYPE&);
    void insertAtBack(const NODETYPE&);
    bool removeFromFront(NODETYPE&);
    bool removeFromBack(NODETYPE&);
    bool isEmpty() const;
    void print() const;

  private:
    ListNode<NODETYPE> *firstPtr; //ponteiro para o primeiro nó
    ListNode<NODETYPE> *lastPtr; //ponteiro para o último nó
    ListNode<NODETYPE> *getNewMode(const NODETYPE&);

}; //fim da classe List

//construtor padrao
template<typename NODETYPE>
List<NODETYPE>::List() : firstPtr(0), lastPtr(0){
  //corpo vazio
}//fim do construtor List 

//Destrutor 
template<typename NODETYPE>
List<NODETYPE>::~List(){
  if(!isEmpty()){ //a lista nao esta vazia 

    cout << "Destroying nodes...\n";

    ListNode<NODETYPE> *currentPtr = firstPtr;
    ListNode<NODETYPE> *tempPtr;

    while(currentPtr != 0) {
      //exclui nós restantes 

      tempPtr = currentPtr;
      cout << tempPtr->data << "\n";
      currentPtr = currentPtr->nextPtr;
      delete tempPtr;

    }//while


  }//if 

  cout << "All nodes destroyed\n";

}//destrutor 

//insere nó na frente da lista
template<typename NODETYPE>
void List<NODETYPE>::insertAtfront(const NODETYPE& value){

  ListNode<NODETYPE> *newPtr = getNewMode(value); //novo nó

  if (isEmpty()) //list está vazia 
    firstPtr = lastPtr = newPtr; //nova lista tem apenas um nó
  else //lista nao esta vazia 
    newPtr->nextPtr = firstPtr; //aponta novo nó para o prmeiro nó anterior
    firstPtr = newPtr; //aponta firstPtr para o novo nó
  //fim do else

}//insert at front

//insere nó no fim da lista 
template<typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE& value){

  ListNode<NODETYPE> *newPtr = getNewMode(value); //novo nó 
  
  if(isEmpty()){ //lista está vazia
    firstPtr = lastPtr = newPtr; //nova lista tem apenas um nó
  }else{ //lista nao está vazia

    lastPtr->nextPtr = newPtr; //atualiza o ultimo no anterior 
    lastPtr = newPtr; //novo ultimo nó

  }

}//insert at back

//exclui nó na frente da lista 

template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE& value){

  if(isEmpty()) //lista está vazia 
    return false; //exclusao malsucedida 
  else{
    ListNode<NODETYPE> *tempPtr = firstPtr; //armazena tempPtr para exluir
 
    if (firstPtr == lastPtr)
      firstPtr = lastPtr = 0; //nenhum nó permanece depois da exclusao 
    else 
      firstPtr = firstPtr->nextPtr; //aponta para o segundo nó anterior 

    value = tempPtr->data; //retorna os dados sendo removidos
    delete tempPtr; //reivindica só frontal anterior 
    return true; //exclusao bem sucedida

  }//else 

}//removeFromFront

//exclui no no fim da lista 
template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE& value){

  if (isEmpty()) //lista esta vazia 
    return false;
  else{

    ListNode<NODETYPE> *temPtr = lastPtr; //armazena tempPtr para excluir 

    if (firstPtr == lastPtr)
      firstPtr = lastPtr = 0;
    else {

      ListNode<NODETYPE> *currentPtr = firstPtr;

      //localiza do segundo ao ultimo elemento
      while(currentPtr->nextPtr != lastPtr){
        currentPtr = currentPtr->nextPtr; //move para o próximo nó
      }

      lastPtr = currentPtr;
      currentPtr->nextPtr = 0;

    }//else 

    value = temPtr->data; //retorna valor do ultimo no antigo 
    delete temPtr; //reivindica o primeiro ultimo no 
    return true;

  }//else 

}//remove from back


//lista está vazia?
template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const{
  return firstPtr == 0;
}//is empty

//retorna ponteiro para nó recentemente alocado
template<typename NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::getNewMode(const NODETYPE& value){

  return new ListNode<NODETYPE>(value);

}//getNewMode

//exibe o conteudo de List 

template<typename NODETYPE>
void List<NODETYPE>::print() const{

  if(isEmpty()){ //lista está vazia

    cout << "The List is empty\n\n";
    return;

  }//fim do if

  ListNode<NODETYPE>* currentPtr = firstPtr;

  cout << "The list is: ";

  while(currentPtr != 0){ //obtem dados de elemento

    cout << currentPtr->data << ' ';
    currentPtr = currentPtr->nextPtr;

  }//while 

  cout << "\n\n";

}

#endif 
