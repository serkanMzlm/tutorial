def  fonksiyon():
  sayi = 0
  def say():
    nonlocal sayi
    sayi += 1
    return sayi
  return say

#üreticilerin fonksiyonlardan farki "yield" ve  "next"

def uretec():
  sayi = 0
  while True:
    sayi += 1
    yield sayi
f = fonksiyon()
print (f())
print (f())
print ("*"*10)
u = uretec()
print (next(u))
print (next(u))

#yield from baska bir üreticinin yield ceker

def ur1():
 yield print ("uretici1")
 yield print ("uretici1.1")
def ur2():
 yield print ("uretici2")
 yield from  ur1()
for i in  ur2():
 i
