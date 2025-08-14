#include <iostream>

using namespace std;

class URL{

  private:
    string protocol;
    string resource;

  public:
    URL(const char* protocol, const char* resource){

      this->protocol = protocol;
      this->resource = resource;

    }

    void show_url(){

      cout << protocol << "://" << resource << endl;

    }
  
};


int main (int argc, char *argv[]) {
  
  URL *url = new URL{"https", "www.cppBestLanguage.com"};

  url->show_url();

  delete url;

  return 0;
}
