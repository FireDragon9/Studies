#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "treeNode.h"

using namespace std;

class tree{

  private:
    treeNode* rootPtr;
    void insertNodeHelper(treeNode**, const int& num);
    void showTreeHelper(treeNode*);
  public:
  tree() : rootPtr(0){};
  
  void insertNode(const int num);
  void showTree(); 

};

void tree::insertNode(const int num){

  insertNodeHelper(&rootPtr, num);

}

void tree::insertNodeHelper(treeNode** root, const int& num){

  //nao tem um valor
  if(*root == 0){

    *root = new treeNode(num);

  }else{

    //num é menor que o 
    if(num < (*root)->data){
      
      //chama novamente a mesma função mas com o root sendo o leftPtr 
      //pois num é MENOR que que o root atual
      insertNodeHelper(&((*root)->leftPtr), num);

    }else{
      
      //checa se for maior
      if(num>(*root)->data){
        
        //chama novamente a mesma função mas com o root sendo rightPtr
        //pois num é MAIOR que o root atual
        insertNodeHelper(&((*root)->rightPtr), num);

      }else if (num == (*root)->data){ //se o valor do data do root atual for o mesmo que num
        cout << num << " duplicated\n"; //valor duplicado
      }

    }//else
    
  }//else

}//insertNodeHelper

void tree::showTree(){
  showTreeHelper(rootPtr);
}

void tree::showTreeHelper(treeNode* root){

  if(root != 0){

    cout << root->data << ' ';
    showTreeHelper(root->leftPtr);
    showTreeHelper(root->rightPtr);

  }

}

#endif // !TREE_H
