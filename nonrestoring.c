#include <stdio.h>
#include <math.h>
#define size1 5
#define size2 5
int addBinary(int first[],int second[]){
				int carry = 0, i;
			for (i = (size1 - 1); i >= 0; i--)
			{
				if (carry == 0)
				{
					if ((first[i] == 1 && second[i] == 0) || (first[i] == 0 && second[i] == 1))
					{
						first[i] = 1;
						carry = 0;
					}
					else if (first[i] == 1 && second[i] == 1)
					{
						first[i] = 0;
						carry = 1;
					}
					else
					{
						first[i] = 0;
						carry = 0;
					}
				}
				else if (carry == 1)
				{
					if ((first[i] == 1 && second[i] == 0) || (first[i] == 0 && second[i] == 1))
					{
						first[i] = 0;
						carry = 1;
					}
					else if (first[i] == 1 && second[i] == 1)
					{
						first[i] = 1;
						carry = 1;
					}
					else
					{
						first[i] = 1;
						carry = 0;
					}
				}
			}
}
int leftshift(int first[], int second[]){
int i;
for (i = 0; i < (size1 + size2 - 1); i++)
			{
				if (i < (size1 - 1))
				{
					first[i] = first[i + 1];
				}
				else if (i == (size1 - 1))
				{
					first[size1 - 1] = second[0];
				}
				else
				{
					second[i - size1] = second[(i + 1) - (size1)];
				}
			}
		}
	int show(int first[]){
	int i;
		for (i = 0; i < 5 ;i++)
	{
		printf("%d", first[i]);
	}
}	
int main()
{
	int number, number2,checkq=0,checkre=0,ij, r,r2,j=0,i,dividend,divisor;
	printf("Enter dividend:");
	scanf("%d",&number2);
	printf("Enter divisor:");
	scanf("%d",&number);
	if(number2<0){
		checkre=1;
	}
	if((number2*number)<0){
		checkq=1;
	}
	int rnumber[5],bnumber[5],rnumber2[5],bnumber2[5] ,MB[size1]={},One[5]={0,0,0,0,1};
	 divisor = abs(number);
	 dividend = abs(number2);
	 for ( ij = 0; ij < 5; ij++)
    { 
	r = divisor % 2;
        divisor = divisor / 2;
        rnumber[ij] = r;
        	r2 = dividend % 2;
        dividend = dividend / 2;
        rnumber2[ij] = r2;
        if (r == 0)
        {
            rnumber[ij] = 0;
        }  
        if (r2 == 0)
        {
            rnumber2[ij] = 0;
        }  
	}  
    for(ij =4; ij >= 0; ij--)  
    {  
        bnumber[j] = rnumber[ij]; 
		bnumber2[j] = rnumber2[ij];  
        j++;  
    }  
	show(bnumber);
	printf("\t");
	show(bnumber2);
	printf("\t");
		for (ij = 0; ij < 5 ;ij++)
	{
		if(bnumber[ij]==0){
			MB[ij]=1;
		}
		else{
			MB[ij]=0;
		}
	}
	addBinary(MB,One);
	show(MB);
	printf("\n");
	int M[size1] = {};
	int Q[size2] = {};
	int A[size1] = {0, 0, 0, 0, 0};
	int count;

	for (i = 0; i < size1; i++)
	{
		M[i] = bnumber[i];
	}
	for (i = 0; i < size2; i++)
	{
		Q[i] = bnumber2[i];
	}
	show(M);
	printf("\n");
	show(Q);
	printf("\n");
	for (count = size2; count > 0; count--)
	{
		if (A[0] == 0)
		{
			leftshift(A,Q);
			Q[size2 - 1] = 0;
			printf("Left shift:\n");
			show(A);
			printf("\n");
			show(Q);
			printf("\n");
			addBinary(A,MB);
			printf("Ater Add:\n");
			show(A);
			printf("\n");
		}
		else if (A[0] == 1)
		{
			leftshift(A,Q);
			Q[size2 - 1] = 0;
			printf("Left shift:\n");
			show(A);
			printf("\n");
			show(Q);
			printf("\n");
			addBinary(A,M);
			printf("Ater Add:\n");
            show(A);
			printf("\n");
		}
		if (A[0] == 1)
		{
			Q[size2 - 1] = 0;
		}
		else
		{
			Q[size2 - 1] = 1;
		}
		printf("Quotient:\n");
		show(Q);
		printf("\n");
	}
	if (A[0] == 1)
	{ 
	addBinary(A,M);
	}
		 int decimal_value = 0, decimal_value2 =0;
    for (i = 0; i < size1; i++) {
        decimal_value += A[i] * pow(2, size1 - 1 - i);
        decimal_value2 += Q[i] * pow(2, size1 - 1 - i);
    }
	printf("\n\n\n");
    if(checkre==1){
    	printf(" Negative ");
    }
    printf("Remainder:\n");
	show(A);
	printf("\n\n");
    if(checkq==1){
    	printf("Negative ");
    }
	printf("Quotient:\n");
    show(Q);
	printf("\n\n");
	printf("\nFinal result in Decimal:\n");
	printf("Dividend: %d\n",number2);
	printf("Divisor: %d\n",number);
	printf("Remainder:",number);
	if(checkre==1){
    	printf(" -");
    }
    printf("%d\n",decimal_value);
    printf("Quotient:",number);
    if(checkq==1){
    	printf(" -");
    }
    printf("%d\n",decimal_value2);
	
}
