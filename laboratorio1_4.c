/* Laboratorio versión 1.0.2
 * ALSE
 * Integrantes: Alejandra Forero, Diego Coy, Juan Andres Riapira
 *Este codigo se realiza con el objetivo de poner en practica nuestras habilidades y conocimientos en programación en lenguaje C.
 El programa solicita valores al usuario con un formato especifico, con el fin de obtener el valor promedio, la desviacion estandar y los valores máximos y mínimos de los números ingresados*/

// se incluye las librerias y se define las constantes a usar

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

# define Max_tan 300
# define maxq 15

// se inicializan las funciones a usar a lo largo del codigo

int menu (char *cadena1, char *cadena2);
int opciones (char *cadena1, char *cadena2);
int ingresar (char *cadena1);
int promedio (char *cadena1);
int desviacion(char *cadena1);
int max_min (char *cadena1);
int sumav (char *cadena1,int sum);
int sum2_vectores (char *cadena1,char *cadena2);

void salir();

//Se define la función principal
int main (void)
{
        printf ("\n \t \t Bienvenido a nuestra aplicación, este es el menu de opciones \n ");
        char cadena1 [Max_tan];
        char cadena2 [Max_tan];
        int result1 [Max_tan];
        menu (cadena1, cadena2);
        opciones(cadena1, cadena2);
        return 0;
}
// la función menu se esncarga de mostrar el menu y dirigir al usuario a la función opciones
int menu(char *cadena1, char *cadena2)
{
        printf ("\n 1. Ingresar valores \n 2. Mostrar promedio \n 3. Mostrar desviación estandar \n 4. Mostrar valores maximos y minimos. \n 5. Mostrar todo \n 6. Comparación de la suma total entre dos arreglos \n 7. Salir \n");
        opciones(&cadena1[0],&cadena2[0]);
}
// La función ociones toma el valor indicado por el usuario y lo dirige a la accion solicitada por este
int opciones (char *cadena1, char *cadena2)
{
        int variable1;
        char *dirr;
        char valor1[Max_tan];
        char valor2[Max_tan];
        char valor3[Max_tan];
        char valor1_1[Max_tan];
	dirr=cadena1;
        strcpy(valor1, cadena1);
        strcpy(valor2, cadena1);
        strcpy(valor3, cadena1);
	strcpy(valor1_1,cadena2);

        printf("\n Introduce el número de la opción que desees: \n ");
        scanf ("%d", &variable1);

        printf("\n La dirección de la cadena1 es: %p \n", dirr);

        switch (variable1)
        {
                case 1:
                        ingresar(cadena1);
                        menu(cadena1, cadena2);
                        break;
                case 2:
                        
                        promedio(valor1);
                        menu(cadena1, cadena2);
                        break;
                case 3:
                 
                        desviacion(valor1);
                        menu(cadena1, cadena2);
                        break;
                case 4:
                        
                        max_min(valor1);
                        menu(cadena1, cadena2);
                        break;
                case 5:
                        promedio(valor1);
                        max_min(valor2);
                        desviacion(valor3);
                        menu(cadena1, cadena2);
                        break;

		case 6:

                        sum2_vectores (valor1,valor1_1);
                        menu(cadena1,cadena2);

                        break;
                case 7:
                
                        printf("\n\n ----- Gracias por usar nuestra aplicación ----- \n\n");
                        salir();
                        break;


                default:
                        printf("\n-------------Por favor, ingrese un valor válido---------- \n\n");
                        menu(cadena1, cadena2);
                        break;
	}
return 0;
}

//La función ingresar se encarga de tomar la información dada por el usuario y cinvertirla en enteros para que con esta información se pueda proceder a ejecutar las otras funciones
int ingresar (char *cadena1)
{
        printf ("\n Porfavor escriba los valores que desea ingresar, maximo cinco valores y separados por ; (ejemplo: valor1;valor2;valor3...) \n");
        scanf("%s", cadena1);

        printf("\n El valor ingresado corresponde a: %s \n", cadena1);
        int cont=0;
        char reserv[Max_tan];
        char delimitador [] = ";";
        strcpy(reserv, cadena1);
        char *token = strtok(cadena1, delimitador);
        do
        {
                //printf("\n Componente %d : es %s \n", cont+1, token);
                cont++;
                token=strtok (NULL, delimitador);
        }
        while (token != NULL);
        strcpy(cadena1,reserv);
return 0;
}

// La función promedio toma los datos resultantes de la función ingreso y halla el promedioo de este
int promedio (char *cadena1)
{
        int cont=0;
        int sum=0;
        printf("\n\n cadena1 :  %s \n\n",cadena1);
        float prom;
	char delimitador [] = ";";
        char *token = strtok (cadena1, delimitador);
        do
        {
                sum=atoi(token)+sum;
                cont++;
                token=strtok (NULL, delimitador);
        }
        while(token != NULL);
        prom = (sum+0.0)/cont;
        printf("\n El promedio es igual a: %1.3f \n", prom);
return 0;
}

// LA función desviación se encarga de calcular la desviacion estandar del arreglo

int desviacion(char *cadena1)
{
        int cont=0;
        int sum=0;
        printf("\n\n cadena1 :  %s \n\n",cadena1);
        float prom;
        char delimitador [] = ";";
        char cadena3[Max_tan];
        strcpy(cadena3,cadena1);
        char *token = strtok (cadena1, delimitador);
        float desviacion=0;
        float suma=0;
        float cuadrado=0;
        float diferencia=0;

        do
        {
                sum=atoi(token)+sum;
                cont++;
                token=strtok (NULL, delimitador);
        }
        while(token != NULL);
        prom=(sum+0.0)/cont;
        printf("\n prom %1.3f", prom);

        char delimitador2 [] = ";";
        char *token2 = strtok (cadena3, delimitador2);

        while (token2 != NULL)
        {
                diferencia=atoi(token2)-prom;
                printf("\n: %f", diferencia);
                cuadrado=pow(diferencia,2);
                suma=suma+cuadrado;
                token2=strtok (NULL, delimitador2);
                printf("\n %s", token2);
        }

        desviacion=sqrt((suma+0.0)/cont);
        printf("\n La desviación es igual a:  %1.3f \n\n", desviacion);

        return 0;

}


// Esta función se encarga de hallar el valor maximo y minimo del arreglo
int max_min (char *cadena1)
{
        int cont=0;
        int valor=0;
        int max=0;
        int min=0;
        char delimitador [] = ";";
        char *token = strtok(cadena1, delimitador);
        do
        {
                if (cont==0)
                {
                        max=atoi(token);
                        min=atoi(token);
                }
                cont++;
                valor=atoi(token);
                if (max<valor)
                {
                        max=valor;
                }
                else if (min>valor)
                {
                        min=valor;
                }
                token= strtok(NULL, delimitador);
        }
        while (token != NULL);
	printf("\n El valor máximo es: %d \n", max);
        printf("\n El valor mínimo es: %d \n", min);
return 0;
}

// Esta función se encarga de realizar la suma y comparacion entre los dos arreglos 
int sum2_vectores (char *cadena1,char *cadena2)
{

        printf ("\n Porfavor escriba los valores que desea ingresar,de igual tam                                                                                                             año al primer vectorseparados por ; (ejemplo: valor1;valor2;valor3...) \n \n ");
        scanf("%s", cadena2);
        int cont=0;
        char copia1[Max_tan];
        strcpy(copia1,cadena1);
        int sum1;
        int sum2;
        char delimitador [] = ";";
        sum1=sumav(copia1,sum1);
        sum2=sumav(cadena2,sum2);
        printf("\n la suma de los componentes del vector 1:%d \n y la suma de los componentes del vector2: %d\n",sum1,sum2);
        if (sum1>sum2){

                printf("\nLa suma de los componentes en el vector 1, es mayor que el vector 2\n");

        }else if (sum2>sum1 ){

                printf("\nLa suma de los componentes en el vector 2, es mayor que el vector 1\n");
        }else {

                printf("\nLa suma de los componentes de los dos vectores son iguales\n");
        }

return 0;
}
int sumav (char *cadena1,int sum){
        sum=0;
        int cont=0;
        char delimitador [] = ";";
        char *token = strtok (cadena1, delimitador);
        do {//copia-------------------------------
                sum=atoi(token)+sum;//la prueba
                cont++;
                token = strtok (NULL, delimitador);
                }
        while (token != NULL);//copia-------------
        return sum;
}

// Esta saca al usuario de la aplicación
void salir()
{
        exit(-1);
}
                  
