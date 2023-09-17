print ("|-2| = ",abs(-2)) #mutlak deger
deger = divmod(10,2) # kalan ve bolumu verir
print ("10 / 2  = ",deger[0],"\nkalan : ",deger[1])

liste = [1,2,3,4,5,6,7,8,9]
kelimeler = ["istanbul","ankara","izmir","mersin","trabzon"]
print (liste)
print ("en buyuk deger : ",max(liste)) # en buyuk deger
print ("en kucuk deger : ",min(liste)) # en kucuk deger
print ("sayi toplamlari : ",sum(liste)) #toplami
print (kelimeler)
print (max(kelimeler,key=len)) #en uzun kelime
