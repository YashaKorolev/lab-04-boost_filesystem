//Copyright 2019 CrazyOverdose
#include <string>
#include <iostream>
#include "analysis.hpp"

int main(){
std::string a = "/home/absinthetoxin/CrazyOverdose/lab-04-boost-filesystem/misc/ftp";
analysis example(a);
example.work(a);
example.print_name_files();
example.print_information();
}
