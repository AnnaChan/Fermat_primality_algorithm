#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MINNUM 1990000001
#define MAXNUM 2000000000
#define MAXTRIES 10

main()
{
	int i = 0, determ_counter = 0, prob_counter = 0;
	int j =0 ;
	int k =0;
	int start=0;
	long long a;
	double det_sttime, det_endtime, prob_sttime, prob_endtime;
	long curtime;
	
	printf ("Checking range [%d, %d] for primes \n", MINNUM , MAXNUM);
	det_sttime = ((double) clock())/CLOCKS_PER_SEC;   
	for (i=MINNUM; i<=MAXNUM; i++)
	
	{
		int flag = 0;
		int max_divisor = sqrt(i);
		int m = i%2;
		if (m == 0)
		{
			flag = 1;
		}
		else
		{
			j = 3;
		
			while (j<= max_divisor && flag == 0)
			{
				double k;
				k = i%j;
				if (k == 0)
					flag = 1;
				else 
					j = j +2;
			}
		if (flag == 0)
		{
			determ_counter ++;
		}
		
		}
	}
	det_endtime = ((double) clock())/CLOCKS_PER_SEC;
	printf ("Deterministic algorithm: Found %d primes in  %.2f secs \n", determ_counter, det_endtime-det_sttime);
	
	curtime = time(NULL);
	printf("Trying Fermat test with seed %ld \n", curtime);
	srand((unsigned int) curtime);
	if ( MINNUM%2==0)
	{
		start = MINNUM+1;
	}
	else 
	{
		start = MINNUM;
	}
	for (i=1; i<= MAXTRIES; i++ )	
	{	
		prob_counter = 0;
		prob_sttime = ((double) clock())/CLOCKS_PER_SEC; 
		
		for (j=start; j<=MAXNUM; j= j+2)
		{
			k = 1;
			int flag = 0;
			while (k<= i && flag == 0)
			{
					a = (rand() % (j - 1)) + 1;
					long long fermat_result = 1;
					long long base = a%j;
					int exponent = j-1;
					while (exponent>0)
					{
						if (exponent%2==1)
						{
							fermat_result = (fermat_result*base) % j;
						}
						exponent = exponent >> 1;
						base = (base*base )% j;	
					}
					if (fermat_result!=1)
					{
						flag =1;
					}
					else 
					{
						flag = 0;
						k++;
					}
			}				
			if (flag == 0)
			{
				prob_counter ++;
			}
					
		}
		prob_endtime = ((double) clock())/CLOCKS_PER_SEC;
		printf ("Probabilistic algorithm: Found %d primes in  %.2f secs (tries = %d) \n", prob_counter, prob_endtime-prob_sttime, i);	
	}

	
}

