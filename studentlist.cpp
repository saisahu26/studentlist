//sai sahu
//student list c++
//10/16/23
//calling from c++ library

#include <iostream>
#include <cstring>
#include<iterator>
#include <iomanip>
#include <vector>

using namespace std;

struct Student {

  char fname [20];//maximum characters for first and last name 
  char lname [20]; 
  int id;//id number
  float gpa; //gpa number (with decimals)

};

void add (vector <Student*> &studentlist); //passing all the vectors for each method
void print (vector<Student*> &studentlist); 
void deleteSt(vector<Student*> &studentlist);


int main () { //main function for calling all the prompts and conditions for each answer
  int scount = 0;
  bool active = true;
  vector<Student*> studentlist;
  while(active == true) {
    cout << "add print delete or quit" << endl; //starting prompt to ask for which option you want
    char input [20];
    //cout << active << endl;
    cin >> input;
    //the four options you can do by calling each function
    if (strcmp(input, "add") == 0) {
      add(studentlist);
    }
    if (strcmp(input, "print") == 0) {
    print(studentlist);
  }
    if (strcmp(input, "delete") == 0) {
      deleteSt(studentlist);
    }
    if (strcmp(input, "quit") == 0) {
      active = false;
    }
  }
  return 0;
 
}

void add (vector<Student*> &studentlist) { //the class that hold the information assigned to each student (name, id, and gpa)
    Student *st = new Student;
    cout << "enter first name" << endl;
    cin >> st -> fname;
    cout << "enter last name" << endl;
    cin >> st -> lname;
    cout << "enter id" << endl;
    cin >> st -> id;
    cout << "enter gpa" << endl;
    cin >> st -> gpa;//inputing the gpa as float
    studentlist.push_back(st);
  }

void print (vector<Student*> &studentlist) { //this funtions prints all of the information about the student
    vector<Student*>:: iterator it;
    for (it = studentlist.begin(); it < studentlist.end(); it++) {
      cout << "first name: " << (*it) -> fname << " last name: " << (*it) -> lname << " id number: " << (*it) ->id << " gpa: " << fixed << setprecision(2) << (*it) -> gpa << endl; //calling all of the vectors and methods to get the name, id and gpa

    }
  }

void deleteSt (vector<Student*> &studentlist) { //delete function which takes in the id and checks which student it is assigned to
  int input;
  cout << "enter the id of student to delete" << endl;
  cin >> input;
  vector<Student*>:: iterator it;
  for (it = studentlist.begin(); it < studentlist.end(); it++) {
    if ((input == (*it) -> id)) { //id check
    delete *it;
    studentlist.erase(it);
      
    break;
    }
  }
  
}

  


