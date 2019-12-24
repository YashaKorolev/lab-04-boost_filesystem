// Copyright 2019 yasha
//#define PATH "/home/yasha/YashaKorolev/rrr/lab-04-boost_filesystem/misc/ftp"
#include <string>
#include <iostream>
#include "../include/Analys.h"

//std::string PATH= "/home/yasha/YashaKorolev/rrr/lab-04-boost_filesystem/misc/ftp";

int main(/*int argc, char *argv[]*/){

//    std::string PATH;
//    if (argc < 2)
//        PATH = "../";
//    else
//        PATH = std::string(argv[1]);

    Analys example("misc/ftp");
    //Analys example(PATH);
    example.work("misc/ftp");
    //example.work(PATH);
    example.print_name_files();
    example.print_information();
}