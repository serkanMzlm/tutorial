#!/usr/bin/python3
import cv2
import pytesseract as pt


img = cv2.imread("1.PNG") #okunacak resmin adı
img = cv2.resize(img,[640,480]) #görüntü boyutları
img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB) #gelen resmi BGR --> RGB çevirir
hImg, wImg,_ = img.shape #img yüksekliği ve genişliği

#pt.image_to_string(img) karakterleri algılar
#pt.image_to_boxes(img) algılanan her karakterin w,h,x,y  verir

boxes = pt.image_to_boxes(img)

for b in boxes.splitlines():
    b = b.split(" ")
    x, y, w, h = int(b[1]), int(b[2]), int(b[3]), int(b[4])
    cv2.rectangle(img,(x,hImg- y), (w,hImg- h),(255,0,0),2) #kareye alma
    cv2.putText(img,b[0],(x+5,hImg- y+20),cv2.FONT_HERSHEY_COMPLEX,1,(0,0,255 ),1)
    cv2.imshow("",img)
cv2.waitKey(0)
