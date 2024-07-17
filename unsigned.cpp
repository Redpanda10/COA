#include <stdio.h>
#include <conio.h>
#include <math.h>
#define size1 4
#define size2 4
int c=0;
int addBinary(int first[],int second[],int size){
				int i,carry=0;
			for (i = (size - 1); i >= 0; i--)
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
			c=carry;
}
int logicalRightShift(int A1[],int B[]){
	int i;
	printf("Called");
	for(i=(size1+size2-1);i>0;i--){
		if(i>4){
			B[i-size2]=B[i-size2-1];
		}
		else if(i==size2){
			B[0]=A1[size1-1];
		}
		else {
			A1[i]=A1[i-1];
		}
		
	}
		A1[0]=c;
		c=0;
}
	int show(int first[]){
	int i;
		for (i = 0; i < 4 ;i++)
	{
		printf("%d", first[i]);
	}
}	
int main(){
int number, number2,multiplier,multiplicand,i,j=0,r,r2,rnumber[4],rnumber2[4],bnumber[4],bnumber2[4];
	printf("Enter Multiplicand:");
	scanf("%d",&number2);
	printf("Enter Multiplier:");
	scanf("%d",&number);
	int result[size1+size2];
	multiplier = abs(number);
	 multiplicand = abs(number2);
	 for ( i = 0; i < 4; i++)
    { 
	r = multiplier % 2;
        multiplier = multiplier / 2;
        rnumber[i] = r;
        	r2 = multiplicand % 2;
        multiplicand = multiplicand / 2;
        rnumber2[i] = r2;
        if (r == 0)
        {
            rnumber[i] = 0;
        }  
        if (r2 == 0)
        {
            rnumber2[i] = 0;
        }  
	}  
    for(i =3; i >= 0; i--)  
    {  
        bnumber[j] = rnumber[i]; 
		bnumber2[j] = rnumber2[i];  
        j++;  
    }  
    	show(bnumber);
	printf("\t");
	show(bnumber2);
	printf("\t");
	int M[size1] = {};
	int Q[size2] = {};
	int A[size2] = {0, 0, 0, 0};
	int count;
		for (i = 0; i < size1; i++)
	{
		M[i] = bnumber2[i];
	}
	for (i = 0; i < size2; i++)
	{
		Q[i] = bnumber[i];
	}
		show(M);
	printf("\n");
	show(Q);
	printf("\n");
	for (count = size2; count > 0; count--)
	{
		if (Q[size2-1] == 1)
		{
			addBinary(A,M,4);
				printf("add\n");
				printf("%d",c);
					printf("\t");
				show(A);
	printf("\t");
	show(Q);
	printf("\n");
		}
		logicalRightShift(A,Q);
			printf("lRS\n");
	printf("%d",c);
		printf("\t");
				show(A);
	printf("\t");
	show(Q);
	printf("\n");
	}
	printf("Answer (%d * %d ) = ",number2,number);
	show(A);
	show(Q);
	j=0;
	for(i=0;i<size1+size2;i++){
		if(i<4){
		result[i]=A[i];
	}
	else{
		result[i]=Q[j];
		j++;
	}
	}
		 int decimal_value = 0;
    for (i = 0; i < size1+size2; i++) {
        decimal_value += result[i] * pow(2, size1+size2 - 1 - i);
    }
	printf("\nFinal result in Decimal:\n");
	printf("Multiplicand: %d\n",number2);
	printf("Multiplier: %d\n",number);
	printf("Product:%d",decimal_value);
}
