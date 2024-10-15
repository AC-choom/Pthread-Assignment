#include <iostream>
#include <fstream>
#include <pthread.h>
using namespace std;

struct student{
    int id;
    int passing;
};



//not finished i just copied and pasted the code but was gonna turn it into a void
int calculateReturnPercent(student grades[],int size){
  int passingCount = 0;
  for(int i = 0; i < size; i++){
    if (grades[i].passing == 1) {
      passingCount++;
    }
  }
  //calculation for those who passed 
  return (passingCount / size) * 100;
}

//I know we will need this we can just modify later
int main() {
 const int Students = 10; 
  student grades[Students];
  ifstream inputStream;
  ofstream outputStream;
  string nameofFile;
  cout<<"Enter the designated file you are looking for"<<endl;
  cin>>nameofFile;
  inputStream.open(nameofFile);
  if(inputStream.fail())
  {
      cout<< "Ouuu out of luck can't find the file"  <<endl;

  }
  inputStream.close();
  int numbers=0;
  // this will put get the data from the file and it will be put into the array 
  while(numbers< Students && inputStream >> grades[numbers].id >> grades[numbers].passing){
    numbers++;
  }

  int returnPercent = calculateReturnPercent(grades,numbers);
  cout << "NT: Return Percentage: " << returnPercent << "%" << endl;

  return 0;

}