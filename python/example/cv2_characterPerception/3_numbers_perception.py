import cv2
import pytesseract as pt

pt.pytesseract.tesseract_cmd = "D:\\Program Files\\Tesseract-OCR\\tesseract.exe" #tesseract bulunduğu kütüphane yolu

img = cv2.imread("1.PNG") #okunacak resmin adı
img = cv2.resize(img,(640,480)) #görüntü boyutları
img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB) #gelen resmi BGR --> RGB çevirir
hImg,wImg, _ = img.shape #img yüksekliği ve genişliği

#pt.image_to_string(img) karakterleri algılar
#pt.image_to_boxes(img) algılanan her karakterin w,h,x,y  verir

cong = r"--oem 3 --psm 6 outputbase digits" #sadece sayıları algılama
boxes = pt.image_to_data(img,config=cong) #karakterlerin biribirine yakınlıgına bakarak kelime ve sayıları algılar

for x,b in enumerate(boxes.splitlines()):
    if x != 0:
        b = b.split()
        if len(b) == 12: # 11. indiste karakterleri bulundurur

            x,y,w,h = int(b[6]),int(b[7]),int(b[8]),int(b[9])
            cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2) #kareye alma
            cv2.putText(img,b[11],(x,y),cv2.FONT_HERSHEY_COMPLEX,1,(0,0,255 ),2)




    cv2.imshow("",img)
cv2.waitKey(0)
