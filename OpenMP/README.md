#Procedimiento
Inicialmente se descarga el archivo de ejemplo "trapezAreaSimple.C".
Luego utilizando OpenMP procedemos a paralelizarlo:
mediante el codigo ```#pragma omp parallel for shared(sum) private(i,x)``` en este codigo se utiliza la directiva #pragma omp parallel for para paralelizar el ciclo que recorre los subintervalos.
La cláusula ```shared(sum)``` indica que la variable sum será compartida entre los hilos que se creen.
La cláusula ```private(i,x)``` indica que las variables i y x serán privadas para cada hilo.
![image](https://user-images.githubusercontent.com/82180254/233878395-f34f19da-3b9b-443f-99ad-4df75afbd941.png)
![Captura de pantalla 2023-04-23 201136](https://user-images.githubusercontent.com/82180254/233878409-ee39c055-7fff-4f3d-ab9c-f84c97fd9aeb.png)
