import cv2
import pytesseract
from time import time


pytesseract.pytesseract.tesseract_cmd = 'D:\\Program Files\\Tesseract-OCR\\tesseract.exe' #tesseract.exe konumu
cap = cv2.VideoCapture(0) #kamera ID belirtiriz

ctime = ptime  =0
while True:

    _,img = cap.read()
    img = cv2.flip(img,1) #aynalama
    img = cv2.resize(img,(640,480)) #ekran boyutlarını ayarlama
    hImg, wImg,_ = img.shape #ekranın genişlik ve yukseklik bilgisini alırız


    boxes = pytesseract.image_to_boxes(img) #algılanan yazıların x, y, w, h bilgilerini verir
    for b in boxes.splitlines(): #satırlara böleriz

        b = b.split(' ')
        x, y, w, h = int(b[1]), int(b[2]), int(b[3]), int(b[4])
        cv2.rectangle(img, (x,hImg- y), (w,hImg- h), (50, 50, 255), 2) #belitrilen konumlara dörtgen oluşturur
        #

    ctime = time()
    fps = 1/(ctime-ptime);
    ptime = ctime

    cv2.putText(img, str(int(fps)), (75, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (20,230,20), 2);
    cv2.imshow("Result",img)
    if cv2.waitKey(1) == ord("q"):
        break
cv2.destroyAllWindows()
