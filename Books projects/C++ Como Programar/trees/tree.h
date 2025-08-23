#ifndef TREE_H
#define TREE_H

#include <iostream>

using std::cout;
using std::endl;

#include "treenode.h"

//definição de template de classe Tree
template<typename NODETYPE> class Tree{

  public:

    Tree(); //constructor
    void insertNode(const NODETYPE&);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;


  private:
    TreeNode<NODETYPE> *rootPtr;

    //funções utilitárias
    void insertNodeHelper(TreeNode<NODETYPE>**, const NODETYPE&);
    void preOrderHelper(TreeNode<NODETYPE>*) const;
    void inOrderHelper(TreeNode<NODETYPE>*) const;
    void postOrderHelper(TreeNode<NODETYPE>*) const;



}; //class Tree

//construtor
template<typename NODETYPE>
Tree<NODETYPE>::Tree(){
  rootPtr = 0; //indica que a árvore está inicialmente vazia
}//construtor

//insere nó em Tree
template<typename NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE& value){
  insertNodeHelper(&rootPtr, value);
}//insertNode

/*Função utilitária chamada por insertNode; recebe um ponteiro
 * para que a função possa modificar o valor do ponteiro*/
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper( TreeNode<NODETYPE>**ptr, const NODETYPE& value){

  //subárvore está vazia; cria novo TreeNode contendo o valor
  if(*ptr == 0){
    *ptr = new TreeNode<NODETYPE>(value);
  }else{

    //os dados a inserir sao menores que os dados no nó atual
    if(value < (*ptr)->data){
      insertNodeHelper(&((*ptr)->leftPtr), value);
    }else{

      //os dados a inserir sao maiores que os dados no nó atual
      if(value>(*ptr)->data){
        insertNodeHelper(&((*ptr)->rightPtr), value);
      }else{
        cout << value << " dup\n";
      }//else

    }//else

  }//else

}//insertNodeHelper

//inicia percurso na pré-ordem de Tree
template<typename NODETYPE>
void Tree<NODETYPE>::preOrderTraversal() const{
  preOrderHelper(rootPtr);
}//preOrderTraversal

//função utilitaria para executar o percurso na pre-ordem de Tree
template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE>* ptr) const{

  if(ptr != 0){

    cout << ptr->data << ' '; //processa nó
    preOrderHelper(ptr->leftPtr); //percorre subarvore esquerda
    preOrderHelper(ptr->rightPtr); //percorre subárvore direita

  }//if


}//preOrderHelper

//inicia percurso na ordem de Tree
template<typename NODETYPE>
void Tree<NODETYPE>::inOrderTraversal() const{

  inOrderHelper(rootPtr);
  
}//inOrderTraversal

//função utilitaria para realizar o percurso na ordem de Tree
template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE>* ptr) const{

  if(ptr != 0){
    inOrderHelper(ptr->leftPtr); //percorre subárvore esquerda
    cout << ptr->data << ' '; //processa nó 
    inOrderHelper(ptr->rightPtr); //percorre subárvore direita 
  }//if

}//inOrderHelper

//inicia o percurso na pós-ordem de Tree
template<typename NODETYPE>
void Tree<NODETYPE>::postOrderTraversal() const{
  postOrderHelper(rootPtr);
}

//função utilitaria para realizar o percurso de pos=ordem de tree
template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE>* ptr) const{

  if (ptr != 0){

    postOrderHelper(ptr->leftPtr); //percorre subárvore esquerda
    postOrderHelper(ptr->rightPtr); //percorre arvore direita
    cout << ptr->data << ' ';

  }//if

}

#endif
