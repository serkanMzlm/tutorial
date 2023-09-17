import cv2


def HVS_Algila(mouse, x, y, flags, param):

    if mouse == cv2.EVENT_LBUTTONDOWN: #farenin sol kısmına basılınca çalışsın
        h = hsv[y, x, 0]
        s = hsv[y, x, 1]
        v = hsv[y, x, 2]

        hsvUzayi = 'HSV: ' + str(h) + ' ' + str(s) + ' ' + str(v)
        print(hsvUzayi)
        cv2.imshow("img", img)
cap = cv2.VideoCapture(0)

while True:

    _,img = cap.read() #HSV üstünde aranacak resmin bulundugu klasör yolu
    img = cv2.resize(img,(640,480)) #ekran boyut ayarlama
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) #görüntüyü HSV formatına cevirme
    cv2.imshow("img", img)
    cv2.setMouseCallback('img',HVS_Algila) #farenin görüntü üstündeki konum bilgilerini gönderir
    if cv2.waitKey(1) == ord("q"):
        break
cap.release()
cv2.destroyAllWindows()
