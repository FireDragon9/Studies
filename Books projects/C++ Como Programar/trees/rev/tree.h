#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "treeNode.h"

using namespace std;

template <typename NODETYPE>class tree{

  private:
    treeNode<NODETYPE>* rootTree;
    
    //funções utilitária
    void insertNodeHelper(treeNode<NODETYPE>**, const NODETYPE&);

  public:
    
    tree();

    void insertNode(const NODETYPE&); //vai chamar insertNodeHelper recursivamente  

}; //tree

template<typename NODETYPE>
tree<NODETYPE>::tree(){
  rootTree = 0;
}

template<typename NODETYPE>
void tree<NODETYPE>::insertNode(const NODETYPE& value){
  insertNodeHelper(&rootTree, value);
}

template<typename NODETYPE>
void tree<NODETYPE>::insertNodeHelper(treeNode<NODETYPE>** ptr,  const NODETYPE& value){

  //subárvore está vazia; cria novo treeNode
  if(*ptr == 0){

    *ptr = new treeNode<NODETYPE>(value);

  }else{

    //checando se os dados a inserir sao menores que os dados do nó atual
    if(value < (*ptr)->data){
    
      insertNodeHelper(&((*ptr)->leftSubTree), value); //insere valor na subarvore esquerda 
    
    }else{ //os dados a inserir sao maiores que o dado atual 

      if (value > (*ptr)->data){
        
        insertNodeHelper(&((*ptr)->rightSubTree), value);
    
      }else{ //o valor é o mesmo

        cout << value << " dup\n";

      }//else
    
    }//else


  }//else

}//insertNodeHelper


#endif
