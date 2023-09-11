//Saikapish Sahu
//C++ Plaindrome Project
//9/11/23
#include <iostream>
#include <cstring>
using namespace std;

int main () {

  char str  [80]; //original char hold
  //these 2 strings will have a copy without non char letters, and will be compared 
  char str2 [80]; 
  char str3 [80];
  cin.getline(str, 80);
  int count = 0; //this is for str2 interations
  int count2 = 0; //this is for str3 iterations
  int checkcount = 0; //this is for the final check
  int length = strlen(str); //gets the string length from the input
  for (int i = 0; i < length; i++) {
    if ((str[i] > 'A' || str[i] < 'Z') && (str[i] > 'a' || str[i] < 'z') && (str[i] != ' ') && ((int)(str[i]) >= 32) && ((int)(str[i]) <= 63)){ //this checks if the char is a letter, nothing else
      str2[count] = str[i]; //copy onto str2
      str3[count2] = str2[count]; //then str3
      count++;
      count2++;

      }

  }
  count2 = count2 - 1;
  for (int i = 0; i < count; i++) { //now seeing if both strings match when one is backwards
    if (str2[i] == str3[count2]) {
      checkcount++;
    }
      count2--;
  }

  if (checkcount == count) { //check if it is the same
    cout << "You have a palindrome!" << endl;
  }
  else {
    cout << "You don't have a palindrome!" << endl;
  }

  return 0;
}
