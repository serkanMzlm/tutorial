#!/usr/bin/python3 
var = "DEneme"
Upper = var.upper()
Lower = var.lower()
Casefold = var.casefold()
print("Upper: ", Upper, " Lower: ", Lower, " Casefold: ", Casefold)
if var.isupper():
    print("isupper")
elif var.islower():
    print("islower")

text1 = "Hello123"
text2 = "Hello 123"
text3 = "Hello!"
text4 = "123"
print(text1.isalnum())  # Çıktı: True
print(text2.isalnum())  # Çıktı: False (boşluk karakteri var)
print(text3.isalnum())  # Çıktı: False (semboller var)
print(text4.isalnum())  # Çıktı: False (semboller var)