#include <cstdint>
#include <iostream>

#include <map>

#include <unordered_map>
#include <vector>

using namespace std;

struct CityRecord{

  string Name;
  uint64_t Population;
  double latitude, Longitude;

};

namespace std{

  template<>
  struct hash<CityRecord>
  {
      size_t operator()(const CityRecord& key){
      return hash<string>()(key.Name);
    }
  };

}

int main (int argc, char *argv[]) {
  
  //Map associate a key to a data

  unordered_map<string, CityRecord> cityMap;
  unordered_map<CityRecord, uint64_t> foundedMap;

  cityMap["London"] = CityRecord {"London", 2313122, 2.5, 6.2};

  CityRecord londonData = cityMap["London"];

  cout << londonData.Name << endl;

  return 0;
}
