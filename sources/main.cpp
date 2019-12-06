#include <string>
#include <iostream>
#include "analysis.hpp"

//using namespace std;

int main(){
string path_to_ftp = "/home/absinthetoxin/CrazyOverdose/";
path_to_ftp = path_to_ftp + "lab04_boost_filesystem/misc/ftp";
analysis example(path_to_ftp);
example.work(path_to_ftp);
example.print_name_files();
example.print_information();
}
