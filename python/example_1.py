#!/usr/bin/python3

metin = "Bu yAzıdA küçük A yok."
for harf in metin:
        if harf == 'a':
                print("a harfi bulundu.")
                break
else:
        print("a harfi bulunmadı.")