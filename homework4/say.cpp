#include<iostream>
#include <string>
using namespace std;
class Test
{
public:
  string array[500];
  int total_words =0;
  Test say(string word="");

};
Test Test::say(string word)
{
  if(word.empty()){
      for(int i =0 ;i<total_words;i++){
          cout<<array[i]<<" ";
      }
  } else {
    array[total_words] = word;
    ++total_words;
  }
  return *this;
}

int main() {
  Test Obj;
  Obj.say("This").say("program").say("works").say();
}
