from colorama import Fore, Back, Style, init
#konsol ekranında renklendirme yapılması için gerekli ayarlamalar yapıldı
init(autoreset=True) 

# Fore sayesinde yazının rengini ayarlayabiliriz. 
# Back arkaplan renginin ayarlanmasını sağlar.
# Style.RESET_ALL konsol ayarlarını sıfırlanmasını sağlar.
print(Fore.BLUE + "Mavi", Fore.RED + "Kirmizi", Fore.GREEN + "Yesil") 
print(Back.CYAN + "Cyan", Back.YELLOW + "Yellow", Back.MAGENTA + "Magenta")
print(Style.DIM + 'Python')
print(Style.RESET_ALL) 
