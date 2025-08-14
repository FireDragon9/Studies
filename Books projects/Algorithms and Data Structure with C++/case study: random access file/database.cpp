#include <ios>
#include <iostream>

#include "student.h"
#include "personal.h"
#include "database.h"

template<class T>
Database<T>::Database(){

}

//places a record at the end of file

template<class T>
void Database<T>::add(T& d){
  database.open(fName, ios::in|ios::out|ios::binary);
  database.seekp(0, ios::end);
  d.writeToFile(database);
  database.close();
}

///////////////////////

//the function modify updates information stored in a particular record.

template<class T>
void Database<T>::modify(const T& d){
  
  /*The record is first retrieved from the file, also using sequential serach 
   * and the new information is read from the user using the overloaded input operator >>*/

  /*To store the updated record tmp in the file, modify() forsces the file pointer database 
   * to go back to the eginning of the record tmp that has just been read; otherwise, the record 
   * followind tmp in the file would be overwritter
   * The startinf point of tmp can be determined immediately because each record occupies the 
   * same number of byter; therefore, it is enough to jump back the number of bytes occupied by one
   * record */

  T tmp;
  database.open(fName, ios::in|ios::out|ios::binary);
  while(!database.eof()){

    tmp.readFromFile(database);
    if(tmp == d){ //overloaded ==
      cin >> tmp; //overloaded >>
      database.seekp(-d.size(), ios::cur);
      tmp.writeToFile(database);
      database.close();
      return;

    }//if tmp == d

  }//while

  database.close();
  cout << "The record to be modified is not in the database\n";

}//modify

////////////////////q

//find() determines whether a record is in the file. 

template<class T>
bool Database<T>::find(const T& d){
  
  //it performs the serach sequentially comparing each retrieved record tmp 
  //to the sought record d using an overloaded equality operator ==
  T tmp;
  database.open(fName,ios::in|ios::binary);
  while(!database.eof()){

    tmp.readFromFile(database);
    if (tmp == d){  //overloaded ==
      database.close();
      return true;
    }

  }//while

  database.close();
  return false;

}//find

template<class T>
ostream& Database<T>::print(ostream& out){

  T tmp;
  database.open(fName, ios::in|ios::binary);
  while(true){

    tmp.readFromFile(database);
    if(database.eof()){
      break;
    }

    out << tmp << endl; //overloaded <<

  }//while

  database.close();
  return out;

}

template<class T>
void Database<T>::run(){

  cout << "File name: ";
  cin >> fName;
  char option[5];
  T rec;
  cout << "1. Add 2. Find 3. Modify a record; 4. Exit\n";
  cout << "Enter an option: ";
  cin.getline(option, 4); //get '\n'

  while(cin.getline(option, 4)){

    if (*option == '1'){
      cin >> rec; //overloaded >>
      add(rec);
    }else if(*option == '2'){
      
      rec.readKey();
      cout << "The record is ";
      
      if (find(rec) == false)
        cout << "Not ";
      cout << "in the database\n";

    }else if(*option == '3'){
    
      rec.readKey();
      modify(rec);
    
    }else if (*option != '4')

        cout << "Wrong option\n";
    else return;
    
    cout << *this; //overloaded <<
    cout << "Enter an option: ";
    

  }//while cin getline 

}
