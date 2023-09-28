## IPC
#### Build 
```
gcc file_name.c -o executable_name
```

- **signals** örneklerinde  receiver tarfının PID kısmı `ps -a` kısmından bakılıp sender tarafına girilmelidir.
- `msg_q_receiver_2.c` ve `msg_q_sender_2.c` dosyaları kullanımı sırasında terminalde belirli bir parametre girilmelidir. Girilen parametrenin başında `/` olmak zorundadır.

```
./msg_q_receiver_2 /msgq
```