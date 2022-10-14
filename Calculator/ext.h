#include <math.h>
// Legendre polynomials
int Legendre(int a, int p)
{
    if (a == 1)
        return 1;
    if (p % a == 0)
        return 0;
    if (a % 2 == 0)
        return Legendre(a / 2, p) * pow(-1, (pow(p, 2) - 1) / 8);
    return Legendre(p % a, a) * pow(-1, (a - 1) * (p - 1) / 4);
}
// GCD of two numbers
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    while (y ^= x ^= y ^= x %= y)
        ;
    return x;
}
// LCD of two numbers
int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}
// Euler's totient function
int phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}
// Input Matrix
void input_matrix(float matrix[20][20], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%f", &matrix[i][j]);
}
// Show Matrix
void output_matrix(float matrix[20][20], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%.3f\t", matrix[i][j]);
        printf("\n");
    }
}
// Add Matrix
void add_matrix(float matrix1[20][20], float matrix2[20][20], float matrix3[20][20], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
}
// Subtract Matrix
void sub_matrix(float matrix1[20][20], float matrix2[20][20], float matrix3[20][20], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
}
// Multiplication of two matrices
void multiply_matrix(float matrix1[20][20], float matrix2[20][20], int r1, int c1, int r2, int c2, float result[20][20])
{
    int i, j, k;
    float temp;

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
        {
            temp = 0;
            for (k = 0; k < c1; k++)
                temp += matrix1[i][k] * matrix2[k][j];
            result[i][j] = temp;
        }
}
// Standard Echelon Form
float standard_echelon(float matrix[20][20], int r, int c, int x, int y)
{
    int i, j, k, l, total[20] = {0};
    float times, temp, result = 0, original_matrix[20][20];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            original_matrix[i][j] = matrix[i][j];
    for (i = 0; i < r - 1; i++)
        for (k = i + 1; k < r; k++)
        {
            j = 0;
            while (matrix[i][j] == 0)
                j++;
            if (matrix[i][j] != 0)
            {
                times = matrix[k][j] / matrix[i][j];
                for (j = 0; j < c; j++)
                    matrix[k][j] -= matrix[i][j] * times;
            }
        }
    for (i = 0; i < r; i++)
    {
        j = 0;
        while (matrix[i][j] == 0)
            j++;
        if (matrix[i][j] != 0)
        {
            times = matrix[i][j];
            for (j = 0; j < c; j++)
                matrix[i][j] /= times;
        }
    }
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (matrix[i][j] == 0)
                total[i]++;
            else
                break;
    for (l = r - 1; l > 0; l--)
        for (i = 0; i < l; i++)
            if (total[l] < total[i])
                for (j = 0; j < c; j++)
                {
                    temp = matrix[l][j];
                    matrix[l][j] = matrix[i][j];
                    matrix[i][j] = temp;
                }
    for (i = 0; i < r; i++)
    {
        j = 0;
        while (matrix[i][j] == 0)
            j++;
        if (matrix[i][j] != 0)
            for (k = 0; k < i; k++)
            {
                times = matrix[k][j] / matrix[i][j];
                for (l = 0; l < c; l++)
                    matrix[k][l] -= times * matrix[i][l];
            }
    }
    result = matrix[x][y];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            matrix[i][j] = original_matrix[i][j];
    if (fabs(result) <= 0.0005)
        result = 0;

    return result;
}
// Rank of Matrix
int rank(float matrix[20][20], int r, int c)
{
    float echelon_matrix[20][20];
    int i, j, none_zero = 0, result = 0;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            echelon_matrix[i][j] = standard_echelon(matrix, r, c, i, j);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            if (echelon_matrix[i][j] != 0)
            {
                none_zero = 1;
                break;
            }
        if (none_zero == 1)
            result++;
        none_zero = 0;
    }
    return result;
}
// Show Standard Echelon Form
void show_standard_echelon(float matrix[20][20], int r, int c)
{
    float echelon_matrix[20][20];
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            echelon_matrix[i][j] = standard_echelon(matrix, r, c, i, j);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (fabs(echelon_matrix[i][j]) < 0.0005)
                echelon_matrix[i][j] = fabs(echelon_matrix[i][j]);
            printf("%.3f\t", echelon_matrix[i][j]);
        }
        printf("\n");
    }
}
// det of matrix
float det_matrix(float matrix[][], int n) //输入代表矩阵的二维数组、矩阵阶数，返回矩阵的行列式
{
    float result = 0;

    // 一阶二阶直接计算
    if (n == 1)
        result = matrix[0][0];
    if (n == 2)
        result = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    else
    {
        for (int k = 0; k < n; k++)
        {
            // 为代数余子式申请内存
            float M[sizeof(matrix)];
            // 为代数余子式赋值
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - 1; j++)
                    M[i][j] = matrix[i + 1][j < k ? j : j + 1];

            // 按第一行展开，递归计算行列式，注意元素0则不展开可以加快计算速度
            if (matrix[0][k])
                result += matrix[0][k] * det_matrix(M, n - 1) * (((2 + k) % 2) ? -1 : 1);
        }
    }
    return result;
}