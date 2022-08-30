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
    std::string print_command = "print";
    std::string attributes_command = "attributes";

    if (print_command == command)
        return Command_Options::PRINT_COMMAND;
    if (attributes_command == command)
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
        jql.print_jql_arguments();
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
        command_interpreter(command.get()));
    return 0;
}