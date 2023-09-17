
"""
binary dosyalari resim dosyalari, muzik dosyalari,
video, office dosyalari vb dosyalardir
"""
fi = open ("ders.pdf","rb")
file = fi.read()

a = file.index(b"/Creator") #belgeyi isteyen yazilim
b = file.index(b"/Producer") #belgeyi PDF ceviren yazilim
#c = file.index(b"/Title") # belgenin basligi
d = file.index(b"/Author") #belgenin yazari
#e = file.index(b"/Subject") #belgenin konusu
#f = file.index(b"Keywords") #belgenin anahtar kelimesi
g = file.index(b"/CreationDate") #dosyanin olusturulma tarihi
h = file.index(b"/ModDate") #belgenin degistirilme tarihi

chr(file[a])
chr(file[b])
chr(file[d])
chr(file[g])
chr(file[h])
print (file[a:a+30])
print (file[b:b+30])
#print (file[c:c+30])
print (file[d:d+30])
#print (file[e:e+30])
#print (file[f:f+30])
print (file[g:g+30])
print (file[h:h+30])
