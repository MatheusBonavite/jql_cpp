#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Jql_Cpp
{
private:
    std::vector<char> jql_char_arr;
    std::vector<char> jql_char_arr_no_spaces;
    std::string jql_string;

public:
    Jql_Cpp(const char *file_name);
    void print_jql_char_arr();
    void print_jql_string();
    void get_attribute_names();
};