#include<iostream>
#include<cstdio>
#include<fstream>
#include<stdio.h>
//#include<cstd.lib>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int replace(string& file_content, const string& target, const string& replacement);

int main()
{
  ifstream file_read("articleTester.txt");
  string content, target, replacement;
  int count = 0;

  //for(char ch; inputStream.get(ch); content.push_back(ch)){}
  while(!file_read.eof()){
    content.push_back((char)file_read.get());
  }

  cout << "File Content: " << content << endl;
  cout << "Target Word: ";
  cin >> target;
  cout << "Replacement: " ;
  cin >> replacement;

  count = replace(content, target, replacement);

  cout << "Count: " << count << endl;
  cout << "File Content: " << content << endl;

  file_read.close();
  ofstream file_write("articleTester.txt");

  if(!file_write.is_open()){
    cout << "article not opened 2" << endl;
  }

  file_write << content;
  file_write.close();

}



int replace(string& file_content, const string& target, const string& replacement){
  int count = 0; //counter for # of replacements

  auto pos = file_content.find(target);
  while( pos != std::string::npos){
    file_content.replace(pos,target.length(), replacement);
    //search for next replacement
    pos = file_content.find(target, pos);
    //increment for each word you find
    count++;
  }

  return count;
}
