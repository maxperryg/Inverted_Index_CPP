//
//  main.cpp
//  Inverted_Index_CPP
//
//  Created by Maxwell Perry Grossman on 12/19/18.
//  Copyright © 2018 Maxwell Perry Grossman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void addWordToMap(string word, map<string,int> &invertedIndex){
    for_each(word.begin(), word.end(), [](char & c){
        c = ::tolower(c);
    });
    if(invertedIndex.find(word) == invertedIndex.end())
        invertedIndex.insert({word,1});
    else
        invertedIndex.at(word)++;
}

void scanLine(string line, map<string,int> &invertedIndex){
    int counter=0;
    string word;
    for(short i=0;i<line.length();i++){
        while(line[i] == ' '|| line[i] == ',' || line[i] == '.' || line[i] == '-'){
            counter++;
            i++;
        }
        word += line[i];
    }
    
}

int main(){
    string line;
    map<string,int> invertedIndex;
    ifstream inputFile;
    inputFile.open("//Users/MaxGrossman/Documents/C++WorkSpace/Inverted_Index_CPP/Inverted_Index_CPP/Gettysburg Address.txt");

    while(getline(inputFile,line)){
        scanLine(line, invertedIndex);
    }
    inputFile.close();
    
    cout << "\tWord\tFrequency\n";
    for (auto i = invertedIndex.begin(); i != invertedIndex.end(); ++i) {
        cout << '\t' << i->first
        << '\t' << i->second << '\n';
    }
    cout << endl;
    return 0;
}
