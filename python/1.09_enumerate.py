# sıralama islemi yapmamizi sağler

print (*enumerate("istanbul"))
print (*enumerate("istanbul",1)) #ikinci parametre  sıralam işleninin kactan baslayacagını belirtir

for harf , sira in enumerate("istanbul",1):
  print ("{}.  {}".format(harf,sira))
