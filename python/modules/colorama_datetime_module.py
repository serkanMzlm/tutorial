from colorama import Fore, Back, Style, init
from datetime import datetime 

#konsol ekranında renklendirme yapılması için gerekli ayarlamalar yapıldı
init(autoreset=True) 

# Fore sayesinde yazının rengini ayarlayabiliriz. 
# Back arkaplan renginin ayarlanmasını sağlar.
# Style.RESET_ALL konsol ayarlarını sıfırlanmasını sağlar.
print(Fore.BLUE + "Mavi", Fore.RED + "Kirmizi", Fore.GREEN + "Yesil") 
print(Back.CYAN + "Cyan", Back.YELLOW + "Yellow", Back.MAGENTA + "Magenta")
print(Style.DIM + 'Python')
print(Style.RESET_ALL) 


now = datetime.now() # ya da datetime.todey()

# Verilerin daha okunaklı olması için kullanılır
date = datetime.ctime(now) # ya da datetime.strftime(suan,"%c")
print("now: ", now, "\ndate: ",date)

# %a: Hafta gününün kısaltılmış adı, %A: Tam yazımları
# %b: Ayın kısaltılmış adı, %B: Tam yazımı
# %c: Tam tarih, saat ve zaman bilgisi
# %d: Sayı değerli bir karakter dizisi olarak gün
# %j: Selli bir tarihin, yılın kaçıncı gününe denk geldiğini gösteren 1-366 arası bir sayı
# %m: Sayı değerli bir karakter dizisi olarak ay
# %U: Belli bir tarihin yılın kaçıncı haftasına geldiğini gösteren 0-53 arası bir sayı
# %y: Yılın son iki rakamı, %Y: Tam yazımı
# %x: Tam tarih bilgisi, %X: Tam saat bilgisi

# now.year - now.month - now.day - now.hour
# now.minute - now.second - now.microsecond

