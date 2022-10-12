#include<iostream>
int solution(int n)
{
	int answer = 0;
	while (n)
	{
		answer += n % 10;
		n /= 10;
	}
	return answer;
}
int func(int x)
{
    int a=1;

    for(int i=1;i<x;i++)
    {
        if(i+solution(i)==x) return a;
    }
    a=0;
    return a;
}
int main()
{
    int n;

    for(int i=1;i<10000;i++)
        if(!func(i)) std::cout<<i<<"\n";
}
