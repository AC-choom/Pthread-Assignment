#include <iostream>
#include <fstream>
#include <vector>
#include <pthread.h>
using namespace std;

struct student{
    int id;
    int passing;
};

hmmmm

//I know we will need this we can just modify later
int main() {
  ifstream infile("students.txt");
  vector<student> students;
  int id;
  int passing;

  while(infile >> id >> passing){
    students.push_back({id, passing});
  }

  double returnPercent = calculateReturnPercent(students);
  cout << "NT: Return Percentage: " << returnPercent << "%" << endl;

  return 0;

}