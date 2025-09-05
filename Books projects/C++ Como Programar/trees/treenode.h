#ifndef TREENODE_H
#define TREENODE_H

//encaminha a declaração da classe tree 
template <typename NODETYPE> class Tree;

//definição do template de classe TreeNode 
template<typename NODETYPE>
class TreeNode{

  friend class Tree<NODETYPE>;

  public:
  //constructor
  TreeNode(const NODETYPE& d) : 
  leftPtr(0), //ponteiro para a arvore esquerda 
  data(d), //dados de nó de árvore
  rightPtr(0) //ponteiro para subarvore direita
  {

  }

  //retorna a cópia de dados do nó 
  NODETYPE getData() const{
    return data;
  }//getData

  private:

    TreeNode<NODETYPE>* leftPtr; //ponteiro para subarvore esquerda
    NODETYPE data;
    TreeNode<NODETYPE>* rightPtr; //ponteiro para a arvore direita

}; //Treenode

#endif
