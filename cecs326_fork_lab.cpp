#include<iostream>
#include<cstdio>
#include<fstream>
#include<stdio.h>
//#include<cstd.lib>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

// void replace(string& target, string& replacement);
string readFile(ifstream& is);
int replace(string& fileContent, const string& target, const string& replacement);

int main()
{
    string target, replacement;
    bool stay = true;

    while(stay){
    cout << "Please enter a string to replace: ";
    cin >> target;

    if(target == "!wq"){ //check input for exit keyword
        stay = false;
        break;
    }

    cout << "Replace with: ";
    cin >> replacement;

    pid_t pid = fork();

    if(pid == -1){
        perror("fork");
    }

    if(pid == 0){ //child process
        cout << "Child Process" << endl;
        cout << "Target: " << target << endl;
        cout << "Replacement: " << replacement << endl;
        int count = 0;

        ifstream read_file("articleTester.txt");
        ofstream write_file("articleTester.txt");

        //replace(target, replacement); //old replace function
        String fileContent = readFile(read_file);
        count = replace(fileContent, target, replacement);

        cout << "Count: " << count << endl;
        //exit();//end of child process
        break;
    }

    if(pid > 0 ){ //parent process
        cout << "Parent Process" << endl;
        if(wait(0) == -1){
            perror("wait");
        }

    }

    } //end of while loop

    cout << "" << endl;

}//end of main


string readFile(ifstream& inputStream){
  string content;
  for(char ch; inputStream.get(ch); content.push_back(ch)){}
  return content;
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




// void replace(string& target, string& replacement){
//     ifstream read_article;
//     read_article.open("articleTester.txt");
//
//     ofstream write_article;
//     write_article.open("articleTester.txt");
//     //article.open("article.txt", ios::out | ios::in);
//
//     if(!read_article.is_open()){
//         cout << "article was not opened" << endl;
//         return;
//     }
//
//     string line;
//
//     while(getline(read_article,line)){//read the file line by line
//       size_t pos = line.find(target); //find position of first occurence of word
//
//       if (pos != std::string::npos){
//         line.replace(pos, target.length(), replacement); //replace word
//       }
//
//       write_article << line << '\n';
//     }
//
//     write_article.close();
//     read_article.close();
//     // while(article >> word){
//     //     if(word == target){
//     //
//     //     }
//     // }
// }
