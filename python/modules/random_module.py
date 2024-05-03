import random
random.random() # 0-1.0 arasında sayı  rasgele sayi üretir
random.uniform(10,2000) #belirlenen aralıkta rasgele sayi üretir
random.randint(45,200) #belirlediğimiz aralıkta tam sayı dondürür
liste = ['ali', 'veli', 'ahmet', 'mehmet', 'celal', 'selin', 'nihat']
random.choice(liste) #listeden rasgele birini cekme
random.shuffle(liste) #listelerin icini karıştırır
random.randrange(10,100,5) #randint aynı  sayılır farkı 1 2 ve 3 parametre ile calışabılıyor olması ve sınır degerleri alamamsı
liste2 = range(100)
random.sample(liste2,10) # diziden kac tane numune alınacagını belırler
