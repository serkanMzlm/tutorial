"""
Demetler listelerle ayni sayilir en önemli farkı
listeler degistirilebilir demetler degistrilemez
olmasidir
Tek ogeli demetler yapılırken  "," konmak zorundadir
yoksa demet  olmaz
"""
demet = ("a",) #tek ögeli demet 
demet2 = ("a","b","c",1,1,1,3)
print (demet)
print (demet2.index(1)) #demette yerini  geri dondurur eger bulamazsa hata verir
print (demet2.count(1)) #kac kez gectigi

