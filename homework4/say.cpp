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
//If word is emplty print the whole array
  if(word.empty()){

      for(int i =0 ;i<total_words;i++){
          cout<<array[i]<<" ";

      }

  }
//otherwise store the passed word in array
  else{
      array[total_words] = word;
      ++total_words;

  }

  return *this; // Return this pointer
}

int main()
{
  Test Obj;

  Obj.say("Hello").say("my").say("name").say("is").say("Colette").say();

}
