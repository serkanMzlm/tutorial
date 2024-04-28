"""
-Dosyanın nereye cikmasini istiyorsak yolu  dosyadan once yazariz
- r = read
- w = write
- a = w ile ayni farki dosya varsa icindeki veriyi silmez
- x = w ile ayni farki dosya adinda dosya varsa o  hata verir
- r+ = w + r
- w+ = w + r
- a+ = w + r
- _b = sona b konulursa binary sistemler icin
"""
ad = input ("ad : ")
soyad = input("soyad : ")


dosya = open("deneme.txt","w") #ilk paramatre  dosya adi ikincisi kip yazma yetkisi dosya acma
dosya.write(f"ad : {ad}\nsoyad : {soyad}") #dosyanin icine yazma 
dosya.close() # dosyayi  kapatma


with open("deneme.txt","w+") as dosya : # okuma hem de yazma  modunda acma  "with" otomatik kapatmak icin kullanilir
  print (dosya.read())
#rideline ile satir satir okunur 
#ridelines bize bir liste verir
  print (dosya.readable()) #dosya okuma iznine sahip olup olmadigimiza bakar
  print (dosya.writable()) #dosya yazma izni olup olmadigimizi kontrol eder
  print (dosya.mode) #dosyanın hangı moda acildigi
  print (dosya.name) #dosyanin adi
  dosya.seek(10) # 19 byte gider
  print (dosya.tell()) #kacinci pyte oldugumuzu ogreniriz
  print (dosya.encoding) #hangi dil kodlamasi ile yapildigi gosterir
  veri = dosya.readlines()
  veri.insert(2,"----------------")
  dosya.seek(0)
  for satir in veri :
    dosya.write(satir)
  dosya.truncate(15) # dosyayi kirpma belirtilen kisima  kadari birakip gerisini siler
