#sozluklerde sira diiye bir kavram olmmadigi icin sayi ile cagrilamaz
#sozluk[key:value]
sozluk = {"ç":"c", "Ç":"C", "ğ":"g", "Ğ":"G", "ş":"s", "Ş":"S", "ı":"i", "İ":"I", "ü":"u", "Ü":"U"}
print (sozluk["ç"])
liste = list(sozluk.keys()) #anahtar kismini cagirilir
print (liste)
demet = tuple(sozluk.values()) #deger kismi
print (demet)
for anahtar,deger in sozluk.items(): #key ve value verir
  print (f"{anahtar} : {deger} ")
sozluk.get("d","Bu kelime yok") #sorgulama yapar eger sozlukte yoksa ekrana verecegi bildirimi yazilir
yedek_sozluk = sozluk.copy() #kopyalama
yedek_sozluk.clear() #sozlugu temizleme
yeni = dict.fromkeys(liste,"TM") #girilen keyleri verilen degerleri atama yaparak sozlukte degısım yapmaz
print (yeni)
sozluk.pop("ç","sozukte yok") #sozlukten istenilen silme istersek hata mesajınıda yazabılırız
sozluk.popitem() #rasgele silme yapar
sozluk.setdefault("f","F") #eger f yoksa sozlukte default olarak içindeki deger atanir
print (sozluk)
stok = {"elma" : 10 ,"armut":5}
yeni = {"elma":7, "armut":13}
print (stok)
stok.update(yeni) #verileri gunceller
print (stok)
