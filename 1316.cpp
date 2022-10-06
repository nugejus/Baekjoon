#include <iostream>
#include <cstring>
void print(char *s)
{
    for(int i=0;i<strlen(s);i++)
    {
        std::cout<<s[i];
    }
    std::cout<<"\n";
}
void clear(char *s)
{
    for(int i=0;i<200;i++)
    {
        s[i]='\0';
    }
}
int main()
{
    bool x = true;
    int N, i = 0, G = 0;
    char c, c1, s[200];

    std::cin >> N;
    getchar();
    while (N)
    {
        i = 0;
        x = true;
        while ((c = getchar()) != '\n')
        {
            if (i == 0)
            {
                s[i] = c;
                c1 = c;
            }
            else
            {
                if (c == c1)
                    continue;
                else
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (s[j] == c)
                            x = false;
                    }
                }
            }
            s[i]=c;
            c1 = c;
            i++;
        }
        //std::cout<<x<<" ";
        //print(s);
        clear(s);
        G += x;
        N--;
    }
    std::cout << G << "\n";
}
