#include <stdio.h>
#include <stdlib.h>
#include "ext.h"
void menu()
{
    printf("\n");
    printf("1. GCD of two numbers\n");
    printf("2. LCM of two numbers\n");
    printf("3. Legendre\n");
    printf("4. Euler's totient\n");
    printf("5. Matrix Manipulation\n");
    printf("6. Exit\n");
    printf("Enter a choice:\n");
}
void mat_menu()
{
    printf("\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Rank and Standard form\n");
    printf("5. Det of Matrix\n");
    printf("Enter a choice:\n");
}
int main()
{
    short choice;
    menu();
    scanf("%hd", &choice);
    switch (choice)
    {
    case 1:
        int a, b;
        printf("Enter the two numbers: ");
        scanf("%d%d", &a, &b);
        printf("The GCD of %d %d is: ", a, b);
        printf("%d", gcd(a, b));
        break;
    case 2:
        int a1, b1;
        printf("Enter the two numbers: ");
        scanf("%d%d", &a1, &b1);
        printf("The LCM of %d %d is: ", a1, b1);
        printf("%d", lcm(a1, b1));
        break;
    case 3:
        int m, n;
        printf("Enter the number of terms: ");
        scanf("%d%d", &m, &n);
        printf("The Legendre symbol is: ");
        printf("%d", Legendre(m, n));
        break;
    case 4:
        int p;
        printf("Enter the number: ");
        scanf("%d", &p);
        printf("The Euler's totient is: %d", phi(p));
        break;
    case 5:
        short choice1;
        float matrix1[20][20] = {0}, matrix2[20][20] = {0}, result[20][20] = {0}; // Initializing the matrices
        mat_menu();
        scanf("%hd", &choice1);
        switch (choice1)
        {
        case 1:
        {
            int e; // Define the size of the matrix
            printf("Enter the size of the first matrix and the second matrix: ");
            scanf("%d", &e);
            printf("Enter the elements of the matrix1: \n");
            input_matrix(matrix1, e, e);
            printf("Enter the elements of the matrix2: \n");
            input_matrix(matrix2, e, e);
            add_matrix(matrix1, matrix2, result, e, e);
            printf("The result of the addition is: \n");
            output_matrix(result, e, e);
        }
        break;
        case 2:
        {
            int e; // Define the size of the matrix
            printf("Enter the size of the first matrix and the second matrix: ");
            scanf("%d", &e);
            printf("Enter the elements of the matrix1: \n");
            input_matrix(matrix1, e, e);
            printf("Enter the elements of the matrix2: \n");
            input_matrix(matrix2, e, e);
            sub_matrix(matrix1, matrix2, result, e, e);
            printf("The result of the addition is: \n");
            output_matrix(result, e, e);
        case 3:
        {
            int e, f, g, h; // Define the size of the matrix
            printf("Enter the size of the matrix1 and matrix2: ");
            scanf("%d%d%d%d", &e, &f, &g, &h);
            if (f != g)
            {
                printf("Can't compute the matrix multiplication\n");
                break;
            }
            printf("Enter the elements of matrix1: \n");
            input_matrix(matrix1, e, f);
            printf("Enter the elements of matrix2: \n");
            input_matrix(matrix2, g, h);
            printf("The matrix multiplication is: \n");
            multiply_matrix(matrix1, matrix2, e, f, g, h, result);
            output_matrix(result, e, h);
        }
        break;
        case 4:
        {
            float matrix[20][20] = {0};
            int i, j, r, c;
            printf("Enter the number of rows and columns: ");
            scanf("%d%d", &r, &c);
            printf("Enter the elements of the matrix: \n");
            input_matrix(matrix, r, c);
            printf("Rank = %d\n", rank(matrix, r, c));
            printf("The standard matrix is: \n");
            show_standard_echelon(matrix, r, c);
        }
        break;
            case 5:
            {
                float matrix[20][20] = {0};
                int i, j, n;
                printf("Enter the matrix size: ");
                scanf("%d", &n);
                printf("Enter the elements of the matrix: \n");
                input_matrix(matrix, n, n);
                printf("The det of the matrix is: %f\n", det_matrix(matrix, n));
            }
            break;
        default:
            break;
        }
            // pause
            printf("\nPress any key to continue...");
            getchar();
            getchar();
            return 0;
        }
    }
}
