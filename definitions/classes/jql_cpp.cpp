#include "../../declarations/classes/jql_cpp.h"
bool check_char_number(const char &val)
{
    return (bool)(int(val) >= 48 && int(val) <= 57);
}

bool check_char_letter(const char &val)
{
    return (bool)((int(val) >= 65 && int(val) <= 90) || (int(val) >= 97 && int(val) <= 122));
}

Jql_Cpp::Jql_Cpp(const char *file_name)
{
    char storage_byte;
    std::ifstream read_json(file_name);
    if (!read_json)
        std::cerr << "Error: file could not be opened" << std::endl;

    // Strings are mutable in C++ :)
    while (read_json.get(storage_byte))
        this->jql_string += storage_byte;
    read_json.close();
    return;
}

std::string Jql_Cpp::val_clean_up(std::smatch val)
{
    std::string cleaned_up_string;
    std::string from_smatch = val[0];
    for (auto &char_val : from_smatch)
    {
        if (
            char_val == '"' || char_val == ':' ||
            char_val == ',' || char_val == '{' ||
            char_val == '}')
        {
            continue;
        }
        cleaned_up_string += char_val;
    }
    return cleaned_up_string;
}

std::string Jql_Cpp::val_type_check(std::string &val)
{
    std::vector<bool> type{false, false, false}; //{ string, number, object }
    for (auto &char_val : val)
    {
        if (char_val == ' ' || char_val == '\n' || char_val == '{' || char_val == '}')
        {
            type[2] = true;
            continue;
        }
        if (check_char_number(char_val))
        {
            type[1] = true;
            continue;
        }
        if (check_char_letter(char_val))
        {
            type[0] = true;
            continue;
        }
    }
    if (type[0])
        return "string";
    if (type[1])
        return "number";
    if (type[2])
        return "object";
    return "undefined";
}

void Jql_Cpp::print_jql_string()
{
    std::cout << this->jql_string << std::endl;
}

void Jql_Cpp::print_jql_arguments()
{
    int line_number = 0;
    std::regex argument_pattern{R"(.*:)"};
    std::regex attribute_pattern{R"(:.*)"};

    std::sregex_iterator arg_it(this->jql_string.begin(), this->jql_string.end(), argument_pattern);
    std::sregex_iterator att_it(this->jql_string.begin(), this->jql_string.end(), attribute_pattern);

    for (; arg_it != std::sregex_iterator{} && att_it != std::sregex_iterator{}; ++arg_it, ++att_it)
    {
        std::string match_att = (*att_it)[0];
        std::cout << val_clean_up(*arg_it) << " " << val_type_check(match_att) << std::endl;
    }
}