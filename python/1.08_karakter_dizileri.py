
metin = "karakter dizileri ..."
metin2 = "123456789"
print (metin)
print (metin[0]) #karakter dizisinde istedigimiz kismi alinir
print (metin[2:4]) #karakter dizilerini dilimleme
print (metin[:4]) #0 indisinden baslayip 3 indise kadar olan kisim
print (metin[4:]) #4 indisten baslayip son indise kadar gider
print (metin[4:-4]) #4 indisten baslayip sondan 4 indise kadar

#karakter dizilerini ters cevrime
#[baslangic,son,atlama_sayisi] son yere - konulursa  tersten baslar
print (metin[::-1])
# tersten yazma isleminii reversed ile yapilabilir
print (reversed (metin))

#karakter dizilerini alfabetik siraya gore dizmek
print (sorted(metin))
