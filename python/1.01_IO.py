# print(,sep=' ', end="\n", file="sys.stdout", flush=False) default değeleri
# sep: Virgül ile ayrılan kısımlardan sonra ne yapılacağını ayarlar.
# end: print fonksiyonu bittikten sonra ne yapılacağını ayarlar
# file: Çıktının yerini belirler.
# flush: dosyanın print fonksiyonundan sonra açık kapalı durumunu belirler.

# type: fonksiyonu ile veri tipi öğrenilir
# len: fonksiyonu ile karakterlerde uzunluk ölçülür
# pow: kuvvet almak için kullanılır ya da  ** kullanılabilir.
# del: değişkenin silinmesini sağlar.

cumle = """Python da  tek tirnak, iki tirnak,
uc tirnak icinde kullanilan her sey karakter dizisidir.
Uc tirnak  en onemli farki  tirnagi kapatana kadar alt 
satira gecmeyi ve uzun cümeler yazmada kolaylik saglar ayni 
zamanda yorum satiri olarakda kullanilmasini sağlar.
"""

print (cumle) 
print ("10+15 " + "=", 10+15) # Python print içinde işlem yapılabilir.
print ("-"*30) # Sonda bulunan * işareti karakterin tekrarlanmasını sağlar. 
print (*"print",sep="\n") # Başlangıçta bulunan *  karakter dizisini karakter karakter okunmasını sağlar.
print ("-"*30)
print ("n\n","t\t","a\a","r\r","v\v","b\b","f\f") # Kaçış dizeleri 
print ("-"*30)
print ("\u0076") # ASCII karakter karşılığını gösterir

ad = input("adinizi girin : ") # Kullanıcıdan  veri almak için kullanılır
print ("ad : ",ad)

print ("'A' = ", type('A'), "| 123: ", type(123), "| 12.3: ", type())
print ("tam sayi = ", type(123))
print ("ondalikli = ",type(12.3))
print ("complex = ", type(12+4j))

cumle = "ABC abc ABC"
print (cumle)
print ("uzunluk = ", len(cumle))
del cumle 

print("pow(2,3):", pow(2,3), "| 2**3:", 2**3, "| pow(2,3,5):", pow(2,3,5))