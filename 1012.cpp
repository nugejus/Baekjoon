#include <iostream>
bool map[100][100] = {};
void print(int M, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            std::cout << map[i][j];
        std::cout << "\n";
    }
}
void find(int x, int y)
{
    if (map[x][y] == false)
        return;
    else
    {
        map[x][y] = false;
        find(x + 1, y);
        find(x, y + 1);
        if(x>0)find(x-1,y);
        if(y>0)find(x,y-1);
    }
    return;
}
int main()
{
    int T, M, N, K, x, y;
    int H = 0;
    std::cin >> T;
    while (T)
    {
        H = 0;
        std::cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            std::cin >> x >> y;
            map[y][x] = true;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] == true)
                {
                    H++;
                    find(i, j);
                }
            }
        }
        std::cout << H << "\n";
        T--;
    }
}
