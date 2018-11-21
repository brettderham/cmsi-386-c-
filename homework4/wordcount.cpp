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
string line,final_string="";
ifstream myfile ("wordcounttester.txt");
if (myfile.is_open()) {
  while ( getline (myfile,line) ) {
    final_string=final_string+" "+line;
  }
  myfile.close();
}
else cout << "Unable to open file";
int words = 0,start=0,j=0,size=0,flag=0;
string w[30];
int count[30];
for(int i = 0; i < final_string.size(); ++i) {
  if (!((final_string[i] >= 'a' && final_string[i]<='z') || (final_string[i] >= 'A' && final_string[i]<='Z'))) {
    final_string[i] = ' ';
  }
}
std::transform(final_string.begin(), final_string.end(), final_string.begin(), ::tolower);
for(int i = 0; final_string [i] != '\0'; i++) {
  flag=0;
  size++;
  if (final_string [i] == ' ')
  {
    std::string str(final_string.substr(start,size));
    std::string string_trimmer = trim(str);
    for(int k=0;k<j;k++) {
      if(string_trimmer.compare(w[k])==0) {
        count[k]=count[k]+1;
        flag=1;
        size=0;
        start=i+1;
        break;
      }
    }
    if(flag==0) {
      if(final_string.substr(start,size).compare(" ")==0)
      {
      }
      else
      {
        w[j]=string_trimmer;
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
  for(int k=i+1;k<j;k++)
  {
    if(count[i]<count[k]) {
      int current_string;
      current_string=count[i];
      count[i]=count[k];
      count[k]=current_string;
      string temp;
      temp=w[i];
      w[i]=w[k];
      w[k]=temp;
    }
  }
}
for(int i=0;i<j;i++) {
  cout<<w[i + 1]<<" "<<count[i + 1]<<endl;
}
return 0;
}
