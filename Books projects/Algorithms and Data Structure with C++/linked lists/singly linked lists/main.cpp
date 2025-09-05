#include "intSLList.h"

int main (int argc, char *argv[]) {
  
  //creates the first node on the list and makes the variable p a pointer to this node 
  /*
    First step - new IntSLLNode is created 
    Second step - info member of this node is set to 10
    Third step - node's next member is set to null
    Fourth step - making p a pointer to the newly created node 
    
  */

  IntSLLNode *p = new IntSLLNode(10);
  p->next = new IntSLLNode(8);
  p->next->next = new IntSLLNode(50);




  return 0;
}
