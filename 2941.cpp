#include<iostream>
int main()
{
    char x;
    int c=0;
    while((x=getchar())!='\n')
    {
        label:
        if(x=='c')
        {
            x=getchar();
            if(x=='\n'){c++;break;}
            else if(x=='='||x=='-'){c++;continue;}
            else{c++;goto label;}
        }
        else if(x=='s'||x=='z')
        {
            x=getchar();
            if(x=='\n'){c++;break;}
            else if(x=='='){c++;continue;}
            else{c++;goto label;}
        }
        else if(x=='d')
        {
            x=getchar();
            if(x=='\n'){c++;break;}
            else if(x=='z')
            {
                x=getchar();
                if(x=='\n'){c+=2;break;}
                else if(x=='='){c++;continue;}
                else {c+=2;goto label;}
            }
            else if(x=='-'){c++;continue;}
            else{c++;goto label;}
        }
        else if(x=='l')
        {
            x=getchar();
            if(x=='\n'){c++;break;}
            else if(x=='j'){c++;continue;}
            else {c++;goto label;}
        }
        else if(x=='n')
        {
            x=getchar();
            if(x=='\n'){c++;break;}
            else if(x=='j'){c++;continue;}
            else {c++;goto label;}
        }
        else c++;
    }
    std::cout<<c;
}
