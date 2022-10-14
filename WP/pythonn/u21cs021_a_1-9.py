def f(i):
	if(i<=1 ):
		return 1 

	return i*f(i-1)



print(f(10))