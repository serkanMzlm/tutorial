import colorama

colorama.init(autoreset=True) #konsol ekranında renklendirme yapılması için gerekli ayarlamalar yapıldı
print(colorama.Fore.BLUE + "Mavi") #Fore sayesinde yazının rengini ayarlayabiliriz
print(colorama.Fore.RED + "Kirmizi")
print(colorama.Fore.GREEN + "Yesil")

print(colorama.Back.CYAN+"Cyan") #Back arkaplan rengini ayarlanmasını saglar
print(colorama.Style.RESET_ALL) #bencere ayarlarını sıfırlar

"""from colorama import Fore, Back, Style, init
init(autoreset=True)
print(Fore.RED + 'sade kırmızı yazı')
print(Back.GREEN + 'Yeşil arkaplan')
print(Style.DIM + 'Python')
print(Style.RESET_ALL)
print('Tekrar normal haline döndü')"""
