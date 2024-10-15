#include <iostream>
#include <fstream>
using namespace std;

struct student{
    int id;
    int passing;
};

double calculateReturnPercent(student students[], int total){
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
  student students[8];
  int count = 0;
  int id;
  int passing;

  while(infile >> id >> passing && count < 8){
    students[count].id = id;
    students[count].passing = passing;
    count++;
  }

  double returnPercent = calculateReturnPercent(students, count);
  cout << "NT: Return Percentage: " << returnPercent << "%" << endl;

  return 0;

}


