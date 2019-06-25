#include <iostream>

void str_toupper(char *str)
{
    char *ptr;

    ptr = str;
    while (*ptr)
    {
        if (*ptr >= 'a' && *ptr <= 'z')
            std::cout << (char)(*ptr - 32);
        else
            std::cout << *ptr;
        ptr++;
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc > 1)
    {
        i = 1;
        while (argv[i])
        {
            str_toupper(argv[i]);
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}