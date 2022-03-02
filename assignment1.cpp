#include "assignment1.h"

namespace MKXTSH013{

   // std::vector<MKXTSH013::TagStruct> tagvector;
    std::vector<std::string> lines;

void clear(){
   // tagvector.clear();
    lines.clear();
}


//This method reads a file that is passed in as an argument. it reads and concatinates the file data into
//a single string
    std::string readFile(std::string filename){
     std::string line;
     std::string s = ""; //add file into string

            //reading in the file
     std::ifstream file(filename);
     if(file.good()){
         while(getline(file, line)){
             s += line;

            }
        file.close();

    }
    else{
        std::cout << "unable to find a file with that name, please ensure file is in Input folder..." << std::endl; // if file not found

    }
    std::cout << s << std::endl;

    return s;

        }

// This method is used to process and parse input data

std::vector <TagStruct> processText(std::string text) {
    std::vector <TagStruct> tagsvecor;
    int position0=0, position1=0, position2 = 0;
    std::string tagname;
    bool found;
    for (;;) { //Loop through entire file searching for tags and data.


        if( text.find('<', position0) == text.find("</", position0)) {
            int temp=text.find(">", text.find('<', position0));
            position0=temp;

            if( text.find('<', position0) == text.find("</", position0)) {
                int temp=text.find(">", text.find('<', position0));
                position0=temp;
            };
        };

        //Mark positions where brackets have been found, extract tags and data
        position0 = text.find('<', position0); //opening bracket
        position1 = text.find('>', position0); //closing bracket

        tagname = text.substr(position0 + 1, position1 - position0 - 1); //find the tag name

        position2 = text.find("</"+tagname+">",position0); //find closing tag

        if(position0==-1 )break; //if no tags found
        if(position2==-1) {position0++; continue;};
        std::string tagtext = text.substr(position1 + 1, position2 - position1-1); //extract tag text

        //adding the extracted data to a vector
        for (int i=0; i<tagsvecor.size(); i++){
            if (tagsvecor[i].tagname==tagname) {
                tagsvecor[i].numOftag++;
                tagsvecor[i].text += ":" + tagtext; // concatiate the text with : is there are multiple texts
                found = true;
                break;
            }
        }
        // If the tag is not found add it
        if(!found){
            TagStruct newstruct;
            newstruct.tagname = tagname;
            newstruct.text = tagtext;
            newstruct.numOftag =1;
            tagsvecor.push_back(newstruct);
            found=false;
        }
        position0=position1;
    }
    return tagsvecor;

}

//Method to print out the texts of associated tags
void printText(std::string tagname,std::vector<TagStruct> tagvector) {
    //std::string s ="";
    if(tagvector.empty()) //when no file has been read there is no data to print
        {
            std::cout <<"No file read. Run 'r' command first to read file."<< std::endl;
        }
    else{

        for(TagStruct a : tagvector){
            if(a.tagname == tagname){

              std::cout<<"\"" << a.tagname << "\", " << a.numOftag << ", \"" << a.text << "\"\n";
              }

}}
            }


//Method to print tags in abitrary

void printTags(std::vector<TagStruct> tagvector){

    for(MKXTSH013::TagStruct vA:tagvector){
            std::cout << vA.tagname << std::endl;
            }

    if(tagvector.empty()){
        std::cout << "No tags found" << std::endl;
    }

}

 // Writes all the data to file file: tag.txt

void write2file(std::vector<TagStruct> tagvector){
        std::ofstream file("tags.txt");
        for(MKXTSH013::TagStruct vA:tagvector){
            file<<"\"" << vA.tagname << "\", " << vA.numOftag << ", \"" << vA.text << "\"\n";
        }
        file.close();
         if(tagvector.empty()){
                std::cout << "Couldn't write to file" << std::endl;
            }
         else{
               std::cout << "Successfully written to file" << std::endl;

         }

}


}










