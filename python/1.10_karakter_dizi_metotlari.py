metin = "merhaba dunya,HELLO WORLD"

print (metin)
print (metin.replace("m","M")) # karakter dizilerinde degiştirme islemi yada yerine koyma işlemi icin kullanılır.
# replace ( eski karakter, yeni karakter , kac tanesi )

print (metin.split()) #karakter dizilerini bolme işleminde kullanılır. parametre verilerek  ayırma yerleri belirtilebilir.
print (metin.rsplit(",")) #split tek farki sondan bölmeye başlar
print (metin.splitlines()) ##satir satir ayrilmasini saglar

print (metin.upper()) #bütün karakterli buyuk harf yapar
print (metin.lower()) #bütün karakterleri kucuk harf yapar
#casefold lowerla aynı tek farkı bazı almanca kelimeleri de kucultebilmesidir.

if metin.isupper(): #metinde buyuk harf var mı onu kontrol eder
  print ("metinde buyuk harf var")
elif metin.islower() : #metinde kucuk harf var mı onu kontrol eder
  print ("metinde kucuk harf var")
if metin.endswith("d"): #karakter dizisinin ne ile bittigini  sorgular
  print ("son harf d") 
if metin.startswith("m"): #baslangic harfi sorgular 
  print ("ilk harf m")
print ("1.",metin.capitalize()) # ilk kelimenin büyütür geri kalan tüm kelimeleri kucultur
print ("2.",metin.title()) #her kelimenin ilk harfini buyutur
print ("3.",metin.swapcase()) #buyuk harfleri kucuk kucuklerı buyuk yapar

print (metin.strip("m")) #karakter dizilerinin sagından ve solundan silme yapar
#lstrip sol taraf
#rstrip sağ taraf
metin2 = " ".join(metin) #her karakter arasina belirtileni koyar
print (metin2)
print (metin.count("a")) #belli bir karakterin dizide kaç kez gectigi
print (metin.index("a")) #karakter dizilerinde yerii bildirir
#index (aranacak, başlangıçi , son sira)
print (metin.rindex("a")) #karakter dizilerinde sondan başlar armaya
#find ve rfind index le aynidir tek farki bulamazsa -1 degeri dondurur
print (metin.center(40)) # ortalama anlaya yarar.
print (metin.rjust(40)) # sağa hizalama
print (metin.ljust(40,"-")) #sola hizalama ikinci parametre boş olan yerleri ne ile doldurulmasi gerektigi
print (metin.zfill(10)) #sol tarafına istenilen kadar sifir ekleme
print (metin.partition("du")) #istenilen parametreye göre boler
#encode ile istedigimiz kodlama sekline göre yapabiliriz
#expandtabs  tab bosluklarını genisletebiiriz
kaynak = "şŞıİçÇüÜöÖğĞ"
hedef = "sSiIcCuUoOgG"
cevir = str.maketrans(kaynak,hedef) #bu karakterler gelirse yer degismelrini saglar
ad = input ("adinizi girin : ")
print (ad.translate(cevir))

if metin.isalpha(): #sadece harf
	print ("sadece harf")
if metin.isdigit(): #sadece sayi
	print ("sadece sayi")
if metin.isdecimal (): #ondalikli sayi
	print ("sadece ondalikli sayi")
if metin.isalnum(): #alfanümerik hem sayi hem harf
	print ("hem sayi hem harf")
print ("print".isidentifier())  #degisken adi olrak kulanabilirmiyiz onu sorgular
print ("12".isnumeric()) #sayi olup olmadigini kontrol
print ("              ".isspace()) #tamammen bosluktan oluşup oluşmadıgına bakar
