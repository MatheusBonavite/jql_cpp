#include "./definitions/classes/jql_cpp.cpp"
#include "./definitions/classes/arg_control.cpp"

enum class Command_Options
{
    PRINT_COMMAND,
    ATTRIBUTES_COMMAND,
    NONE
};

Command_Options command_interpreter(const char *command)
{
    std::vector<char> print_command = {'p', 'r', 'i', 'n', 't', '\0'};
    std::vector<char> attributes_command = {'a', 't', 't', 'r', 'i', 'b', 'u', 't', 'e', 's', '\0'};
    int counter = 0, print_command_counter = 5, attributes_command_counter = 10;
    for (char i; i != '\0';)
    {
        i = command[counter];

        if (counter < print_command.size() && i == print_command[counter])
            print_command_counter--;
        if (counter < attributes_command.size() && i == attributes_command[counter])
            attributes_command_counter--;
        counter++;
    }
    if (print_command_counter <= 0)
        return Command_Options::PRINT_COMMAND;
    if (attributes_command_counter <= 0)
        return Command_Options::ATTRIBUTES_COMMAND;
    return Command_Options::NONE;
}

void command_switcher(Jql_Cpp jql, Command_Options option)
{
    switch (option)
    {
    case Command_Options::PRINT_COMMAND:
        jql.print_jql_string();
        return;
    case Command_Options::ATTRIBUTES_COMMAND:
        jql.get_attribute_names();
        return;
    default:
        std::cout << "No command given" << std::endl;
        return;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Not enough inputs given \n";
        return 1;
    }

    Arg_Control command(argv[1]);
    Arg_Control file_name(argv[2]);
    Jql_Cpp jql(file_name.get());

    command_switcher(
        jql,
        command_interpreter(argv[1]));
    return 0;
}