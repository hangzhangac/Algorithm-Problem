def gcd(a,b):
	if a%b == 0:
		return b
	else :
		return gcd(b,a%b)
 
a = input()
n , m ,q = a.split(' ')
n = int(n)
m = int(m)
q = int(q);

k=gcd(360*n, 360*m)
lc=360*360*n*m/k;
lc=int(lc)
while q>0:
	q-=1
	s=input()
	t1,v1,t2,v2=s.split(' ')
	t1=int(t1)
	t2=int(t2)
	v1=int(v1)
	v2=int(v2)
	v1=v1-1
	v2=v2-1
	if(t1==t2):
		if(t1==1):
			x=360*m*v1//lc
			y=360*m*v2//lc
			if(x==y):
				print("YES")
			else:
				print("NO")
		else:
			x=360*n*v1//lc
			y=360*n*v2//lc
			if(x==y):
				print("YES")
			else:
				print("NO")
	else:
		if(t1==2):
			x=v1
			v1=v2
			v2=x
			x=360*m*v1;
			y=360*n*v2;
			x//=lc
			y//=lc
			if(x==y):
				print("YES")
			else:
				print("NO")
		else:
			x=360*m*v1;
			y=360*n*v2;
			x//=lc
			y//=lc
			#print(x,y)
			if(x==y):
				print("YES")
			else:
				print("NO")
		
			
	
