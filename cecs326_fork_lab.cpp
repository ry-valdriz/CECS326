#include<iostream>
#include<cstdio>
#include<fstream>
#include<stdio.h>
//#include<cstd.lib>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

void replace(string target, string replacement);

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
        /**
         * Enter replacement algorithm
         *
         **/

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

    cout << "BYE BYE!!!" << endl;

}//end of main


void replace(string target, string replacement){
    std::ifstream read_article;
    read_article.open("article.txt");

    std::ofstream write_article;
    write_article.open("article.txt");
    //article.open("article.txt", ios::out | ios::in);

    if(!read_article.is_open()){
        cout << "article was not opened" << endl;
        return;
    }

    string line;

    while(getline(read_article,line)){
      size_t pos = line.find(target);
      if (pos != std::string::npos){
        line.replace(pos, target.length(), replacement);
      }
    }

    // while(article >> word){
    //     if(word == target){
    //
    //     }
    // }


}
