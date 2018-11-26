#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<cstd.lib>
#include<sys/wait.h>
#include<sys/types.h>

using namespace std;

void replace(string target, string replacement);

int main()
{
    string target, replacement;
    bool stay = true;

    while(stay){
    cout << "Please enter a string to replace: ";
    cin >> target;

    if(target == "!wq"){
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
        int count = 0;
        /**
         * Enter replacement algorithm
         * 
         **/

        cout << "Count: " << count << endl;
        _exit();//end of child process
    } 

    if(pid > 0 ){ //parent process
        if(wait(0) == -1){
            perror("wait");
        }

    }

    } //end of while loop

    cout << "BYE BYE!!!" << endl;

}//end of main


void replace(string target, string replacement){
    ifstream article;
    article.open("article.txt");

    if(!article.is_open()){
        return;
    }

    string word;

    while(article >> word){
        if(word == target)
    }
}