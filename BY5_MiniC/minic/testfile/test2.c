int main(void)
{
	int i;   // definition of i
       int sum; /* definition of sum ,
                   the result of operation */
	i = 1; sum = 0;
	while (i <= 100) {
		sum = sum + i;              
		i = i + 1;
	}
       output(sum);
	return 0;
}

