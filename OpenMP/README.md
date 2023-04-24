# Procedimiento
Inicialmente se descarga el archivo de ejemplo "trapezAreaSimple.C".
Luego utilizando OpenMP procedemos a paralelizarlo:
mediante el codigo ```#pragma omp parallel for shared(sum) private(i,x)``` en este codigo se utiliza la directiva #pragma omp parallel for para paralelizar el ciclo que recorre los subintervalos.
La cláusula ```shared(sum)``` indica que la variable sum será compartida entre los hilos que se creen.
La cláusula ```private(i,x)``` indica que las variables i y x serán privadas para cada hilo.
La cláusula ```#pragma omp atomic``` se utiliza para asegurar que la suma de f(x) en cada subintervalo sea atómica, es decir, que sea ejecutada como una operación única, aunque realmente no es necesaria en este caso.
Ya teniendo el nuevo codigo paralelizado, lo que hacemos es acceder a Guane-1, para realizar la compilación y la ejecución paralelizada, para esto lo que se hace es ingresar con el usuario y la contraseña asignados y utilizando el comando ```ssh``` accedemos a toctoc, luego mediante ```ssh guane``` accedemos a Guane-1, una vez allí accedemos a nuestra carpeta y allí ponemos el codigo paralelizado "omp_trapezAreaSimple.c", una vez se tiene el codigo en guane, lo que se hace es compilarlo mediante el comando ```gcc -fopenmp omp_trapezAreaSimple.c -o omp_trapecio``` y porteriormete ejecutarlo con el comando ```./omp_trapecio```, como valores de entrada le puse ```Enter the no. of sub-intervals: 1000```, ```Enter the initial limit: 3```, ```Enter the final limit: 8``` y obtuve como resultado: ```The integral is: 161.666688```, de la misma manera al compilar y ejecutar el codigo desde la maquina local obtuve los mismos resultados.
## Imagen de la ejecución en maquina local
![image](https://user-images.githubusercontent.com/82180254/233878395-f34f19da-3b9b-443f-99ad-4df75afbd941.png)
El codigo fue compilado y ejecutado utilizando Dev c++
## Imagen de la ejecucion en Guane-1
![Captura de pantalla 2023-04-23 201136](https://user-images.githubusercontent.com/82180254/233878409-ee39c055-7fff-4f3d-ab9c-f84c97fd9aeb.png)
