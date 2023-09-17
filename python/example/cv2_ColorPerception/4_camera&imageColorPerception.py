"""
Kameradan fare ile tıklanan yere göre o kısımda bulunan HSV 
bilgisini alıp aynı renkleri  iki farklı ekranda gösterme
"""
import cv2
import numpy as np

def HVS_Algila(mouse, x, y, flags, param):

    if mouse == cv2.EVENT_LBUTTONDOWN: #farenin sol kısmına basılınca çalışsın
        h = hsvImg[y, x, 0]
        s = hsvImg[y, x, 1]
        v = hsvImg[y, x, 2]
        print("HSV:",h,s,v)
        lower = np.array([h - 8, s - 25, v - 50])
        upper = np.array([h + 8, s + 25,v+50])
        Mask = cv2.inRange(hsvImg, lower, upper)  # belirtilen deger aralıklarınnda maskeleme yapar siyah beyaz
        color = cv2.bitwise_and(flipImg, flipImg, mask=Mask)  # algılanan renkleri normal renkte diger her yer siyah
        cv2.imshow("greenMask", Mask)
        cv2.imshow("green", color)

cap = cv2.VideoCapture(0) #kamera ıd


while True:
    _,img = cap.read() #resim algılama ve alınan resım
    flipImg = cv2.flip(img,1) #aynalama
    hsvImg = cv2.cvtColor(flipImg,cv2.COLOR_BGR2HSV) #HVS formatına ceviriyoruz
    cv2.imshow("img", flipImg)
    cv2.setMouseCallback('img', HVS_Algila)

    if cv2.waitKey(1) == ord("q"):
        break

cap.release() #serbest bırakma
cv2.destroyAllWindows() #pencereleri kapatma
