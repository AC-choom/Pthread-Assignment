#include <iostream>
#include <fstream>
#include <vector>
#include <pthread.h>
using namespace std;

struct student{
    int id;
    int passing;
};

struct thread {
  vector<student> students;
  int percent;
};

//not finished i just copied and pasted the code but was gonna turn it into a void
void calculatePercent(){
  int total = students.size();
  int passingCount = 0;
  for(int i = 0; i < total; i++){
    if (students[i].passing == 1) {
      passingCount++;
    }
  }
  return (double(passingCount) / total) * 100;
}

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