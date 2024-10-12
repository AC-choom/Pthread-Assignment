#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct student{
    int id;
    int passing;
};

double calculateReturnPercent(vector<student>& students){
  int total = students.size();
  int passingCount = 0;
  for(int i = 0; i < total; i++){
    if (students[i].passing == 1) {
      passingCount++;
    }
  }
  return (double(passingCount) / total) * 100;
}

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


