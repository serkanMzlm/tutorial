#http://wiki.python.org/moin/DatabaseInterfaces
#Bunlar arasında sadeliği ve kullanım kolaylığı nedeni ile sqlite

import  sqlite3 as sql

vt = sql.connect("deneme1.sqlite") # bir ad koyarak veri tabanı olusturuldu
#vt = sql.connect(":memory:") # sabit disk yerine RAM de saklanır
im = vt.cursor()
im.execute("CREATE TABLE IF NOT EXISTS kisi(isim,soyisim)") #CREATE TABLE tablo oluşturma kommutu 
#adres_defteri adında iki tablo oluşturuldu
im.execute("INSERT  INTO kisi VALUES('ali','koc')") #işlenecek verileri hazırlar
vt.commit() #verilerin işlenmesini sağlar
im.execute("SELECT * FROM kisi") #kisi adlı tabloda bulunan bütün veriler anlamına gelir
veri = im.fetchall() # secilen verilerin alınmasını saglar
#veri = im.fetchone her cagrıldıgında sadece bir ver alıp bir ileri gider
#veri = im.fetchmany(5) belirtilen kadar veriyi ceker
#im.execute("SELECT name  FROM kisi") sayesinde kisi tablosunun baslıklarını ogreniriz
#im.execute("SELECT * FROM kisi WHERE ad = 'ali'") seklinde istenilen veriye gider
print(veri)





vt.close() #veritabanını kapatılması
