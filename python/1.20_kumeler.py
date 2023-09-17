"""
-kumelerde sayi kullanilamaz
-kumelerde her alk kume sadece bir kez gecer
"""
bos_kume = set() # kume olusturma
kume = set(["a","b","c"])
bilgi = "atla"
atla = set(bilgi)
print (atla) #her harf bir kez gozukucektir
atla.clear() # kumeyi temizler
bos_kume = kume.copy() #kopyalama
bos_kume.add("d") #ekleme
print (bos_kume.difference(kume)) #kumeleer arasinda farki gosterir
#difference_update() difference ile nerde ise ayni farki kumenin icini siler sonucu yazar
kume.discard("a") #kumeden oge silme
kume.remove("b") #disard aynı fark olrak olmayan seyi silmeye calisinca hata verir
kume.intersection(bos_kume) #kesisimi verir
"""
intersection_update
km1.isdisjoint(km2) sorgulama yapar aynimilar diye
km1.issubset(km2) kumenın digerinin icinde olup olmadıgını sorgular
km1.issupperset(km2) kapsar mı
km1.union(km2) birlesimi
km1.symmetric_difference(km2) iki kumenin birbirinden farkini alir
km1.symmetric_difference_update(km2)
km1.pop("a") silme islemi
"""
kume.update(bos_kume) #kume digerinin icine yükleme
d_kume = frozenset(["a","b"]) #dondurulmus kume degisiklik yapilmasini engeler
