#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> //greater<T>

using namespace std;

template<class T>
void printVector(char* s, const vector<T>& v){
    cout << s << "= (";
    if (v.size() == 0){
      cout << ") \n";
      return;
    }

    typename vector<T>::const_iterator i = v.begin();
    for(; i != v.end()-1; i++){
        cout << &i << ' ';
      }

    cout << &i << ")\n";

}

bool f1(int n){
  return n < 4;
}

class Person{

  private:
    char* name;
    int age;
    friend bool lesserAge(const Person&, const Person&);

  public:
    Person(char *n = "", int a = 0){
      name = strdup(n);
      age = a;
    }

    ~Person(){
      free(name);
    }
 
    bool operator==(const Person& p) const{
      return strcmp(name, p.name) == 0 && age == p.age;
    }

    bool operator<(const Person& p) const{
      return strcmp(name, p.name) < 0;
    }

    bool operator>(const Person& p) const{
      return !(*this == p) && !(*this < p);
    }


};//class person

int main (int argc, char *argv[]) {
  
  vector<Person> v6(1, Person("Ren", 17));

  //adding to v6 two more objects
  v6.push_back(Person("Ann", 15));
  v6.push_back(Person("Ryuji", 16));

  sort(v6.begin(), v6.end());

  printVector("v6", v6);

  /*
  int a[] = {1, 2, 3, 4, 5};

  vector<int> v1; //v1 is empty, size = 0, capacity = 0
  printVector("v1", v1);

  //v1 is declared empty and then new elements are inserted with the function push_back()
  //adding a new element to the vector is usually fast unless the vector is full and has to be copied
  //to a new block. This situation occurs if the size of the vector equals to its capacity
  for(int j = 1; j <= 5; j++){
    v1.push_back(j); // v1 = (1 2 3 4 5), size = 5, capacity = 8
  }

  vector<int> v2(3, 7); //v2 = (7 7 7)
  vector<int>::iterator i1 = v1.begin()+1;
  vector<int> v3(i1, i1+2); //v3 = (2 3), size = 2, capacity = 8
  vector<int> v4(v1); //v4 = (1 2 3 4 5), size = 5, capacity = 5
  vector<int> v5(5); //v5 = (0 0 0 0 0)
  v5[1] = v5.at(3) = 9; //v5 = (0 9 0 9 0)
  
  //changing the vectors capacity tiwh reserve()
  //affects only the capacity, not its contents
  v3.reserve(6); //v3 = (2 3), size = 2, capacity = 6
  
  //resize affects contents and possibly the capacity
  v4.resize(7); //v4 = (1, 2, 3, 4, 5, 0, 0), size = 7, capacity = 10
  v4.resize(3); //v4 = (1 2 3), size = 3, capacity = 10
  v4.clear(); //v4 is empty, size = 0, capacity = 10 (!)
  v4.insert(v4.end(), v3[1]); //v4 = (3)
  v4.insert(v4.end(), v3.at(1)); //v4 = (3 3)
  v4.insert(v4.end(), 2, 4); //v4 = (3 3 4 4)
  v4.insert(v4.end(), v1.begin()+1, v2.end()-1); //v4 = (3 3 4 4 2 3 4)
  v4.erase(v4.end()-2); //v4 = (3 3 4 4 2 4)
  v4.erase(v4.begin(), v4.begin()+4); //v4 = (2 4)
  v4.assign(3, 8); //v4 = (8 8 8)
  v4.assign(a, a+3); //v4 = (1 2 3)
  
  vector<int>::reverse_iterator i3 = v4.rbegin();

  for(; i3 != v4.rend(); i3++){
    cout << *i3 << ' '; //print 3 2 1
  }
  
  cout << endl;


  //algorithms
  
  //all the STL algorithmns can be applied to vectors 
  v5[0] = 3;    //v5 = (3 9 0 9 0)
  //applies f1 to all elements of v5 and replaces all elements less than 4 with 7
  replace_if(v5.begin(), v5.end(), f1, 7); //v5 = (7 9 7 9 7)
  v5[0] = 3; v5[2] = v5[4] = 0;   //v5 = (3 9 0 9 0)
  //replaces all 0s with 7s in v5 
  replace(v5.begin(), v5.end(), 0, 7);    //v5 = (3 9 7 9 7)
  sort(v5.begin(), v5.end());   //v5 = (3 7 7 9 9)
  //sorting from highest to lowest
  sort(v5.begin(), v5.end(), greater<int>()); //v5 = (9 9 7 7 3)
  v5.front() = 2;

  */ 

  return 0;
}
