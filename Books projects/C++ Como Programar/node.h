#ifndef NODE_H
#define NODE_H

class Node{

  public:
    Node(int); //constructor
    void setData(int); //constructor 
    void setNextPtr(Node*); //Configura ponteiro como proximo node 
    Node *getNextPtr() const; //obtem ponteiro para proximo node 

  private:
    int data; //dados armazenados nesse node
    Node *nextPtr; //ponteiro para outro objeto do mesmo tipo 
};

#endif
