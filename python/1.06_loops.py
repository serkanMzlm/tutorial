b = int(input ("Bir sayi girin : "))
a = 0 
while a < b:
	a+=1
	print ("*"*a)

####################################################

for a in "for":
	print (a)
for b in range(0,20,2): #range (ilk deger,son deger, artis miktari)
	print ("*")

####################################################

#pass  pas gecmek anlaminda 
#break  donguyu sonlandirmak
#continue donguyu basa sarmak
for a in range(15):
	if a == 3:
		print ("a = ",a,"pass calisti")
		pass
	if a ==  8:
		print ("a = ",a,"continue calisti")
		continue 
	if a == 10:
		print ("a = ",a,"break calisti ")
		break
	print ("a = ",a)
print ("islem sonlandirildi...")