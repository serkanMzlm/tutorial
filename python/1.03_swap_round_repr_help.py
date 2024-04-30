#swap (degiskenlerin degerlerini degistirmesi)

a = b = c = 10 #üç değerede 10 atar

d, e, f = 1, 2, 3 
g, h, *other = [1, 2, 3, 4, 5, 6, 7, 8] # Bu kısımda ilk iki değer sırası ile g ve h ye atanır kalanlar liste olarak other atanır

ilk_deger = 150
iki_deger = 100
print ("ilk deger = ",ilk_deger)
print ("ikinçi deger = ",iki_deger)

ilk_deger,iki_deger = iki_deger,ilk_deger

print ("ilk deger = ",ilk_deger)
print ("ikinçi deger = ",iki_deger)

############################################

#round icinde olan degerin yuvarlanmasini saglar
print ("5.123 yuvarlaniyor...\n",round(5.123,1))
#ilk  deger yuvalanacak sayi ikinci deger virgulden sonra kac hane 


#################################################

#repr bir metnin icinde bulunan kacis satirlarinida gosterir
metin = """
ad : 
soyad : 
il :
adres :
"""
print (metin)
print (repr(metin))


####################################################3

"""
dir () : bize bir nesnenin özelliklerinini 
verir
help () : bir nesne hakkında bilgi almamizi saglar
"""
print (dir(str))
print (help(str))

