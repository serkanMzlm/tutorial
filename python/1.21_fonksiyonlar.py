"""
karmasık islemleri toplayarak tek adımda yapmamizi
saglarlar.
def ile fonksiyon tanımlanir
"""

def kayitol(ad,soyad,numara):
	print ("-"*30)
	print ("ad : ",ad)
	print ("soyad : ",soyad)
	print ("numara : ",numara)
	print ("-"*30)

kayitol("ahmet","koma","1234567899")
kayitol("mert","alan","125483325555")
print ("\n")
def bilgial():
	import sys
	print ("Sistem Ana Surum Numarasi : ",sys.version_info.major)
	print ("Sistem Alt Surum Numarasi : ",sys.version_info.minor)
	print ("Sistem Minik Surum Numarasi : ",sys.version_info.micro)
	print ("İsletim Sistemi : ",sys.platform)
bilgial()

#fonksiyona bazlangic degeri ataya biliriz

def defter (ad = "mert",soyad = "ulu",numara = "123456789"):
	print ("ad : ",ad)
	print ("soyad : ",soyad)
	print ("numara : ",numara)
defter ()
defter (soyad = "alkan" ,ad = "murat", numara ="1245789631")

def topla (*parametre): #sinirsiz sayida isimsiz parametre alir
	sonuc = 0
	for i in parametre:
		sonuc +=i
	print ("sayilarin toplami : ",sonuc)
topla(10,12)
topla(10,12,12,12,12,29)
topla(12,23,4,32,1,0)
topla (5)

def adlar (**ad) : #sinirsiz sayida isimli parametre
	print (ad)
adlar(ad1="mert",ad2="ali",ad3="murat")

def deneme(*par,**par2):
	for i in par:
		print (i,**par2)

deneme("ahmet","veli","murat",sep="-",end="****")

def ad ():
  print ("\n\n")
  add = input ("adiniz : ")
  return add
print ("merhaba , ",ad())

ad = "mert"
def yeni():
  ad = "bol"
  return ad
print (yeni())
def yeni2():
  global ad #global degiskeni cagirir
  ad += " bol"
  return ad
print (yeni2())
