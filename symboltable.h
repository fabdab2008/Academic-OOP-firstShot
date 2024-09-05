#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


class symbolinfo {

public:
    string name;
  string type;


  symbolinfo() {}


  symbolinfo(string a, string b) {
    name = a;
    type = b;
  }



  void set_(string a, string b) {
    name = a;
    type = b;
  }

  string get_name() {
    return name;
  }


  string get_type() {
    return type;
  }


  void get() {
    cout << "<" << name << "," << type << ">" << endl;
  }
};


int hashing(string name) {
  int l = (name.length()) * 7;
  int k = l % 7;
  return k;
}

class symboltable {
public:

  vector<symbolinfo> arr[7];

  symboltable() {}


  void insert_(symbolinfo a) {

    int ind = hashing(a.get_name());


    arr[ind].push_back(a);
  }


  bool lookup(string a) {

    int p = hashing(a);


    for (int i = 0; i < arr[p].size(); i++) {
      if (arr[p][i].get_name() == a) {
        return true;
      }
    }
    return false;
  }


  int delete_(string a) {

    int p = hashing(a);


    for (int j = 0; j < arr[p].size(); j++) {
      if (arr[p][j].get_name() == a) {

        arr[p].erase(arr[p].begin() + j);
        return j;
    }
    return 0;
  }}


  void print(ofstream &file2) {

    for (int i = 0; i < 7; i++) {

      file2 << i;


      string p = to_string(i);


      for (int j = 0; j < arr[i].size(); j++) {

        file2 << "->" << "<" << arr[i][j].get_name() << ">" << "<"
             << arr[i][j].get_type() << ">" << " ,";
      }

      file2 << endl;
    }
  }
};



