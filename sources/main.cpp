//Copyright 2019 CrazyOverdose
#include <string>
#include <iostream>
#include <Analys.h>
//#include "analysis.hpp"

int main(){
    //
//analysis example("/home/absinthetoxin/lab-04-boost-filesystem/misc/ftp");
    Analys example("/Users/alexandergaranin/Projects/test10/lab-04-boost-filesystem");
//example.work("/home/absinthetoxin/lab-04-boost-filesystem/misc/ftp");
    example.work("/Users/alexandergaranin/Projects/test10/lab-04-boost-filesystem");
example.print_name_files();
example.print_information();
}
