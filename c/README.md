 gcc -o main yaml_parser.c -lyaml -lglib-2.0 `pkg-config --cflags --libs glib-2.0`

### Problems
 If you encounter the error 'glib.h: No such file or directory,' the required step is to:

 ```
 sudo apt-get install libglib2.0-dev
 sudo apt-get install libgtk2.0-dev
 ```