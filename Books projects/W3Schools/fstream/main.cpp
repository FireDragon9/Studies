#include <iostream>

#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
  
  //table of useful fstream classes::
  /*
   * filebuf - A lower level file handling class used internally by the fstream, ifstream and ofstream 
   * fstream - a class that can read and write to files
   * ifstream - A class that can read from files 
   * ofstream - A class that can write to files 
   * */

  //CREATE AND WRITE TO A FILE 

  //create and open a text file 
  ofstream MyFile("filename.txt");

  //Write to the file 
  MyFile << "Files can be tricky, but it is fun enough!";

  //close the file 
  //Close the file is a good practice and it can clean up unnecessary memory space
  MyFile.close();

  //READ A FILE 
  
  //Create a text string which is used to output the textfile
  string myText;

  //read from the text file 
  ifstream myReadFile("filename.txt");

  //use a while loop together with the getline() function to read the file line by  line 

  while(getline(myReadFile, myText)){

    //output the text from the file 
    cout << myText << endl;

  }
  
  //close the file 
  myReadFile.close();

  return 0;
}
