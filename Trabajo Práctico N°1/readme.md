**Trabajo Práctico Nº 1 – Conversión de velocidades**

*Proyecto con varios fuentes y makefile*

1. *__Objetivos__*

    a. Armar un proyecto con varios fuentes.

    b. Estudiar la relación de los fuentes y sus encabezados.

    c. Analizar posibles errores de compilación.

    d. Armar un archivo makefile para construir el ejecutable.

2. *__Temas__*

    a. Lenguaje de programación C.

    b. Proceso de compilación.

    c. Pasaje de parámetros al programa desde el entorno de invocación.

3. *__Tareas__*

    a. Se quiere un programa que arme una tabla de equivalencia de velocidades, entre nudos y kilómetros por hora. Los valores que la tabla debe convertir se indican con parámetros al lanzar el programa.

    b. Programar usando los siguientes fuentes

    1. main.c lee los parámetros que le pasan al ser invocado y los pasa a la función que arma la tabla. Los parámetros a pasar son (siempre en nudos):
    
        i. inicio: valor inicial a mostrar en la tabla

        ii. fin: valor máximo, la tabla mostrará hasta el mayor valor que no supere este parámetro.

        iii. Incremento: del valor entre una fila y la siguiente. A diferencia de los dos anteriores que son obligatorios y si no están el programa debe parar con un mensaje adecuado, este último es optativo. Si no está se considerará que vale 1.


    2. tabla.c muestra por pantalla (stdout) las filas pedidas, llamando a la función de conversión. Use assert para poner precondiciones sobre los valores de los parámetros recibidos.

    3. Conversion.c recibe una velocidad en nudos y devuelve la correspondiente en km/h.
    
        Nota: 1 nudo equivale a 1,852 km/h.

    c. Arme los encabezados e incluirlos en los fuentes que lo necesiten.

    d. Arme un makefile apropiado para el proyecto.

    e. Arme un archivo de resultados, que puede ser un pdf o un md, donde mostrará los resultados de las siguientes pruebas.

    1. Muestre un comando que permita compilar todo el proyecto (sin el makefile) de
    acuerdo a los lineamientos del curso (adherir estrictamente al estándar).

    2. Compile con el comando anterior pero modifque tabla.c de modo que no incluya
    conversion.h, copie el resultado y coméntelo.

    3. De un comando que compile todos los fuentes menos tabla.c, ejecútelo, muestre el
    resultado y coméntelo.

    4. Copie el comando necesario para obtener conversion.i, el archivo ya preprocesado de conversion.c