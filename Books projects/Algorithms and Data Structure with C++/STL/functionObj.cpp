#include <functional>
#include <iostream>

#include <numeric>

using namespace std;

class classf{

  public:
    classf(){}
    //overloads function call operator
    double run(double x){
      return 2*x;
    }

};

//defining
double sum2 (double f, int n, int m){
  double result = 0;
  for (int i = n; i<= m; i++){
    result += 2*i;
  }
  return result;
}

template<class F>
double sum(F f, int n, int m){

  double result = 0;
  for (int i = n; i <= m; i++){
    result += f(i);
  }
  return result;
}

int main (int argc, char *argv[]) {
  
  classf cf;
  cout << sum(negate<double>(), 2, 5) << endl;

  

  return 0;
}
