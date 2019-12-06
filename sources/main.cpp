//Copyright 2019 CrazyOverdose
#include <string>
#include <iostream>
#include "analysis.hpp"

//using namespace std;

int main(){
analysis example("/home/absinthetoxin/CrazyOverdose/lab04_boost_filesystem/misc/ftp");
example.work("/home/absinthetoxin/CrazyOverdose/lab04_boost_filesystem/misc/ftp");
example.print_name_files();
example.print_information();
}
