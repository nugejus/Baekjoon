#include <iostream>
long long A[50];
long long ccw(int x, int y, int z)
{
    long long n = x * A[y] + y * A[z] + z * A[x] - (y * A[x] + z * A[y] + x * A[z]);
    //std::cout<<n<<" ";
    return n;
}
int func(int x, int N)
{
    int n = 0;
    bool b;
    //std::cout<<"r ";
    for (int i = x + 1; i < N; i++)
    {
        b = true;
        for (int j = x + 1; j < i; j++)
        {
            if (abs(x - i) == 1)
                break;
            if (ccw(x, i, j) >= 0)
            {
                b = false;
                break;
            }
        }
        n += b;
    }
    //std::cout<<" l ";
    for (int i = x - 1; i > -1; i--)
    {
        b = true;
        for (int j = x - 1; j > i; j--)
        {
            if (abs(x - i) == 1)
                break;
            if (ccw(x, i, j) <= 0)
            {
                b = false;
                break;
            }
        }
        n += b;
    }
    //std::cout<<"   =>"<<n;
    return n;
}
int main()
{
    int N, max = 0;

    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        int x;
        x = func(i, N);
        if (x > max)
            max = x;
            //std::cout<<"\n";
    }
    std::cout << max;
}
