#include <string>
#include <iostream>
#include "analysis.hpp"

//using namespace std;

int main () {
string a="/home/absinthetoxin/CrazyOverdose/";
string b = "lab04_boost_filesystem/misc/ftp";
string path_to_ftp = a+b;
analysis example (path_to_ftp);
example.work (path_to_ftp);
example.print_name_files();
example.print_information();
}
