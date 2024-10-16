#include <iostream>
#include <fstream>
#include <pthread.h>
#include <cstdlib>
using namespace std;

struct student{
    int id;
    int passing;
};

struct thread{
student* students;
int starting;
int ending;
int passingCount;
};

void* calculateReturnPercent(void* arg){
  thread* data = (thread*) arg;
  data->passingCount = 0;
  for(int i = data->starting; i < data->ending; i++){
    if (data->students[i].passing == 1){
      data->passingCount++;
    }
  }
  pthread_exit(NULL);
}

void* messagetoUser(void* arg){
  cout << "MT: Hi User! How has your day been?" << endl;
  pthread_exit(NULL);
}

int stringToInt(char* str){
  int num = 0;
  for (int i = 0; str[i] != '\0'; i++){
    num = num * 10 + (str[i] - '0');
  }
  return num;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    return 1;
  }
  int numThreads = stringToInt(argv[1]);

  ifstream inputStream;
  string fileName;
  student students[10];
  int id;
  int passing;
  cout << "Enter the file you are looking for: " << endl;
  cin >> fileName;
  inputStream.open(fileName);
  if(inputStream.fail()){
    cout << "Damn, no file found" << endl;
    return 1;
  }
  int count = 0;
  while(inputStream >> id >> passing && count < 10){
    students[count].id = id;
    students[count].passing = passing;
    count++;
  }
  inputStream.close();

  pthread_t threads[numThreads + 1];
  thread data[numThreads];
  int studentsPerThread = count / numThreads;

  for(int i = 0; i < numThreads; i++){
    data[i].students = students;
    data[i].starting = i * studentsPerThread;
    data[i].ending = (i + 1) * studentsPerThread;
    pthread_create(&threads[i], NULL, calculateReturnPercent, &data[i]);
  }

  pthread_create(&threads[numThreads], NULL, messagetoUser, NULL);

  int totalPassing = 0;
  for (int i = 0; i < numThreads; i++){
    pthread_join(threads[i], NULL);
    totalPassing += data[i].passingCount;
  }

  pthread_join(threads[numThreads],NULL);

  double percent = (double(totalPassing) / count) * 100;
  cout << "MT: Return Percentage: " << percent << "%" << endl;

  return 0;

}


