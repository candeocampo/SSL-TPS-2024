**Trabajo Práctico Nº 2 – Escáner**

*Hecho con Tabla de Transición*
1. *__Objetivos__*

    a. Armar un escáner para lenguaje mini.

    b. Conocer a bajo nivel como trabaja un escáner.

2. *__Temas__*

    a. Reconocedor léxico.

    b. Autómatas finitos.

3. *__Tareas__*

    a. Se pide armar un escáner para el lenguaje mini que es descripto en la documentación adicional entregada junto con este enunciado. Para ello debe usar una tabla de transición y basarse en el “seudocódigo para TT” de la presentación dada en clase.
    Se debe programar un archivo main que pruebe el escáner, llamándolo hasta que el token devuelto sea FDT (EOF).
    El escáner debe trabajar contra stdin y stdout. Luego para probar podremos redireccionar el archivo entrada.txt al flujo stdin. Se provee el archivo entrada.txt para que puedan probar. Debería dar un salida similar a la mostrada en el archivo salida.txt

    b. Programar usando los siguientes fuentes

     1) main.c llama al escáner hasta que este devuelve el token FDT. Con cada devolución del escáner informa en stdout que token fue reconocido y el lexema correspondiente.

    2) scanner.c tiene el escáner propiamente dicho y sus funciones auxiliares, por ejemplo, una que en base a un carácter devuelva el índice de la columna a usar en la tabla de transición.

    3) scanner.h tiene la información necesaria que debe conocerse en otros fuentes parautilizar el scanner.

    c. Arme antes de programar la documentación de la tabla de transición a usar, puede usar una planilla y entregar ese archivo, o exportarlo a pdf o usar un procesador. Puede documentar entregando en cualquier formato en tanto no utilice formatos propietarios.

    d. Puede usar un makefile si lo considera útil, pero no es requerido.

    e. Si bien un scanner no suele entregar tokens de error, en este caso si lo haremos de modo que main sirva para probar todo.

    f. Siendo que este escáner lo hacemos “a mano” haremos algunas simplificaciones y cambios con respecto a la documentación.

1. Para esta versión no hay comentarios que eliminar

2. No reconoceremos las palabras reservadas, las mismas se informarán como
identificadores.

3. Informaremos 3 tipos de errores

    i. Error común o general, tal como está en la documentación

    ii. Error de asignación, separado en dos casos

    1) Se leyó : pero luego no vino =

    2) Aparece un = sin que inmediatamente antes se leyera :

