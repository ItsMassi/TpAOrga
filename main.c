#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convertir(long s){// ejercicio 2
    int horas = s/3600;
    s = s % 3600;
    int minutos = s/60;
    s = s % 60;
    printf("El tiempo ingresado es de: %d horas, %d minutos y %ld segundos", horas, minutos,s);
    return 0;
}


int mesurements(){//ejercicio 3a
    int eleccion;
    float conver, resultado;

    printf("Que deseas convertir? \n 1. Celsius -> Fahrenheit \n 2. Millas x hora -> Kilometros x minuto \n 3. Litros -> Galones \n ");
    printf("Eleccion: ");
    scanf("%d", &eleccion);
    printf("\n Cantidad a convertir: ");
    scanf("%f", &conver);

    switch(eleccion){
        case 1://Celsius -> Fahrenheit
            resultado = (conver*1.8)+32;
            printf("%f Celcius son %f Fahrenheit", conver,resultado);
            break;
        case 2://Millas x hora -> Kilometros x minuto
            resultado = conver*37.282;
            printf("%f Millas x hora son %f Kilometros x minuto", conver,resultado);
            break;
        case 3://litros -> galones
            resultado = conver*0.264172052;
            printf("%f Litros son %f Galones", conver,resultado);
            break;
    }

    return 0;

}

int ejercico4(int n){
    int cont = 0;
    long suma = 0;
    long mayor, menor;
    long ingresado;

    printf("ingrese un numero: ");
    scanf("%ld", &ingresado);
    if(ingresado<0){
        while(ingresado<0){
            printf("Error: Ingrese un numero que no sea negativo \n");
            printf("ingrese un numero: ");
            scanf("%ld", &ingresado);
        }
    }

     mayor = ingresado;
     menor = ingresado;
     suma+=ingresado;

    while(cont<n-1){
        printf("ingrese un numero: ");
        scanf("%ld", &ingresado);
        cont++;
        if(ingresado<0){
                printf("Error: Ingrese un numero que no sea negativo \n");
            cont--;
        }else{
            if(ingresado>mayor){
            mayor = ingresado;
            }
            if(ingresado<menor){
                menor = ingresado;
            }
            suma= suma + ingresado;
        }
    }
    float promedio = suma/(float)n; //numerador y denominador deben ser mismo tipo
    printf("-----------------------------------------------------\n");
    printf("suma: %ld | numeros ingresados: %d \n",suma, n);
    printf("Mayor: %ld | Menor: %ld | promedio: %f",mayor,menor,promedio);
}

//ejercicio 5
int cambioDeBaseADiez(int numero,int base){ // 0%10 = 0, esto es cuando vamos a parar: cuando numero == 0
    int n = numero;//backup del numero, usamos int por el redondeo de decimales
    float digito = 0;
    int cont = 0;
    float conversion=0;
   while(n){

        digito = n % 10;
        n = n / 10;
        conversion += digito * pow(base,cont);// conversion = conversion * base^contador
        cont++;

   }

   printf("La conversion del numero es: %d", (int)conversion);
}

//ejericicio 6a
int contarDigitosSource(int numero, int contador){

    printf("Valor de numero: %d | contador: %d \n",numero, contador);

    if(numero == 0){

        printf("valor del contador final: %d \n", contador);

        return contador;
    }else{
        contador++;
        return contarDigitosSource(numero/10,contador);
    }
}


int contarDigitos(int numero){
    int contador = 0;
    int resultado = contarDigitosSource(numero,contador);
    printf("El numero tiene: %d digitos", resultado);
}

//ejercicio 6c
int contarDigitosPares(int numero){
    int contador = 0;
    int pares = 0;
    int resultado = contarDigitosParesSource(numero,contador,pares);
    printf("El numero tiene: %d digitos que cumplen la condicion", resultado);
}

int contarDigitosParesSource(int numero, int contador, int pares){

    printf("anlizando: %d | contador: %d | nro pares: %d\n",numero % 10, contador,pares);
    (contador % 2 != 0) ? (printf("contador no es par: %d\n", contador % 2 != 0)) : (printf("Contador es par: %d\n",contador % 2 != 0));
    (numero % 2 == 0) ? (printf("numero es par: %d\n", numero % 2 == 0)) : (printf("Numero es par: %d\n",numero % 2 == 0));
    printf("---------------------------------------\n");

    if(contador % 2 != 0 && numero % 2 == 0){//impares
        pares++;
    }
    if(numero == 0){

        printf("valor del contador final: %d \n", pares);

        return pares;
    }else{
        contador++;
        return contarDigitosParesSource(numero/10,contador,pares);
    }
}


//ejercicio 9
int cambioDiezToHex(char str[]){//el array debe tener un tamaño maximo de 16 y las letras deben ser mayusculas
    int asciiChar = 0;
    int aux = 0;
    int suma = 0;
    int coeficiente = 0;
    for(int i = 15; i>=0; i--){                                                      //recorremos de atras para adelante
        asciiChar = str[i];                                                         //valor en ascii de cada char del array
        if(asciiChar != 0 && asciiChar != 16){                                      //si la celda no esta vacia
            if(isdigit(str[i])){                                                    //libreria estandar de C no es necesaria la importacion
                aux = str[i] - '0';                                                 //sacamos el valor del digito como integer
                suma += aux * pow(16,coeficiente);
                coeficiente++;                                                      //cada vez que sumamos aumentamos el coeficiente para manter el formato
            }else{
                switch(asciiChar - '@'){//esto para que comience en 1
                    case 1 ://valor de A
                        suma += 10 * pow(16,coeficiente);
                        coeficiente++;
                        break;
                    case 2 ://valor de B
                        suma += 11 * pow(16,coeficiente);
                        coeficiente++;
                        break;
                    case 3 ://valor de C
                        suma += 12 * pow(16,coeficiente);
                        coeficiente++;
                        break;
                    case 4 ://valor de D
                        suma += 13 * pow(16,coeficiente);
                        coeficiente++;
                        break;
                    case 5 ://valor de E
                        suma += 14 * pow(16,coeficiente);
                        coeficiente++;
                        break;
                    case 6 ://valor de F
                        suma += 15 * pow(16,coeficiente);
                        coeficiente++;
                        break;
                }
            }
        }
        printf("El valor en decimal es: %d \n", suma);
    }

    printf("El valor en decimal es: %d", suma);
     return 0;
}
int main(){

    //ejercicio 2
    /*
    int segundos;
    printf("Ingrese una cantidad de segundos: ");
    scanf("%d", &segundos);
    convertir(segundos);
    */

    //ejercicio 3
    //mesurements();

    //ejercicio 4
    /*
    int n;
    printf("Que largo de entrada desea: ");
    scanf("%d",&n);
    ejercicio4(n);
    return 0;*/

    //ejercicio 5
    /*
    printf("Que numero deseas cambiar de base: ");
    int numero;
    scanf("%d",&numero);

    printf("Que base tiene este numero: ");
    int base;
    scanf("%d",&base);
    cambioDeBaseADiez(numero,base);
    */
    // ejercicio 6
    //contarDigitos(4321); //6a
    //contarDigitosPares(4321); //6c

    //ejercico 9
    char str[16];
    scanf("%s", str);
    cambioDiezToHex(str);
}
