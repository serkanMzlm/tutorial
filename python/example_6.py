#!/usr/bin/python3 
def carp(*sayi):
    sonuç = 1
    for i in sayi:
        sonuç *= i
    print(sonuç)

def fonksiyon(**parametreler):
    print(parametreler)

def kayit_olustur(**bilgiler):
    for anahtar, değer in bilgiler.items():
        print("{:<10}: {}".format(anahtar, değer))

carp(1, 2, 3, 4)
kayit_olustur(ad="Fırat", soyad="Özgül", şehir="İstanbul", tel="05333213232")
fonksiyon(isim="Ahmet", soyisim="Öz", meslek="Mühendis", şehir="Ankara")