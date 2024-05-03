
from datetime import datetime # datetime sınıfı içinde  date ve time sınıflarını bulundurur

suan = datetime.now() # bulunduğumuz  tarih ve saati verir 
# suan = datetime.todey()  now  ile aynı
bugun = datetime.ctime(suan) #tarih zaman bilgilerini okunaklı verir
#bugun2 = datetime.strftime(suan,"%c") ctime benzer son parametresi 

"""
%a:hafta gününün kısaltılmış adı
%A:hafta gününün tam adı
%b:ayın kısaltılmış adı
%B:ayın tam adı
%c:tam tarih, saat ve zaman bilgisi
%d:sayı değerli bir karakter dizisi olarak gün
%j:belli bir tarihin, yılın kaçıncı gününe denk geldiğini gösteren 1-366 arası bir sayı
%m:sayı değerli bir karakter dizisi olarak ay
%U:belli bir tarihin yılın kaçıncı haftasına geldiğini gösteren 0-53 arası bir sayı
%y:yılın son iki rakamı
%Y:yılın dört haneli tam hali
%x:tam tarih bilgisi
%X:tam saat bilgisi

 
suan.year
suan.month
suan.day
suan.hour
suan.minute
suan.second
suan.microsecond

şeklinde istenilen net tarih cekilebilir
"""
print(suan) 
print(bugun) 


