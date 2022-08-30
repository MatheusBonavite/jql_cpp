#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <sstream>

class Jql_Cpp
{
private:
    std::string jql_string;
    std::string val_clean_up(std::smatch val);
    std::string val_type_check(std::string &val);

public:
    Jql_Cpp(const char *file_name);
    void print_jql_string();
    void print_jql_arguments();
};