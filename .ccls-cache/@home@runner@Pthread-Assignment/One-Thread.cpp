#include <iostream>
#include <fstream>
#include <pthread.h>
using namespace std;

struct student{
    int id;
    int passing;
};
struct thread{
student* grades;
int size;
int passingCount;
};


//not finished i just copied and pasted the code but was gonna turn it into a void
void *calculateReturnPercent(void*arg){
  thread*data=(thread*)arg;
  data->passingCount = 0;
  for(int i = 0; i < data->size; i++){
    if (data->grades[i].passing == 1) {
      data->passingCount++;
    }
  }
  //calculation for those who passed 
  pthread_exit(NULL);
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
  
  int numbers=0;
  // this will put get the data from the file and it will be put into the array 
  while(numbers < Students && inputStream >> grades[numbers].id >> grades[numbers].passing){
    numbers++;
  }
  thread data;
  data.grades = grades;
  data.size =  numbers;
pthread_t thread;

   pthread_create(&thread, NULL, calculateReturnPercent, &data);
  pthread_join(thread, NULL);
  
  inputStream.close();
  double percent = (double(data.passingCount) /data.size) * 100;
  cout << "OT: Return Percentage: " << percent << "%" << endl;

  return 0;

}