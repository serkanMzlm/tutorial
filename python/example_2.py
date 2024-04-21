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