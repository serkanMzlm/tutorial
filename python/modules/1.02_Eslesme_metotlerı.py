import re
metin = "Ankara İstanbul Trabzon İzmir"

nesne = re.search("(Ankara) (İstanbul) (Trabzon) (İzmir)",metin)
print (nesne.group(0)) # butun arananan herşeyi getirir
print (nesne.group(1)) #birinci  kısmı getirir
print (nesne.group(2))
print (nesne.group(3))
print (nesne.group(4))

print(nesne.groups()) #arama listesinin tamamını gösterir
