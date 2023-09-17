deger = int (input ("deger girin : "))
print ("Binary : ",bin(deger)) #ikili sisteme cevirir
print ("Octal : ",oct(deger)) #sekizli sistem
print ("Desimal : ",deger) #onluk sistem
print ("hexadecimal : ",hex(deger)) #onaltılı sistem

deger2 = int('12A',16) #tam sayiya dondurme
print ("12A = ",deger2)

#format ile kullanma
metin = """
binary = {0:b}
octal = {0:o}
desimal = {0}
hexadecimal = {0:x}
"""
print (metin.format(deger))

print (deger.bit_length()) #kac bit kapladigi 

#kayan sayilar 
deger3 = float(input("ondalikli sayi girin : "))
print (deger3.as_integer_ratio()) # float sayiyi hangi iki  tam sayinin sonucu olur onu gosterir
print (deger3.is_integer()) # . sonrasi sifir mi onu kontrol eder

#karmasik sayilar
sayi = 10+5j
print ("sayi = ",sayi)
print ("Sanal kismi = ",sayi.imag)
print ("Reel kismi = ",sayi.real)
