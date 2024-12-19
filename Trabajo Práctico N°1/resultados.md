# Resultados
1) Comando:
    ```
    $ gcc -g -Wall -pedantic-errors -std=c2x -o prog main.c tabla.c conversion.c
    ```

2)  Resultado:  
    ```
    tabla.c: In function 'crear_tabla':
    tabla.c:9:29: error: implicit declaration of function 'conversion' [-Wimplicit-function-declaration]
        9 |         double convertido = conversion(inicio);
          |                             ^~~~~~~~~~

    ```
    El error se produce en la función *crear_tabla* del archivo *tabla.c*, en la línea 9. No está declarada la función *conversion*
    al no incluir el header correspondiente.

3) Comando:
    ```
    $ gcc -g -Wall -pedantic-errors -std=c2x -o prog main.c conversion.c
    ```

    Resultado:  
    ```
    C:/msys64/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\Usuario\AppData\Local\Temp\ccMz8xcL.o: in function `main':
    C:/Users/Usuario/Documents/Universidad/2do/SSL/24-002-xx/TP1/main.c:20:(.text+0x10d): undefined reference to `crear_tabla'
    collect2.exe: error: ld returned 1 exit status
    ```
    El error se produce en la función *main* del archivo *main.c*, en la línea 20. No encuentra el identificador *crear_tabla* ya que no está definido (porque estaba en *tabla.c*).  


4) Comando:
    ```
    $ gcc -E -g -Wall -pedantic-errors -std=c2x conversion.c -o conversion.i
    ```