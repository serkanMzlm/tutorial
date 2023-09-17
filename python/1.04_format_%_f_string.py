#format  doldurulmasinin sonradan olmasini istedigimiz  yerlere  doldurmamizi saglar
metin = """
*****************
Ad : {}
Soyad : {}
Numara : {}
Serhir : {}
****************
"""
metin2 = """
{1:<20}  sola dayalı 
{1:>20}  saga dayali
{1:^20}  ortada 
{0}
"""
ad = input ("adinizi girin : ")
soyad = input ("soyadinizi girin : ")
numara = input ("numaranizi girin : ")
sehir = input ("sehir girin : ")

print (metin.format(ad,soyad,numara,sehir))
print (metin2.format(ad,soyad))



ad = input ("adiniz : ")
numara = int(input("soyad : "))
print ("ad : %s \nnumara: %i"%(ad,numara))

metin = """
adiniz = %(ad)s 
numraniz = %(numara)i
hosgeldiniz  %(ad)s

"""
print (metin%{"ad" : ad,"numara" : numara})





ad = input("adiniz : ")
soyad = input ("soyadiniz : ")
numara = int(input("numaraniz : "))
print (f"isminiz : {ad}\nsoyad : {soyad}\nnumara : {numara}")
