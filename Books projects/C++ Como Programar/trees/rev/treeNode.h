#ifndef TREENODE_H
#define TREENODE_H

template<typename NODETYPE> class tree;

template<typename NODETYPE>
class treeNode{

  friend class tree<NODETYPE>;

  private:
    treeNode* leftSubTree;
    treeNode* rightSubTree;
    NODETYPE data;

  public:
    treeNode(const NODETYPE& d) : leftSubTree(0), rightSubTree(0), data(d){

    }
    
    NODETYPE getData() const{
      return data;
    }

}; //treeNode

#endif
