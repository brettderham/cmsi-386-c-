#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <algorithm>

using namespace std;

std::string trim(std::string const& str)
{
   std::string word;
   std::stringstream stream(str);
   stream >> word;

   return word;
}

int main () {
  string line,full_string="";
  ifstream myfile ("word_count.txt");
  if (myfile.is_open()) {
    while ( getline (myfile,line) )
    {
      full_string=full_string+" "+line;
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  int words = 0,start=0,j=0,size=0,flag=0; // Holds number of words
  string w[30];
  int count[30];
  for(int i = 0; i < full_string.size(); ++i) {
     if (!((full_string[i] >= 'a' && full_string[i]<='z') || (full_string[i] >= 'A' && full_string[i]<='Z')))
     {
       full_string[i] = ' ';
     }
   }

  std::transform(full_string.begin(), full_string.end(), full_string.begin(), ::tolower);

  for(int i = 0; full_string [i] != '\0'; i++) {
    flag=0;
    size++;
    if (full_string [i] == ' ') {//Checking for spaces
      std::string str(full_string.substr(start,size));
      std::string t = trim(str);
      for(int k=0;k<j;k++) {
        if(t.compare(w[k])==0) {
          count[k]=count[k]+1;
          flag=1;
          size=0;
          start=i+1;
          break;
        }
      }
      if(flag==0) {
        if(full_string.substr(start,size).compare(" ")==0) {
        }
        else {
          w[j]=t;
          count[j]=1;
          j++;
          start=i+1;
          size=0;
          words++;
        }
      }
    }
  }
  for(int i=0;i<j;i++) {
    for(int k=i+1;k<j;k++) {
      if(count[i]<count[k]) {
      int tmp;
      tmp=count[i];
      count[i]=count[k];
      count[k]=tmp;
      string temp;
      temp=w[i];
      w[i]=w[k];
      w[k]=temp;
    }
  }
}
for(int i=0;i<j;i++) {
  cout<<w[i]<<" "<<count[i]<<endl;
}

return 0;
}
