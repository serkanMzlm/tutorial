#belitrilen resimde fare ile tıklanan yerdeki rengin HSV degerini gösterir

import cv2


def HVS_Algila(mouse, x, y, flags, param):

    if mouse == cv2.EVENT_LBUTTONDOWN: #farenin sol kısmına basılınca çalışsın
        h = hsv[y, x, 0]
        s = hsv[y, x, 1]
        v = hsv[y, x, 2]

        hsvUzayi = 'HSV: ' + str(h) + ' ' + str(s) + ' ' + str(v)
        cv2.putText(img, "+", (x-14, y+12), cv2.FONT_HERSHEY_PLAIN, 2, (255,0,0), 2)
        cv2.putText(img, hsvUzayi, (x,y), cv2.FONT_HERSHEY_PLAIN, 1, (0,0,255),2 )
        cv2.imshow("img", img)

img = cv2.imread('1.jpg') #HSV üstünde aranacak resmin bulundugu klasör yolu
img = cv2.resize(img,(640,480)) #ekran boyut ayarlama
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) #görüntüyü HSV formatına cevirme
cv2.imshow("img", img)
cv2.setMouseCallback('img',HVS_Algila) #farenin görüntü üstündeki konum bilgilerini gönderir
cv2.waitKey(0)
cv2.destroyAllWindows()
