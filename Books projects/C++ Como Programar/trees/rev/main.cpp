#include "tree.h"

int main (int argc, char *argv[]) {

  tree myTree; 

  myTree.insertNode(52);
  myTree.insertNode(19);
  myTree.insertNode(2);
  myTree.insertNode(92);
  myTree.insertNode(1);
  myTree.insertNode(8);
  myTree.insertNode(3);

  myTree.showTree();
  return 0;
}
