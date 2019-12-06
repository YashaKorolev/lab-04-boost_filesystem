//Copyright 2019 CrazyOverdose
#include <string>
#include <iostream>
#include "analysis.hpp"

//using namespace std;

int main(){
analysis example(".../lab04_boost_filesystem/misc/ftp");
example.work(".../lab04_boost_filesystem/misc/ftp");
example.print_name_files();
example.print_information();
}
