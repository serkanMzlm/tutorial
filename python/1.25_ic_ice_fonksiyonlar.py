"""
Hatalı düzeltilicek

"""



def CV(mesaj):
 def ad():
  nonlocal mesaj #ana fonksiyonda olan degişken üzerinde değişiklik yapilmasini sağlar
  mesaj += " mert "
 def soyad():
  nonlocal mesaj
  mesaj += " demir "
 def numara():
  nonlocal mesaj
  mesaj += " 12303654789 "
 return  mesaj
print (CV("*******"))




