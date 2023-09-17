# [] ile ifade ediliyorsa listedir

liste = ["a","b",1,2,3,12.20]
ad = input("adiniz : ")
print ("adiniz : ",ad)
print (list(ad)) # karakter dizilerini kelime kelime listeler
print  (liste)
liste[2] = "c" #ya da liste = ["c"]+liste listede degisiklik yapma 
print (liste)
liste =liste + ["asd"] # listeye ekleme yapma 
print (liste)
del liste[1:3] # listeden silme 
print (liste)
liste2 = [i for i in range (100)]
print ( liste2)

liste.append(ad) # listeye ekleme her seferinde bir sey ekler + ile ayni anlam
print (liste)

liste.extend(liste2) #append ile ayni tek farki tek seferde birden fazla ekleme yapailmesi
print (liste)

del liste[5:]
print (liste)

liste.insert(0,ad) #extend ve append farki ekleyecegimiz yeride biz belirleriz
print (liste)

liste.remove(ad) #istenilen ogeyi silmeye yarar
liste.pop(1) #removeden farki silinen ogeyi ekrana basar
print (liste)

reversed(liste) #ya da liste[::-1] listenin ters cevrilmesi
print (liste)

liste2.sort(reverse = True) #icteki parametre sayesinde ters cevrilir belli bir siraya gore sıralar listenin icinde bulunan ogelerin hepsi  ayni olmak zorundadir
print (liste2)

print (liste.index("a")) # yer bulma icin kullanılır

print (liste.count("a")) #icinde kac kez gectigi 

liste3 = liste.copy() #liste kopyalama
# liste3 = liste[1::]
# liste3 = list(liste) hepsi kopyalama
print (liste3)

liste3.clear() #listeyi temizler
print (liste3)
