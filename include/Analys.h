//
// Created by yasha on 07.12.2019.
//

#ifndef FILES_ANALYS_H
#define FILES_ANALYS_H


#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <iostream>

struct Date {
    int day;
    int month;
    int year;

    Date(int day1, int month1, int year1) : day(day1), month(month1), year(year1) {}
};

struct Information {
    std::string title;
    std::string broker;
    int account;
    Date data;

    Information(
            const std::string &title1,
            const std::string &broker1,
            int account1,
            const Date &data1) : title(title1),
                                broker(broker1),
                                account(account1),
                                data(data1) {}

};

bool lastdate_predicat(Information file1, Information file2) {
    if (file1.data.year < file2.data.year)
        return 1;
    if (file1.data.year > file2.data.year)
        return 0;

    if (file1.data.month < file2.data.month)
        return 1;
    if (file1.data.month > file2.data.month)
        return 0;

    if (file1.data.day < file2.data.day)
        return 1;
    if (file1.data.day > file2.data.day)
        return 0;

    return 0;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    out << date.day << "." << date.month << "." << date.year;
    return out;
}


class Analys {
protected:
    boost::filesystem::path path_to_ftp;
    std::vector<Information> informations;

    std::unordered_map<int, std::vector<Information>> accounts_groups;

public:
    explicit Analys(boost::filesystem::path path) {
        this->path_to_ftp = path;
    }

    void work(boost::filesystem::path path) {
        for (boost::filesystem::directory_entry dir_iter :
                boost::filesystem::directory_iterator{path}) {
            if (boost::filesystem::is_regular_file(dir_iter))
                file(dir_iter);
            if (boost::filesystem::is_directory(dir_iter))
                work(dir_iter);
        }
    }

    void file(boost::filesystem::path path) {
        try {
            Information new_file = parcer(path.filename().string());

            std::string path2 = path.string();

            size_t i = path2.rfind('/');
            path2.erase(i);
            i = path2.rfind('/');

            new_file.broker = path2.substr(i + 1);

            informations.push_back(new_file);
            accounts_groups[new_file.account].push_back(new_file);
        }
        catch (const std::logic_error &) {}
    }


    void print_name_files() {
        std::cout << "Task one " << std::endl;
        for (size_t i = 0; i < informations.size(); ++i) {
            std::cout << informations[i].broker << "  ";
            std::cout << informations[i].title << std::endl;
        }
    }

    void print_information() {
        std::cout << "Task two " << std::endl;

        for (const auto &i : accounts_groups) {
            std::cout << "broker: " << i.second[0].broker << "| ";

            std::cout << "account: " << i.first << "| ";

            std::cout << "files: " << i.second.size() << "| ";

            std::cout << "lastdate_predicat: ";

            std::cout << std::max_element(i.second.begin(), i.second.end(), lastdate_predicat)->data;

            std::cout << " ";

            std::cout << std::endl;
        }
    }

    bool exceptions(std::string file) {
        bool flag = false;

        if ("balance_" == file.substr(0, 8)) {
            if ('_' == file[16]) {
                if (".txt" == file.substr(25)) {
                    if (std::atoi((file.substr(8, 8)).c_str()) != 0) {
                        if (std::atoi((file.substr(17, 8)).c_str()) != 0) {
                            flag = true;
                        }
                    }
                }
            }
        }

        return flag;
    }

    Information parcer(std::string file) {
        if (!exceptions(file))
            throw std::logic_error("");

        file.erase(0, 8);
        int account = std::atoi((file.substr(0, 8)).c_str());


        file.erase(0, 9);
        int year = std::atoi((file.substr(0, 4)).c_str());

        file.erase(0, 4);
        int month = std::atoi((file.substr(0, 2)).c_str());

        file.erase(0, 2);
        int day = std::atoi((file.substr(0, 2)).c_str());

        Date date(day, month, year);

        Information new_file(file, "", account, date);

        return new_file;
    }
};


#endif //FILES_ANALYS_H
