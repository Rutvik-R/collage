from math import pi
'''
# Q-1
vowels = ['a' , 'e' , 'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U']
s = str(input("Enter a string : "))
ans = 0 
for i in vowels :
    ans += s.count(i)

print("ans is " , ans)
'''

'''# Q-2
num = int(input("Enter No : "))
ans = 0
while num :
    ans *= 10
    ans += num%10
    num = num//10

print("Ans is" , ans)
'''
'''
#Q-3
num = int(input("Enter No : "))
ans = 0
while num :
    ans += 1
    num = num//10

print("Ans is" , ans)
'''

'''
#Q-4
def fac(i) :
    if(i<=1):
        return 1
    return  i*fac(i-1)

num = int(input())
ans = 1
ans1 = 1

ans1 = fac(num)
while num :
    ans *= num
    num -= 1
print("ans with recursion" , ans1)
print("ans without recursion" , ans)
'''

'''
#Q-5
def pow(x , i):
    if i<0 :
        x = 1/x
        return pow(x , -i)
    elif i==0:
        return 1
    elif i==1:
        return x
    else :
        return x*pow(x , i-1)
x , i = map(int , input().split())
print("ans is"  , pow(x,i))
'''

'''
#Q-6
def f(i):
    if(i==0):
        return 0
    return 1/i + f(i-1)

num = int(input())
print("ans is" , f(num))
'''

'''
#Q-7
num = list(map(int , input().split()))
n = int(input())
if n in num :
    print("Present")
else :
    print("Absent")
'''


'''
#Q-8
def max(i , j ,k):
    if(i<j and k<j):
        return j
    elif i<k:
        return k
    return i

i , j, k = map(int ,input().split())
print("Ans is " , max(i,j,k))
'''

'''
#Q-9
def a(r):
    return r*r*pi

r = int(input())
print("Area is " , a(r))
'''

'''
#Q-10
def f():
    num = int(input())
    if num<3 :
        return 0
    elif num<12 :
        return 10
    return  15

n = int(input())

for i in range(n):
    print("Cost is $" , f() )
'''

'''
#Q-11
def make_album():
    artist_name , album = input().split()
    return { artist_name : album}

dic = {}
n = int(input())
while n :
    dic.update(make_album())
    n = n -1 
print(dic)
'''

'''
#Q-12
def show_magicians(ll):
    for i in ll:
        print(i)


ll = ["Johannes Sebastian Bach" , "The Rolling Stones" , "Xian Xinghai" , "Notorious B.I.G." , "Caetano Veloso"]
show_magicians(ll)
'''