#include "../../declarations/classes/jql_cpp.h"

Jql_Cpp::Jql_Cpp(const char *file_name)
{
    std::ifstream read_json;
    read_json.open(file_name, std::ios::in | std::ios::out);
    if (!read_json)
        std::cout << "Error: file could not be opened" << std::endl;

    char byte;
    while (read_json.get(byte))
    {
        this->jql_char_arr.push_back(byte);
        this->jql_string += byte;
        if (byte != ' ')
            this->jql_char_arr_no_spaces.push_back(byte);
    }
    read_json.close();
    return;
}

void Jql_Cpp::print_jql_char_arr()
{
    for (const auto &byte : this->jql_char_arr)
        std::cout << byte;
    std::cout << "\n";
}

void Jql_Cpp::print_jql_string()
{
    std::cout << this->jql_string << std::endl;
}

void Jql_Cpp::get_attribute_names()
{
    char storage_byte = '\0';
    std::vector<char> attribute;
    int jql_size = this->jql_char_arr_no_spaces.size();

    for (int i = 0; i < jql_size; ++i)
    {
        if (this->jql_char_arr_no_spaces[i] == '"' && storage_byte == '\0')
            storage_byte = '"';
        if (this->jql_char_arr_no_spaces[i] != '"' && storage_byte == '"')
            attribute.push_back(this->jql_char_arr_no_spaces[i]);
        if (this->jql_char_arr_no_spaces[i] == '"' &&
            storage_byte == '"' &&
            i + 1 < jql_size &&
            this->jql_char_arr_no_spaces[i + 1] == ':')
        {
            while (i < jql_size &&
                   this->jql_char_arr_no_spaces[i] != '\n' &&
                   this->jql_char_arr_no_spaces[i] != '\0')
            {
                i++;
            }
            attribute.push_back(' ');
            storage_byte = '\0';
        }
    }

    for (const auto &byte : attribute)
        std::cout << byte;
    std::cout << "\n";
}