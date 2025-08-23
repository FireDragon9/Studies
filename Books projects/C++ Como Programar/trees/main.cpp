#include <iostream>
using std::cout;
using std::cin;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "tree.h"

int main (int argc, char *argv[]) {
  
  Tree<int> intTree; //cria Tree de valores int
  int intValue;

  cout << "Enter 10 integer values\n";

  for(int i = 0; i < 10; i++){
    cin >> intValue;
    intTree.insertNode(intValue);
  }//for

  cout << "\nPreorder traversal\n";
  intTree.preOrderTraversal();

  cout << "\nInorder traversal\n";
  intTree.inOrderTraversal();

  cout <<"\nPostorder traversal\n";
  intTree.postOrderTraversal();

  return 0;
}
