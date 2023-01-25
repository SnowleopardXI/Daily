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
    printf("6. Large number manipulation\n");
    printf("7. Exit\n");
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
    printf("6. Inverse of Matrix\n");
    printf("7. Judge if the quadratic form is positive definite\n");
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
    {
        short choice1;
        float matrix1[20][20] = {0}, matrix2[20][20] = {0}, result[20][20] = {0}; // Initializing the matrices
        mat_menu();
        scanf("%hd", &choice1);
        switch (choice1)
        {
        case 1:
        {
            int c, r; // Define the size of the matrix
            printf("Enter the size of the first matrix and the second matrix: ");
            scanf("%dx%d", &r, &c);
            printf("Enter the elements of the matrix1: \n");
            input_matrix(matrix1, r, c);
            printf("Enter the elements of the matrix2: \n");
            input_matrix(matrix2, r, c);
            add_matrix(matrix1, matrix2, result, r, c);
            printf("The result of the addition is: \n");
            output_matrix(result, r, c);
        }
        break;
        case 2:
        {
            int c, r; // Define the size of the matrix
            printf("Enter the size of the first matrix and the second matrix: ");
            scanf("%dx%d", &r, &c);
            printf("Enter the elements of the matrix1: \n");
            input_matrix(matrix1, r, c);
            printf("Enter the elements of the matrix2: \n");
            input_matrix(matrix2, r, c);
            add_matrix(matrix1, matrix2, result, r, c);
            printf("The result of the subtraction is: \n");
            output_matrix(result, r, c);
        }
        break;
        case 3:
        {
            int r1, c1, r2, c2; // Define the size of the matrix
            printf("Enter the size of the matrix1 and matrix2: ");
            scanf("%dx%d %dx%d", &r1, &c1, &r2, &c2);
            if (c1 != r2)
            {
                printf("Can't compute the matrix multiplication\n");
                break;
            }
            printf("Enter the elements of matrix1: \n");
            input_matrix(matrix1, r1, c1);
            printf("Enter the elements of matrix2: \n");
            input_matrix(matrix2, r2, c2);
            printf("The matrix multiplication is: \n");
            multiply_matrix(matrix1, matrix2, r1, c1, r2, c2, result);
            output_matrix(result, r1, c2);
        }
        break;
        case 4:
        {
            float matrix[20][20] = {0};
            int r, c;
            printf("Enter the number of rows and columns: ");
            scanf("%dx%d", &r, &c);
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
            int n;
            printf("Enter the matrix size: ");
            scanf("%dx%d", &n, &n);
            printf("Enter the elements of the matrix: \n");
            input_matrix(matrix, n, n);
            printf("The det of the matrix is: %f\n", det_matrix(matrix, n));
        }
        break;
        case 6:
        {
            float matrix[20][20] = {0};
            int r, c;
            printf("Enter the matrix size: ");
            scanf("%dx%d", &r, &c);
            printf("Enter the elements of the matrix: \n");
            input_matrix(matrix, r, c);
            printf("The inverse of the matrix is: \n");
            inverse_matrix(matrix, r, c);
        }
        break;
        case 7:
        {
            float matrix[20][20] = {0};
            int r, c;
            printf("Enter the matrix size: ");
            scanf("%dx%d", &r, &c);
            printf("Enter the elements of the matrix: \n");
            input_matrix(matrix, r, c);
            if (quadratic_matrix(matrix, r, c))
                printf("The matrix is positive definite\n");
            else
                printf("The matrix is not positive definite\n");
        }
        break;
        default:
            break;
        }
    }
    break;
    case 6:
    {
        printf("Please enter a large number: ");
        char data[1000]={0};
        store_number(data);
    }
    break;
    default:
        break;
        // pause
        printf("\nPress any key to continue...");
        getchar();
        getchar();
        return 0;
    }
}