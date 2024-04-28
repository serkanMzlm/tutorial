#programci hatalari (error)
#program kusurlari (bug)
#istisnalar (exception)

"""
SyntaxError  =  soz dizimi hatasi

IndexError = bir listenin sinirlari disindaki bir bir dizine erişmeye
calisilirsa olur

ValueError = deger atadigimiz degiskene bir deger atadigimizda olusur.
integer  bir float veya string atamaya calistigimizda

ZeroDivisionError = sıfıra bolme durumunda oluşur.

"""
dosya = open("bolme_sonuc.txt","w")
try : #hatanin olabilecegi kisim
  a = int(input("bolen : "))
  b = int(input("bolunen : "))
  c = str(float(b)/a)
  dosya.write(c)

except ValueError: #olabilecek hata
  print ("Sadece sayi girin ...")

except ZerroDivisionError as hataadi : #bu hata olusunca aciklamasini hataadi  icine attik
  print ("Sifira bolunmez ...")
  print (hataadi)

except : #olusabilecek tum hatalarda 
  print ("hata olustu ...")

finally : #hata olsada olmasada calisacak kisimdir.
  dosya.close()
tr = "ıİüÜöÖçÇşŞğĞ"
ad = input ( "adiniz : ")
for a in ad:
  if a in tr:
    raise TypeError ("Turkce karakter kulandiniz") #raise sayesinde istedigimiz kisimlarda kullanicinin
#girmesini istemddigimiz  hata olarak anlamasini istedigimiz yerlerde kullanilir. Hata adi istenildigi
#gibi verilebilir.
assert len(ad)!=0,"isin bos birakildi" # bir  yandan raisle aynidir sadece biraz daha  toplu sekilde 
# ve daha kisa


