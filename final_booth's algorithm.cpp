#include <iostream>
#include <math.h>
#define size 5
using namespace std;

int DTB(int binary[], int decimal, int count)
{
    int r, i = 0;
    while (decimal != 0)
    {
        r = decimal % 2;
        decimal = decimal / 2;
        binary[count - i - 1] = r;
        i++;
    }
}

void show(int first[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << first[i];
    }
}

void addBinary(int first[], int second[], int count)
{
    int i, carry = 0;
    for (i = (count - 1); i >= 0; i--)
    {
        int sum = first[i] + second[i] + carry;
        first[i] = sum % 2;
        carry = sum / 2;
    }
}
void complement(int first[], int count)
{
    int one[count];
    for (int i = 0; i < count; i++)
    {
        first[i] = 1 - first[i];
        one[i] = 0;
    }
    one[count - 1] = 1;
    addBinary(first, one, count);
}

void subBinary(int first[], int second[], int count)
{
    complement(second, count);
    addBinary(first, second, count);
}

void shiftright(int A[], int B[], int C[], int count1, int count2)
{
    C[0] = B[count2 - 1];
    int m = A[0];
    for (int i = (count2 - 1); i > 0; i--)
    {
        B[i] = B[i - 1];
    }
    B[0] = A[count1 - 1];
    for (int i = (count1 - 1); i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = m;
}
void BTD(int a1[], int a2[], int count1, int count2)
{
    int sum = 0;
    
    int k = count1 + count2 - 1;
    sum -= (a1[0] * pow(2,k));
    k--;
    for (int j = 1; j < count1; j++)
    {
        sum += (a1[j] * pow(2,k));
        k--;
    }

    for (int i = 0; i < count2; i++)
    {
        sum += (a2[i] * pow(2,k));
        k--;
    }

    cout << "The final answer is : " << sum;
}
int main()
{
    int multiplier, multiplicand, i, count1, count2, num1, num2;
    cout << "Enter Multiplicand :";
    cin >> multiplicand;

    cout << "Enter the Multiplier :";
    cin >> multiplier;

    num1 = abs(multiplicand);
    num2 = abs(multiplier);

    count1 = log(num1) / log(2) + 1;
    count2 = log(num2) / log(2) + 1;

    int A1[count1], A2[count2], M[count1 + 1], Q[count2 + 1], MB[count1 + 1], A[count1 + 1], Q_1[1];
    Q_1[0] = 0;
    DTB(A1, num1, count1);
    DTB(A2, num2, count2);

    // Initializing accumulator
    for (int i = 0; i <= count1; i++)
    {
        A[i] = 0;
    }

    // Converting M and Q in standard format
    M[0] = 0, Q[0] = 0;
    for (i = 1; i <= count1; i++)
    {
        M[i] = A1[i - 1];
    }
    cout << endl;
    for (i = 1; i <= count2; i++)
    {
        Q[i] = A2[i - 1];
    }

    cout << "Binary format of multiplicand is:" << endl;
    if (multiplicand < 0)
    {
        complement(M, count1 + 1);
    }
    show(M, count1 + 1);

    cout << "\nBinary format of multiplier is:" << endl;
    if (multiplier < 0)
    {
        complement(Q, count2 + 1);
    }
    show(Q, count2 + 1);

    // Getting 2's compliment of M
    for (i = 0; i <= count1; i++)
        MB[i] = M[i];
    complement(MB, count1 + 1);
    cout << "\nTwo's compliment of Multiplicand is:" << endl;
    show(MB, count1 + 1);

    cout << "\nInitial value of accumulator is:" << endl;
    show(A, count1 + 1);

    cout << endl;

    cout << "\nFinal Stage" << endl;
    show(M, count1 + 1);
    show(Q, count2 + 1);

    // Booth multiplication
    cout << "\n"
         << "A" << "\t" << "Q" << "\t" << "Q_1" << endl;
    for (i = 0; i <= count2; i++)
    {
        show(A, count1 + 1);
        cout << "\t";
        show(Q, count2 + 1);
        cout << "\t";
        cout << Q_1[0] << endl;
        if (Q[count2] == 1 && Q_1[0] == 0)
        {
            addBinary(A, MB, count1 + 1);
        }
        if (Q[count2] == 0 && Q_1[0] == 1)
        {
            addBinary(A, M, count1 + 1);
        }
        shiftright(A, Q, Q_1, count1 + 1, count2 + 1);
    }
    show(A, count1 + 1);
    cout << "\t";
    show(Q, count2 + 1);
    cout << "\t";
    cout << Q_1[0] << endl;

    BTD(A, Q, count1 + 1, count2 + 1);
}
