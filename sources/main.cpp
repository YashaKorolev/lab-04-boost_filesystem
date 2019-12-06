//Copyright 2019 CrazyOverdose
#include <string>
#include <iostream>
#include "analysis.hpp"

int main(){
analysis example("/home/absinthetoxin/lab-04-boost-filesystem/misc/ftp");
example.work("/home/absinthetoxin/lab-04-boost-filesystem/misc/ftp");
example.print_name_files();
example.print_information();
}
