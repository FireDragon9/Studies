#ifndef TREENODE_H
#define TREENODE_H

class tree;

class treeNode{

  friend class tree;

  private:
    
    treeNode* leftPtr, *rightPtr;
    int data;

  public:
    treeNode(const int& num) : leftPtr(0), rightPtr(0), data(num){};

    int getData(){
     return data;
    }

}; //class 


#endif // !TREENODE_H
