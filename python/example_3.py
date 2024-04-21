#!/usr/bin/python3 

metin = """Bu programlama dili Guido Van Rossum adlı Hollandalı bir
programcı tarafından 90'lı yılların başında geliştirilmeye başlanmıştır."""
silinecek = "aeıioöuüAEIİOÖUÜ"
çeviri_tablosu = str.maketrans('', '', silinecek)
print(metin.translate(çeviri_tablosu))

print("{:,}".format(123456789900.265))


isim = "serkan"
soyad = "mazlum"
sayi1, sayi2 = 10 ,20
print(f'Selam {isim} {soyad} {sayi1+sayi2}!')

print(f"""Sayıların toplamı { int(input("Birinci sayıyı girin: ")) 
											+ int(input("İkinci sayıyı girin: ")) } eder.""")