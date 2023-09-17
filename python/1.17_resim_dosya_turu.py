file = open("dosya_adi","rb")
veri = file.ride(10)
if veri[6:11] in [b"JFIF",b"Exif"]:
  print ("JPEG dosyasi")
elif veri[:8] == b"\211PNG\r\n\032\n":
  print ("PNG dosyasi")
elif veri[:3] ==b"GIF":
  print ("GIF dosyasi ")
elif veri[:2] in [b"II",b"MM"]:
  print ("TIFF dosyasi ")
elif veri[:2] == b"BM" :
  print ("BMP dosyasi")
