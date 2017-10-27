import numpy as np
b=[np.matrix('1 1;1 0')]
for i in range(1000):
	b.append(b[i]*b[i]%29989)
t=int(input())
for i in range(t):
	now=0
	ini=np.matrix('1;0')
	n=int(input())
	while n!=1:
		if(n%2):
			ini=(b[now]*ini)%29989
		now=now+1
		n=int(n/2)
	ini=(b[now]*ini)%29989
	print(int(ini[1][0]))