import re
metin = "1FF ff4 sdfg 55f 3343 fghd"

nesne = re.search("\s\d+\w",metin) # \s bir boluk tutar \d bir sayı + 0 veya daha fazla sayı olabilir w ise alfanümerik
print(nesne.group())
