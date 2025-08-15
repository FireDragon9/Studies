#include <iostream>

#include "list.h"


using namespace std;

//função para testar uma list 

void instructions(){

  cout << "Enter one of the following:\n" 
       << "1 to insert at the beginning of the list\n" 
       << "2 to insert at the end of the list\n"
       << "3 to delete from the beginning of the list\n"
       << "4 to delete from the end of the list\n"
       << "5 to end list processing\n";

}

template<typename T>
void testList(List<T>&listObject, const string& typeName){

  cout << "Testing a List of" << typeName << " value\n";

  instructions(); 

  int choice; //armazena a escolha do usuario
  T value;

  do {
  
    cout << "? ";
    cin >> choice;

    switch(choice){

      case 1: //insere no inicio
        cout << "Enter " << typeName <<": ";
        cin >> value;
        listObject.insertAtfront(value);
        listObject.print();
        break;

      case 2: //insere no final
        cout << "Enter: " << typeName << ": ";
        cin >> value;
        listObject.insertAtBack(value);
        listObject.print();
        
        break;
      case 3: //remove do inicio 
        if(listObject.removeFromFront(value))
          cout << value << " removed from list\n";
        listObject.print();
        break;

      case 4: //remove do final 
        if(listObject.removeFromBack(value))
          cout << value << " removed from list\n";
        listObject.print();

        break;

    }//switch


  }while (choice != 5);

  cout << "End list test\n";

}



int main (int argc, char *argv[]) {
  
  /*Aloca os bytes sizeof(Node), 
   * executa o constructor Node e 
   * Atribui o endereço do novo objeto Node a newPtr*/
  //se nenhuma memoria estiver disponivel, new lança um bad_alloc

  //testa list de valores int 
  List<int> integerList;
  testList(integerList, "integer");

  


  return 0;
}
