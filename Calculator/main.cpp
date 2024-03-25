#include <bits/stdc++.h>
#include "ext.hpp"
using namespace std;
void menu()
{
    cout << "Welcome to the calculator\n";
    cout << "Please select the function you want to use\n";
    cout << "1. GCD of two numbers\n";
    cout << "2. LCM of two numbers\n";
    cout << "3. Legendre\n";
    cout << "4. Euler's totient\n";
    cout << "5. Reverse of mod\n";
    cout << "6. Matrix\n";
    cout << "7. Large number\n";
    cout << "8. Codes\n";
    cout << "9. Error correction codes\n";
    cout << "10. Secret sharing\n";
    cout << "11. Exit\n";
    cout << "Enter a choice:\n";
}
void mat_menu()
{
    cout << "\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Rank and Standard form\n";
    cout << "5. Det of Matrix\n";
    cout << "6. Inverse of Matrix\n";
    cout << "7. Judge if the quadratic form is positive definite\n";
    cout << "Enter a choice:\n";
}
int main()
{
    short choice;
    menu();
    cin >> choice;
    switch (choice)
    {
    case 1:
        int a, b;
        cout << "Enter the two numbers: ";
        cin >> a >> b;
        cout << "The GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
        break;
    case 2:
        int a1, b1;
        cout << "Enter the two numbers: ";
        cin >> a1 >> b1;
        cout << "The LCM of " << a1 << " and " << b1 << " is: " << lcm(a1, b1) << endl;
        break;
    case 3:
        int m, n;
        cout << "Enter the two numbers: ";
        cin >> m >> n;
        cout << "The Legendre of " << m << " and " << n << " is: " << legendre(m, n) << endl;
        break;
    case 4:
        int num;
        cout << "Enter the number: ";
        cin >> num;
        cout << "The Euler's totient of " << num << " is: " << phi(num) << endl;
        break;
    case 5:
    {
        // reverse of mod
        int a, b;
        cout << "Enter the two numbers: ";
        cin >> a >> b;
        cout << "The reverse of mod is: " << mod_reverse(a, b) << endl;
        break;
    }
    case 6:
    {
        short choice1;
        float matrix[20][20] = {0}, matrix1[20][20] = {0}, matrix2[20][20] = {0}, result[20][20] = {0}; // Initializing the matrices
        mat_menu();
        cin >> choice1;
        switch (choice1)
        {
            int r1, c1, r2, c2; // Define the size of the matrix
        case 1:
        {
            cout << "Enter the size of the first matrix and the second matrix: (Format: row column)";
            cin >> r1 >> c1;
            cout << "Enter the elements of the matrix1: \n";
            input_matrix(matrix1, r1, c1);
            cout << "Enter the elements of the matrix2: \n";
            input_matrix(matrix2, r1, c1);
            add_matrix(matrix1, matrix2, result, r1, c1);
            cout << "The result of the addition is: \n";
            output_matrix(result, r1, c1);
        }
        break;
        case 2:
        {
            cout << "Enter the size of the first matrix and the second matrix: (Format: row column)";
            cin >> r1 >> c1;
            cout << "Enter the elements of the matrix1: \n";
            input_matrix(matrix1, r1, c1);
            cout << "Enter the elements of the matrix2: \n";
            input_matrix(matrix2, r1, c1);
            add_matrix(matrix1, matrix2, result, r1, c1);
            cout << "The result of the subtraction is: \n";
            output_matrix(result, r1, c1);
        }
        break;
        case 3:
        {
            cout << "Enter the size of the matrix1 and matrix2: (Format: row column)";
            cin >> r1 >> c1 >> r2 >> c2;
            if (c1 != r2)
            {
                cout << "Can't compute the matrix multiplication\n";
                break;
            }
            cout << "Enter the elements of matrix1: \n";
            input_matrix(matrix1, r1, c1);
            cout << "Enter the elements of matrix2: \n";
            input_matrix(matrix2, r2, c2);
            cout << "The matrix multiplication is: \n";
            multiply_matrix(matrix1, matrix2, r1, c1, r2, c2, result);
            output_matrix(result, r1, c2);
        }
        break;
        case 4:
        {
            cout << "Enter the number of rows and columns: (Format: row column)";
            cin >> r1 >> c1;
            cout << "Enter the elements of the matrix: \n";
            input_matrix(matrix, r1, c1);
            cout << "Rank = " << matRank(matrix, r1, c1) << endl;
            cout << "The standard matrix is: \n";
            show_standard_echelon(matrix, r1, c1);
        }
        break;
        case 5:
        {
            int n;
            cout << "Enter the matrix size: (Format: row number)";
            cin >> n;
            cout << "Enter the elements of the matrix: \n";
            input_matrix(matrix, n, n);
            cout << "The det of the matrix is: %f\n", det_matrix(matrix, n);
        }
        break;
        case 6:
        {
            cout << "Enter the matrix size: (Format: row column)";
            cin >> r1 >> c1;
            cout << "Enter the elements of the matrix: \n";
            input_matrix(matrix, r1, c1);
            cout << "The inverse of the matrix is: \n";
            inverse_matrix(matrix, r1, c1);
        }
        break;
        case 7:
        {
            cout << "Enter the matrix size: (Format: row column)";
            cin >> r1 >> c1;
            cout << "Enter the elements of the matrix: \n";
            input_matrix(matrix, r1, c1);
            if (quadratic_matrix(matrix, r1, c1))
                cout << "The matrix is positive definite\n";
            else
                cout << "The matrix is not positive definite\n";
        }
        break;
        default:
            break;
        }
    }
    break;
    case 7:
    {
        cout << "Please enter a large number: ";
        char data[1000] = {0};
        store_number(data);
    }
    break;
    case 8:
    {
        int num, bit;
        char data[32] = {'\0'};
        cout << "Please enter a number: ";
        cin >> num;
        cout << "8-bit range is -128 to 127, 16-bit range is -32768 to 32767, 32-bit range is -2147483648 to 2147483647\n";
        cout << "Enter bit : ";
        cin >> bit;
        cout << "The binary representation of " << num << " is: ";
        decimal_to_binary(fabs(num), bit, data);
        print_binary(data, bit);
        cout << endl;
        if (num > 0)
        {
            cout << "The true form of " << num << " is: ";
            print_binary(data, bit);
            cout << endl
                 << "The reverse code of " << num << " is: ";
            print_binary(data, bit);
            cout << endl
                 << "The two's complement of " << num << " is: ";
            print_binary(data, bit);
        }
        else
        {
            char result[32] = {0};
            cout << "The true form of " << num << " is: ";
            negative_true(data, result, bit);
            print_binary(result, bit);
            clear_array(result);
            cout << endl
                 << "The reverse code of " << num << " is: ";
            negative_inverse(data, result, bit);
            print_binary(result, bit);
            clear_array(result);
            cout << endl
                 << "The two's complement of " << num << " is: ";
            negative_complement(data, result, bit);
            print_binary(result, bit);
            cout << endl;
        }
    }
    case 9:
    {
        // Odd-even error code calculation
        int data[32] = {0};
        int temp[8] = {0};
        int parity = 0;
        int error = 0;
        cout << "Please enter 32-bit data: ";
        // 16进制数据
        for (int i = 0; i < 8; i++)
            cin >> hex >> temp[i];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                data[i * 4 + j] = temp[i] % 2;
                temp[i] /= 2;
            }
        }
        // 输出二进制数据
        cout << "The binary data is: ";
        for (int i = 0; i < 32; i++)
            cout << data[i];
        cout << "\n";
        // 奇偶校验
        for (int i = 0; i < 32; i++)
        {
            parity += data[i];
        }
        if (parity % 2 == 0)
            data[31] = 0;
        else
            data[31] = 1;
        // 错误检测
        // Generate random error bit position
        srand((unsigned)time(NULL));
        error = rand() % 32;
        data[error] = !data[error];
        // 奇偶校验
        parity = 0;
        for (int i = 0; i < 32; i++)
        {
            parity += data[i];
        }
        if (parity % 2 == 0)
            data[31] = 0;
        else
            data[31] = 1;
        // 错误检测
        if (data[31] == 0)
            cout << "No error\n";
        else
            cout << "Error bit position: " << error << "\n";
        for (int i = 0; i < 32; i++)
            cout << data[i];
        cout << endl;
    }
    case 10:
    {
        int n, low, high, times, pub, priv = 0;
        cout << "Please enter the number of table size: ";
        cin >> n;
        int table[20][20] = {0};
        gx_multipy(table, n);
        cout << "Please enter the number of times: ";
        cin >> times;
        cout << "Please enter the range of prime number: ";
        cin >> low >> high;
        priv = ranint (low, high);
        while((priv%n)==0)
            priv = ranint (low, high);
        pub = gx_pow_n(table, priv, times);
        cout << "The private key is: " << priv << " and the public key is: " << pub << endl;

    }
    default:
        break;
        // pause
        cout << "\nPress any key to continue...";
        getchar();
        getchar();
        return 0;
    }
}