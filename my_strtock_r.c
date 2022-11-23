#include "my_strtok_r.h"

size_t my_strlen(const char *s)
{
    const char *st;
    for (st = s; *st; ++st)
    {
        continue;
    }
    return (st - s);
}
size_t my_strspn(const char *s, const char *accept)
{
    size_t cmpt = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        for (int j = 0; accept[j] != 0; j++)
        {
            if (accept[j] == s[i])
            {
                cmpt += 1;
                break;
            }
        }
        if (cmpt != i + 1)
            return cmpt;
    }
    return cmpt;
}
char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if ((*saveptr != NULL) && (*saveptr[0] == '\0'))
        return NULL;
    if (str == NULL)
        str = *saveptr;
    size_t len = my_strlen(str);
    size_t itk = my_strspn(str, delim);
    *saveptr = str + itk;
    str = str + itk;
    char vrai = 1;
    size_t j;
    size_t cmpt = 0;
    for (j = 0; str[j] != 0; j++)
    {
        for (int i = 0; delim[i] != 0; i++)
        {
            if (str[j] == delim[i])
            {
                cmpt += 1;
                vrai = 0;
                break;
            }
        }
        if (vrai == 0)
            break;
    }
    if (cmpt == len)
        return NULL;
    itk = j;
    if (str[0] == 0)
        return NULL;
    if (str[itk] == 0)
    {
        *saveptr = str + itk;
    }
    else
        *saveptr = str + itk + 1;
    str[itk] = 0;
    return str;
}
int main(void)
{
    char str[] = "---a-----b----v-----p---e---";
    char* token;
    char* rest = str;
    token = my_strtok_r(rest,"-", &rest);
    printf("%s\n", token);
    while ((token = my_strtok_r(NULL, "-", &rest)))
        printf("%s\n", token);
    return 0;
}
