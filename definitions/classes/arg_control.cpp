#include "../../declarations/classes/arg_control.h"

Arg_Control::Arg_Control(char *argv) : argv{argv}
{
    int counter = 0;
    for (char i = '0'; i != '\0';)
    {
        i = argv[counter];
        ++counter;
    }
    this->arg_sz = counter;
}

void Arg_Control::print_arg_info()
{
    std::cout << "Argv " << this->argv << " Size: " << this->get_size() << "\n";
}

char *Arg_Control::get()
{
    return this->argv;
}

int Arg_Control::get_size_off()
{ // counting the terminating character '\0'
    return this->arg_sz;
}

int Arg_Control::get_size()
{ // excluding the terminating character '\0'
    return this->arg_sz - 1;
}