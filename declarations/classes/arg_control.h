#include <iostream>

class Arg_Control
{
private:
    int arg_sz;
    char *argv;

public:
    Arg_Control(char *argv);
    void print_arg_info();
    char *get();
    int get_size_off();
    int get_size();
};