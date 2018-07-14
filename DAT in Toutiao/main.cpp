//
//  main.cpp
//  DAT in Toutiao
//
//  Created by Eric Handsome on 2018/7/13.
//  Copyright © 2018年 Eric Handsome. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//const number
#define WORDMAXLENGTH 100
#define CHINESELENGTH 3

//global variable
set<string> charSet;
vector<string> wordList;


int inputData(const char *filename){
    FILE* fp = nullptr;
    char tempWord[WORDMAXLENGTH] = "",tempChar[CHINESELENGTH+1];
    string tempWordInString,tempCharInString;
//    cout << filename<<endl;
//    cout << "/Users/eric_lee/Project/DAT-in-Toutiao/DAT in Toutiao/dic1"<<endl;
    if(fp = fopen(filename, "r")){
        cout<<"open file success."<<endl;
    } else{
        cout<<"open file failed"<<endl;
    }
    while(fscanf(fp, "%s", tempWord)!=EOF){
//        cout<<tempWord<<endl;
        tempWordInString = tempWord;
        wordList.push_back(tempWordInString);
        int len = strlen(tempWord);
        for(int i=0; i<len; i+=3){
            strncpy(tempChar, tempWord + i, CHINESELENGTH);
            tempChar[CHINESELENGTH] = '\0';
            tempCharInString = tempChar;
            charSet.insert(tempCharInString);
        }
    }
    return 0;
}

void printCharSet(){
    set<string>::iterator iter=charSet.begin();
    while(iter!=charSet.end()){
        cout<<*iter<<endl;
        ++iter;
    }
}

void printWordList(){
    for(int i=0; i<wordList.size(); i++){
        cout<<wordList[i]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    char *filename= (char*) malloc(100), path[100] = "/Users/eric_lee/Project/DAT-in-Toutiao/DAT in Toutiao/";
    cout<<"Input filename, please"<<endl;
//    cin>>filename;
    filename="dic1";
    filename = strcat(path, filename);
    inputData(path);
    printCharSet();
    printWordList();

    return 0;
}
