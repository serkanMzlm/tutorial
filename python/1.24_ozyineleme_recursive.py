def isim(ad):
 if len(ad) < 1:
  return ad
 else:
  print (ad)
  return isim(ad[1:])
def tisim(tad):
 if len(tad) < 1:
  return tad
 else :
  print (tad)
  return tisim(tad[:-1])

name = input ("adiniz : ")
print (isim(name))
print (tisim(name))
