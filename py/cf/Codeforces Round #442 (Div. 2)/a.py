friends_names=['Danil','Olya','Slava','Ann','Nikita']
ques=input()
num=0
isok=1
for name in friends_names:
	if (name in ques):
		num+=1
	if (ques.count(name)>1):
		isok=0
if (isok and num==1):
	print('YES')
else:
	print('NO')
