//#include "assignment1.cpp"
#include "assignment1.h"



int main(int argc, char **argv){
             std::vector <MKXTSH013::TagStruct> tagvector;

             std::string menu;
             std::cout <<"_______Enter an option (r,p,d,l) or q to quit, and press return...   ________"<<std::endl;
             std::cout <<"'r’(read and parse a specified input file)"<<std::endl;
             std::cout <<"‘p’(print all tags - this will list all the tags in arbitrary order, to cout)"<<std::endl;
             std::cout <<"‘d’(dump/write tags and data to a file called tag.txt)"<<std::endl;
             std::cout <<"‘l’(list/print tag data for given tag to cout)"<<std::endl;
             std::cout <<"‘q’(quit - terminate the input loop and exit the program)"<<std::endl;
             std::cin >> menu;

             while(true){
                  if(menu == "r"){

                   std::string filename;
                   std::cout << "Enter file name and press return..." << std::endl;
                   std::cin >> filename;
                                                  // MKXTSH013::readFile(filename);
                   std::string f = MKXTSH013::readFile(filename);
                   tagvector = MKXTSH013::processText(f);

                  }
                  else if(menu == "p"){

                    MKXTSH013::printTags(tagvector);

                  }
                  else if(menu == "d"){
                    MKXTSH013::write2file(tagvector);

                  }
                  else if(menu == "l"){
                      std::string tagname;
                      std::cout << "Enter tag name and press return..." << std::endl;
                      std::cin >> tagname;
                      MKXTSH013::printText(tagname,tagvector);

                  }
                  else if (menu == "q"){break;}
                  else{std::cout << "invalid input" << std::endl;}
                      std::cout <<"_______Enter an option (r,p,d,l) or q to quit, and press return...   ________"<<std::endl;
                      std::cout <<"'r’(read and parse a specified input file)"<<std::endl;
                      std::cout <<"‘p’(print all tags - this will list all the tags in arbitrary order, to cout)"<<std::endl;
                      std::cout <<"‘d’(dump/write tags and data to a file called tag.txt)"<<std::endl;
                      std::cout <<"‘l’(list/print tag data for given tag to cout)"<<std::endl;
                      std::cout <<"‘q’(quit - terminate the input loop and exit the program)"<<std::endl;
                      std::cin >> menu;

             }

            /* std::string filename;
             std::string tagname;
             std::cout << "Enter file name and press return..." << std::endl;
             std::cin >> filename;
            // MKXTSH013::readFile(filename);
             std::string f = MKXTSH013::readFile(filename);
             tagsvecor = MKXTSH013::processText(f);
             std::cout << "Enter tag name and press return..." << std::endl;
             std::cin >> tagname;
             MKXTSH013::printText(tagname);
             */


return 0;

}



