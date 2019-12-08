// Copyright 2019 yasha
#include <string>
#include <iostream>
#include "../include/Analys.h"


int main(){
    Analys example("/misc/ftp");
    example.work("/misc/ftp");
    example.print_name_files();
    example.print_information();
}
