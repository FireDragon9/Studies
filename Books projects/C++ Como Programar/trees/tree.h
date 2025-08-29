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
    void insertNode(const NODETYPE&); //insere novo nó na árvore 
    //percorrem a árvore de forma designada
    //cada uma dessas funções membro chama sua propria função utiitária recursiva separada para realizar as operações apropriadas na representação 
    //interna da árvore 
    //assim, o programa não precisa acessar os dados private subjacentes para realizar essas funções 
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;


  private:
    TreeNode<NODETYPE> *rootPtr; //ponteiro para o nó-raiz 

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
//chamado por insertNode para inserir recursivamente um nó na linha
//um nó pode somente ser inserido como um nó-folha  em uma árvore de pesquisa binária
//primeiro argumento de inserNodeHelper é declarado como um ponteiro para um ponteiro para uma TreeNode
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper( TreeNode<NODETYPE>**ptr, const NODETYPE& value){

  //subárvore está vazia; cria novo TreeNode contendo o valor
  if(*ptr == 0){
    *ptr = new TreeNode<NODETYPE>(value);
  }else{
    
    //programa compara o valor a ser inserido com o valor data no nó-raiz 
    
    //os dados a inserir sao menores que os dados no nó atual
    if(value < (*ptr)->data){ 
    
      insertNodeHelper(&((*ptr)->leftPtr), value); //insere o valor na subárvore esquerda
    
    }else{

      //os dados a inserir sao maiores que os dados no nó atual
      if(value>(*ptr)->data){
        insertNodeHelper(&((*ptr)->rightPtr), value); //insere o valor na subárvore direita 
      }else{ //se o valor a ser inserido é identico aos valores dos dados no nó raiz 
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
