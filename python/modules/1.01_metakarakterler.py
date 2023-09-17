
import re
a = 0
liste = ["sat","saat","saaat","set","seet","sut","suut","t","$","at", "katkı", "fakat", "atkı", "rahat", "mat", "yat", "sat", "satılık", "katılım"]
for i in liste:
 a = a+1
 print("**********************\n{}. dongu '{}' kelimesi\n*********************** ".format(a,i))
 nesne1 = re.search("s[ae]t",i) #e veya a dan herhangi biri olup olmadıgına bakar
 if nesne1:
     print("nesne1 : ", nesne1.group())
 nesne2 = re.search("s.t",i) #tek bir karakterlik herhangi bir şey olduğuna bakar
 if nesne2:
     print("nesne2 : ", nesne2.group())
 nesne3 = re.search(".*t",i) #0 yada  daha fazla sayıda yer ayırır
 if nesne3:
     print("nesne3 : ", nesne3.group())
 nesne4 = re.search(".+t",i) #sonu t ile bitenler getirir ama sadece t karakterini getirmez * ise getirir
 if nesne4:
     print("nesne4 : ",nesne4.group())
 nesne5 = re.search("s?t",i) #0 veya 1 olduğu durumlarda  kullanılır
 if nesne5:
     print("nesne5 : ",nesne5.group())
 nesne6 = re.search("sa{0,3}t",i) # bir karakterin en az kac en fazla kaç kez geçtiği istersek tek parametre ile  kac kez gececeğini belirtilebilir
 if nesne6:
     print("nesne6 : ",nesne6.group())
 nesne7 = re.search("^sa",i) #dizinin en bası ne ile basladıgına bakar
 if nesne7:
     print("nesne7 : ",nesne7.group())
 nesne8 = re.search("$at",i) #sonununnasıl bitmesi gerektiğini  bakar
 if nesne8:
     print("nesne8 : ",nesne8.gruop())
 nesne9 = re.search("\$",i) #özel anlam içeren karakterleri aratması sağlanır
 if nesne9:
     print("nesne9 : ",nesne9.group())
 nesne10 = re.search("^at|at$",i) #veya anlamı taşır yane at ile başlayan yada at ile biten kelimeler
 if nesne10:
     print("nesne10 : ",nesne10.group())


