import cv2
import numpy as np

cap = cv2.VideoCapture(0) #kamera ıd


while True:
    _,img = cap.read() #resim algılama ve alınan resım
    flipImg = cv2.flip(img,1) #aynalama
    hsvImg = cv2.cvtColor(flipImg,cv2.COLOR_BGR2HSV) #HVS formatına ceviriyoruz

    #REnklerin HVS atl ve üst degerleri
    #Turuncu
    lowerOrange = np.array([0, 100, 100])
    upperOrange = np.array([22, 255, 255])
    #Sarı
    lowerYellow = np.array([22, 146, 190])
    upperYellow = np.array([38, 180, 250])
    #Yesil
    lowerGreen = np.array([38, 100, 100])
    upperGreen = np.array([75, 255, 255])
    #Mavi
    lowerBlue = np.array([75, 100, 100])
    upperBlue = np.array([130, 255, 255])
    #Mor
    lowerPurple = np.array([130, 100, 100])
    upperPurple = np.array([160, 255, 255])
    #Kırmızı
    lowerRed = np.array([160, 100, 100])
    upperRed = np.array([179, 255, 255])


    greenMask = cv2.inRange(hsvImg,lowerGreen,upperGreen) #belirtilen deger aralıklarınnda maskeleme yapar siyah beyaz
    green = cv2.bitwise_and(flipImg,flipImg,mask=greenMask) #algılanan renkleri normal renkte diger her yer siyah



    cv2.imshow("img",flipImg)
    cv2.imshow("greenMask",greenMask)
    cv2.imshow("green",green)



    if cv2.waitKey(1) == ord("q"):
        break



cap.release() #serbest bırakma
cv2.destroyAllWindows() #pencereleri kapatma
