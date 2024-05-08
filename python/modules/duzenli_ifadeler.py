#!/usr/bin/python3
import re

metin = "Bu bir python kodudur."

flag_1 = re.match("bir", metin)       # Karakter dizinin ilk kısı kontrolü yapılır
flag_2 = metin.split()[0] == "bir"    # Düzenli ifade kullanılmadanda bu kontrol yapılabilir.
if flag_1: # Eşleşme olmasa None değer verir bu kısım bu durumda hata olmasını önler
    print(flag_1.group())

flag_3 = re.search("bir", metin)
print(flag_3,  "| Gectigi aralik:", flag_3.span(), "| Kelime:", flag_3.group())

# Bir liste üzerinde işlem yapmak için

liste = ["elma", "tren", "armut", "muz", "elma"]
metin = "elma ev araba armut"
for i in liste:
    nesne = re.search(i, metin)
    if nesne:
        print(nesne.group(), "kelimesi:", nesne.span(), "index degeridir.")
    else:
        print(i, "kelimesi metin icinde bulunamadi")

metin = """Guido Van Rossum Python'ı geliştirmeye 1990 yılında başlamış... Yani
aslında Python için nispeten yeni bir dil denebilir. Ancak Python'un çok uzun
bir geçmişi olmasa da, bu dil öteki dillere kıyasla kolay olması, hızlı olması,
ayrı bir derleyici programa ihtiyaç duymaması ve bunun gibi pek çok nedenden
ötürü çoğu kimsenin gözdesi haline gelmiştir. Ayrıca Google'ın da Python'a özel
bir önem ve değer verdiğini, çok iyi derecede Python bilenlere iş olanağı
sunduğunu da hemen söyleyelim. Mesela bundan kısa bir süre önce Python'ın
yaratıcısı Guido Van Rossum Google'de işe başladı..."""

print(re.findall("Python", metin)) # Belirtilen metinde geçen bütün python kelimelerini bulur.

# Meta karakterler sayesinde arama belirli bir aralık verilmesi daha rahat olur.
# alt kısımda bulunan listede özcan özkan özhan bulmanın kolay yolu [] kullanmaktır.
liste = ["özcan", "mehmet", "süleyman", "selim",
"kemal", "özkan", "esra", "dündar", "esin",
"esma", "özhan", "özlem"] 

for i in liste:
    if re.search("öz[chk]an", i):
        print(i)

yeniliste = ["st", "sat", "saat", "saaat", "falanca"]
for i in yeniliste:
    if re.match("sa*t",i):
        print(i)

kardiz = "python bir programlama dilidir"
nesne = re.search("(python) (bir) (programlama) (dilidir)", kardiz)
print(nesne.group()) # ya da print(nesne.group(0))
print(nesne.group(1))
print(nesne.group(2))
print(nesne.group(3))
print(nesne.groups())