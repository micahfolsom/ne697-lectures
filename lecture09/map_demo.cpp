#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  // We must specify both types, the key type and the value type
  // These can be whatever you want
  map<string, int> my_map = {
    {"one", 1},
    {"one thousand", 1000},
    {"two", 2}
  };
  // Access with [key]
  cout << my_map["one"] << endl;

  // Different ways to loop over the map
  // 1. Using iterators (these are just pointers, hence the ->)
  for (auto it = my_map.begin(); it != my_map.end();++it) {
    cout << "key: " << it->first << ", value: " << it->second << endl;
  }
  // Ranged-based for loop
  // Note that the type of the map elements is
  // std::pair<const KeyType, ValueType> - the keys cannot be changed!
  for (auto item : my_map) {
    cout << "key: " << item.first << ", value: " << item.second << endl;
    // To modify the values, we need to be careful what we're working with
    // "item" is a local copy in this loop; this will not persist outside of
    // it
    item.second -= 100;
    // This will stick because we're accessing the container
    my_map[item.first] += 100;
  }
  // To modify the values, we need to get the reference to the elements
  for (auto& item : my_map) {
    cout << "key: " << item.first << ", value: " << item.second << endl;
    // Now this persists outside the loop
    item.second = 10000;
  }
  // New with C++17 (need -std=c++17)
  for (auto const& [key, value] : my_map) {
    cout << "key: " << key << ", value: " << value << endl;
  }
  // Same deal with the type of the keys and values: it's auto, auto&, or
  // auto const&, depending on whether you want to modify the values (you
  // will typically use the last 2, since making a copy of the std::pair
  // might be pretty expensive)
  return 0;
}
