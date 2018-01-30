#include <iostream>
#include <fstream>
#include <ctime>
int main() {
    std::string directory;
    std::ofstream outputFile;
    std::cout<<"enter the file directory:"<<std::endl;
    std::cin>>directory;
    std::cout<<"enter the file name:"<<std::endl;
    std::string fileName;
    std::cin>>fileName;
    directory=directory+"/"+fileName;
    outputFile.open(directory,std::ios::out|std::ios::app|std::ios::in);
    if(!outputFile.is_open()) {
        std::cout<<"open file:"<<directory<<"fail";
        return 0;
    }
    size_t number_size;
    std::cout<<"enter amount"<<std::endl;
    std::cin>>number_size;
    int first_time;
    first_time = (int)time(nullptr);
    size_t line=0;
    for(size_t i=1;i<=number_size;i++){
        srandom((unsigned int)(time(nullptr)+i));
        size_t resent_number;
        resent_number = (size_t)random();
        outputFile<<resent_number<<" ";
        if(i%10==0&&i!=1){
            line++;
            outputFile<<std::endl;
        }
        line++;
    }
    std::cout<<"has"<<line<<"lines"<<std::endl;
    std::cout<<"using "<<time(nullptr)-first_time<<"secs"<<std::endl;
}

/*10 numbers per line*/