#ifndef assignment1_h
#define assignment1_h
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <iostream>


//Declaring functions
namespace MKXTSH013
{
    struct TagStruct { //tag structure
        std::string tagname;
        int numOftag;
        std::string text;
    };

     extern std::vector<MKXTSH013::TagStruct> v1; //vector of structs
     //METHODS
     void clear();
     std::string readFile(std::string filename);
     std::vector <TagStruct> processText(std::string text);
     void printText(std::string tagname,std::vector<TagStruct> tagvector);
     void printTags(std::vector<TagStruct> tagvector);
     void write2file(std::vector<TagStruct> tagvector);




}
#endif
