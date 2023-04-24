/*

  Purpose:

    TRANSFORM is an example of a transformation of an EDP using some parameters for Intro PP Students.

  Example:

    23 Apr 2023 7:27:12 PM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    23 April 2023

  Author:
  George 
  OpenMP Modification:
  23 april 2023 by Jeicob Restrepo, Universidad Industrial de Santander jeicob2183076@correo.uis.edu.co                   
  This OpenMP Modification makes a parallelization of the original Code... 
*/
#include<stdio.h>
#include<math.h>
#include<omp.h>

/* Define the function to be integrated here: */
double f(double x){
  return x*x;
}

/*Program begins*/
int main(){
  int n,i;
  double a,b,h,x,sum=0,integral;
  /*Ask the user for necessary input */
  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  
  /*
  Se utiliza la directiva #pragma omp parallel for para paralelizar el ciclo que recorre los subintervalos.
  La cláusula shared(sum) indica que la variable sum será compartida entre los hilos que se creen.
  La cláusula private(i,x) indica que las variables i y x serán privadas para cada hilo.
  El ciclo for va desde 1 hasta n-1, ya que los extremos del intervalo ya se han incluido en el cálculo del área.
  La variable x se actualiza en cada iteración para que represente el extremo derecho del subintervalo actual.
  La directiva #pragma omp atomic se utiliza para asegurar que la suma de f(x) en cada subintervalo sea atómica, es decir, que sea ejecutada como una operación única.
  */
  #pragma omp parallel for shared(sum) private(i,x)
  for(i=1;i<n;i++){
    x=a+i*h;
    #pragma omp atomic
    sum=sum+f(x);
  }

  integral=(h/2)*(f(a)+f(b)+2*sum);
  /*Print the answer */
  printf("\nThe integral is: %lf\n",integral);
}
