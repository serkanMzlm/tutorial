import os

isletimS = os.name # isletim sistemi adını veriri nt(windows) posix(linux ve MAC)
ayrac = os.sep #isletim sistemi hangi ayracı kulandıgı 
bulunulan_dizin = os.getcwd() #bulunulan dizin 
# . bulundugun dizi  .. bir üst dizin
os.startfile('deneme.txt') # bilgisayardaki herhangi programı ilişkilendiği programla açmak 
os.stat("deneme.txt") #dosya hakkında bilgi alınır
os.startfile('https://github.com/serkanMzlm/Python') #aynı zamanda web sayfalarınıda açabilir
os.mkdir("yaniD") #yeni dizi olusturur
os.makedirs(".\\a\\b\\denemeD") #mkdir  farkı bunda yollar yoksa onları oluşturu
os.rename("yeniD","isimD") #os.replace benzer isim değiştirme
os.remove("deneme.txt") # dosya silme
os.rmdir("isimD") # boş dizileri siler
#os.removedirs(C:\\...) içi boş dizi yollarını siler
os.chdir('C:\\Users\\') # dizinler arasında hareket
listele = os.listdir("C:\\Users\\") #dizinin içini listeler
os.system("notepad.exe") #programların başlatılmasını saglar
os.urandom() #rasgele 12 bytan oluşan diziler oluşturmayı sağlar
os.path.abspath("deneme.txt") #tam yolunu gösterir


