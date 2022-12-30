#include <iostream>
class points
{
public:
    int p, q, r;
    points(int p_ = -1, int q_ = -1, int r_ = -1)
    {
        p = p_;
        q = q_;
        r = r_;
    }
    void print()
    {
        std::cout << '(' << p << ',' << q << ',' << r << ')' << '\n';
    }
    int get_sum()
    {
        return p + q + r;
    }
};
bool operator==(const points &x, const points &y)
{
    if (x.p == y.p && x.q == y.q && x.r == y.r)
        return true;
    else
        return false;
}
class relate
{
public:
    int i, j;
    relate(int i_ = 0, int j_ = 0)
    {
        i = i_;
        j = j_;
    }
};
int get_last_index(points *list)
{
    for (int i = 0; i < 3001; i++)
        if (list[i].get_sum() < 0)
            return i - 1;
}
void move2(points *list, int last_index, int index)
{
    for (int i = last_index; i > index - 1; i--)
        list[i + 1] = list[i];
}
bool is_same(points *list, points X, int index)
{
    for (int j = 0; j < index + 1; j++)
    {
        if (X == list[j])
            return true;
    }
    return false;
}
int get_index(points *list, points X, int index)
{
    for (int i = 0; i < index + 1; i++)
        if (X == list[i])
            return i;
    return -1;
}
void fit(points *res, points *forN, relate *forM, int M)
{
    points X, Y;
    int index = 0;
    for (int i = 0; i < M; i++)
    {
        X = forN[forM[i].i];
        Y = forN[forM[i].j];
        if (index == 0)
        {
            res[index] = Y;
            res[index + 1] = X;
        }
        else
        {
            if (is_same(res, X, index))
            {
                if (get_index(res, X, index) == 0)
                {
                    move2(res, index, 0);
                    res[0] = Y;
                }
            }
            if (is_same(res, Y, index))
            {
                if (get_index(res, Y, index) == index)
                {
                    res[index + 1] = X;
                }
            }
        }
        index = get_last_index(res);
    }
}
char predict(points *res, points *forN, relate *forM, points x, points y, int Q, int N, int last_index)
{
    int xi = get_index(res, x, last_index);
    int yi = get_index(res, y, last_index);
    if (xi < 0 || yi < 0)
    {
        for (int i = 0; i < N; i++)
        {
            points pxi = forN[forM[i].i];
            points pyi = forN[forM[i].j];
            if (pxi == x && pyi == y)
                return '>';
            else if (pxi == y && pyi == x)
                return '<';
        }
        return '?';
    }
    else
    {
        if (xi < yi)
            return '<';
        else if (xi > yi)
            return '>';
        else
            return '=';
    }
}
int main()
{
    int M, N, Q;
    int last_index;
    points res[3001];
    points forN[3001] = {};
    relate forM[3001], forQ[3001];
    std::cin >> N >> M >> Q;
    for (int i = 0; i < N; i++)
    {
        int p, q, r;
        std::cin >> p >> q >> r;
        forN[i] = points(p, q, r);
    }
    for (int k = 0; k < M; k++)
    {
        int i, j;
        std::cin >> i >> j;
        forM[k] = relate(i - 1, j - 1);
    }
    for (int k = 0; k < Q; k++)
    {
        int i, j;
        std::cin >> i >> j;
        forQ[k] = relate(i - 1, j - 1);
    }
    fit(res, forN, forM, M);
    last_index = get_last_index(res) + 1;
    for (int i = 0; i < Q; i++)
        std::cout << predict(res, forN, forM, forN[forQ[i].i], forN[forQ[i].j], Q, N, last_index) << '\n';
}
