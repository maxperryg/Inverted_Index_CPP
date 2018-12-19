//
//  main.cpp
//  Inverted_Index_CPP
//
//  Created by Maxwell Perry Grossman on 12/19/18.
//  Copyright © 2018 Maxwell Perry Grossman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
using namespace std;

void addWordToMap(string word, map<string,pair<int,list<pair<int,int>>>> &invertedIndex, int lineNumber, int lineIndex){
    for_each(word.begin(), word.end(), [](char & c){
        c = ::tolower(c);
    });
    if(invertedIndex.find(word) == invertedIndex.end()){
        list<pair<int,int>> locations;
        locations.push_back({lineNumber,lineIndex});
        invertedIndex.insert({word,{1,locations}});
    }
    else{
        invertedIndex.at(word).first++;
        invertedIndex.at(word).second.push_back({lineNumber,lineIndex});
    }
}
void scanLine(string line, map<string,pair<int,list<pair<int,int>>>> &invertedIndex, int lineNumber){
    string word;
    int i = 0;
    while(i<line.length()){
        while(line[i] != ' '&& line[i] != ',' && line[i] != '.' && line[i] != '-'){
            word += line[i++];
        }
        addWordToMap(word, invertedIndex, lineNumber, i);
        word="";
        while(line[i] == ' '|| line[i] == ',' || line[i] == '.' || line[i] == '-'){
            i++;
        }
    }
}
string listToString(list<pair<int,int>> listOfPairs){
    stringstream ans;
    ans<<"[ ";
    for(auto it = listOfPairs.begin(); it != listOfPairs.end(); ++it)
        ans <<"("<<it->first<<","<<it->second<<") ";
    ans <<" ]";
    
    return ans.str();
}

int main(){
    string line;
    map<string,pair<int,list<pair<int,int>>>> invertedIndex;
    ifstream inputFile;
    inputFile.open("//Users/MaxGrossman/Documents/C++WorkSpace/Inverted_Index_CPP/Inverted_Index_CPP/Gettysburg Address.txt");
    
    int lineNumber=1;
    while(getline(inputFile,line)){
        scanLine(line, invertedIndex, lineNumber++);
    }
    inputFile.close();
    
    for (auto i = invertedIndex.begin(); i != invertedIndex.end(); ++i) {
        cout<<i->first<<" "<<i->second.first<<listToString(i->second.second)<<endl;
    }
    cout << endl;
    return 0;
}
