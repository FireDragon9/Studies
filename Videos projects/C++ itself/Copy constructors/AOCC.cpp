#include <iostream>
#include <list>
#include <string>
using namespace std;

struct YouTubeChannel {

  string Name;
  int SubscribersCount;

  YouTubeChannel(string name, int subcribersCount) {

    Name = name;
    SubscribersCount = subcribersCount;

  } // constructor

  bool operator==(const YouTubeChannel &channel) {

    return this->Name == channel.Name;

  } // operator ==

}; // struct

ostream &operator<<(ostream &COUT, YouTubeChannel &ytChannel) {

  COUT << "Name: " << ytChannel.Name << endl;
  COUT << "Subs: " << ytChannel.SubscribersCount << endl;

  return COUT;
} // void operator<<

struct MyCollection {

  list<YouTubeChannel> myChannels;

  void operator+=(YouTubeChannel &channel) {
    this->myChannels.push_back(channel);
  } // opetator+=

  void operator-=(YouTubeChannel &channel) {
    this->myChannels.remove(channel);
  } // opetator+=
};

ostream &operator<<(ostream &COUT, MyCollection &myCollection) {

  for (YouTubeChannel ytChannel : myCollection.myChannels) {

    COUT << ytChannel << endl;
  }

  return COUT;

} // operator<<

int main(int argc, char *argv[]) {

  YouTubeChannel yt1 = YouTubeChannel("KillerGamer37", 200000000);
  YouTubeChannel yt2 = YouTubeChannel("DeathGamer2", 90000);
  MyCollection myCollection;
  myCollection += yt1;
  myCollection += yt2;
  myCollection -= yt2;
  cout << myCollection;

  cin.get();
  return 0;
}
