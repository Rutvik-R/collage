sum = 0

for i in range(5):
	a = int(input())		
	sum += a 

sum /= 5

if(sum > 90) :
	print('A')

elif(sum > 80):
	print('B')

elif sum>70:
	print("C")

elif sum>60 :
	print('D')

else:
	print('F')


