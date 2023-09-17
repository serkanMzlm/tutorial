deger = input("Rakam girin : ")
deger = int(deger)
if deger%2 == 0 and deger<10:
   print ("cift sayi ")
elif deger%2 == 1 and deger <10 :
   print ("tek sayi")
else : 
   print ("hatali giris  ... ")

############################################
ad = input("adinizi girin : ")
if 'a' in ad and 'b' in ad :
	print ("adinizda 'a' ve 'b'  harfleri var.")
elif 'a' in ad or 'b' in ad :
	print ("adinizda 'a' ya da 'b'  harfleri var.")
elif not 's' in ad :
	print ("not")
else :
	print ("else calisti ... ")

################################################

a = 12
b = 12
print ("a = ",a,"\na id = ",id(a)) #bellekte yerini verir
print ("b = ",b,"\nb id = ",id(b)) 
if  a is b : #a  b ye eşit mi 
	print ("ayni alani bulunuyor.")