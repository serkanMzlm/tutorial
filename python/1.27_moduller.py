import os # Operating System ( isletim sistemi ) ice aktarma
import subprocess as sp #modulu artik cagirirken sp yazmak yeterli bu modül python icinde harici komutlari calistirmaya yarar
from webbrowser import open as op #internet sistemi acilmasini saglar. hem adi kısaltma hem de sadece bir ozelligini ice akratma
from sys import version #modulun icinde bulunan  istedigimiz ozelliklerini aktarmamizi saglar
from random import * #bu sayede tüm hepsini sisteme ekler "random." yazmaya gerek yoktur
if os.name == "posix": #linux ve mac ciktisi
  print ("GNU/Linux veya Mac isletim sistemi.")
elif os.name == "nt": #windows  ciktisi
  print ("windows isletim sistemi")
os.makedirs("deneme") #bulunulan dizinin icine dizi olusturur
print (os.getcwd()) #o an  hangi dizinde oldugunuz
#sp.call ("notepad.exe") notped calistirirlir.
op("https://github.com/serkanMzlm") # web sayfasini acar
print (version) #python surumunu verir sadece bu ozellik aktarildigi icin "sys." yazılmaz

