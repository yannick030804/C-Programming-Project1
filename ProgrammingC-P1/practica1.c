/***********************************************
*
* @Proposito: Para aprender las funciones básica en C
* @Autor/es: Yannick Suchy Viñolo
* @Fecha creacion: 13/11/2023
* @Fecha ultima modificacion: 23/11/2023
*
************************************************/

// Librerías generales del sistema
#include <stdio.h>
#include <math.h>

// Constantes
#define FLOORS_FOR_INSPECTION 12
#define INSPECTION_PRICE 150

// Procedimiento principal
int main () {

// Declaración de variables
// Variables char para el programa en general
char option, option2, trash, inicio, destino;
// Variables int para el programa en general
int flag = 0, piso1 = 0, piso2 = 0, distMin = 0, distMin2 = 0, num_PlantasMin = 0, i = 0, j = 0, aux1 = 0, aux2 = 0, total_Price = 0;
// Variables int para el ascensor Alpha
int alpha = 0, dist_Alpha = 0, useA = 0, num_PlantasA = 0, countA = 0, countA_Up = 0, countA_Down = 0, resA = 0, precioA = 0;
// Variables int para el ascensor Beta
int beta = 0, dist_Beta = 0, useB = 0, num_PlantasB = 0, countB = 0, countB_Up = 0, countB_Down = 0, resB = 0, precioB = 0;
// Variables int para el ascensor Gamma
int gamma = 0, dist_Gamma = 0, useG = 0, num_PlantasG = 0, countG = 0, countG_Up = 0, countG_Down = 0, resG = 0, precioG = 0;

//Mensaje de Bienvenida
printf("Welcome to our building!\n");

//Función do-while para poder repetir cada vez el mensaje de de bienvenida. La condición es que la variable flag debe ser 1, mientras sea 0 se repetirá
do {
    printf("\nA. Use Elevator | B. Statistics | C. Elevators inspection | Q. Quit\n");
    printf("Enter option: ");
    scanf("%c", &option);
    scanf("%c", &trash);

    //Condicional if para que si la variable opción es Q o q flag sea 1 y salga del bluce do-while principal
    if (option == 'Q' || option == 'q') {
        flag = 1;
    //En esta condición, si la variable es distinta de las letras A, a, B, b, C, c, Q y q se muestre un mensaje de error
    } else if ((option != 'A') && (option != 'a') && (option != 'B') && (option != 'b') && (option != 'C') && (option != 'c')) {
        printf("(ERROR) Invalid option\n");
    }

    //Condicional switch para que el programa realice la opción que ha introducido el usuario
    switch (option) {

        //Primer caso, para poder usar un ascensor
        case 'A':
        case 'a':

            printf("\n");

            //Buscle do-while para pedir el piso donde se encuentra el usuario. Este se repetirá si la variable inicio es distinta de A, G, B, 1, 2, 3, 4 y 5
            do {
                printf("From? ");
                scanf("%c", &inicio);
                scanf("%c", &trash);
            } while ((inicio != 'A') && (inicio != 'G') && (inicio != 'B') && (inicio != '1') && (inicio != '2') && (inicio != '3') && (inicio != '4') && (inicio != '5'));

            //Buscle do-while para pedir el piso a donde quiere ir el usuario. Este se repetirá si la variable final es distinta de A, G, B, 1, 2, 3, 4 y 5
            do {
                printf("To? ");
                scanf("%c", &destino);
                scanf("%c", &trash);
            } while ((destino != 'A') && (destino != 'G') && (destino != 'B') && (destino != '1') && (destino != '2') && (destino != '3') && (destino != '4') && (destino != '5'));

            //Condicional if, si la variable inicio es igual a la variable destino, muestra un error
            if (inicio == destino) {
                printf("(ERROR) Are you joking?\n");
            } else {
                
                //Condicional switch que dependiendo del valor de la variable char inicio, la variable piso1 adquiere el valor int de un piso u otro
                switch (inicio) {

                    case 'B':
                        piso1 = -1;
                    break;

                    case 'G':
                        piso1 = 0;
                    break;

                    case '1':
                        piso1 = 1;
                    break;

                    case '2':
                        piso1 = 2;
                    break;

                    case '3':
                        piso1 = 3;
                    break;

                    case '4':
                        piso1 = 4;
                    break;

                    case '5':
                        piso1 = 5;
                    break;

                    case 'A':
                        piso1 = 6;
                    break;
                }
                
                //Condicional switch que dependiendo del valor de la variable char final, la variable piso2 adquiere el valor int de un piso u otro
                switch (destino) {

                    case 'B':
                        piso2 = -1;
                    break;

                    case 'G':
                        piso2 = 0;
                    break;

                    case '1':
                        piso2 = 1;
                    break;

                    case '2':
                        piso2 = 2;
                    break;

                    case '3':
                        piso2 = 3;
                    break;

                    case '4':
                        piso2 = 4;
                    break;

                    case '5':
                        piso2 = 5;
                    break;

                    case 'A':
                        piso2 = 6;
                    break;
                }

                //Calculamos la distancia de los tres ascensores. Hacemos el valor absoluto del piso donde se encuentra el usuario y el ascensor
                dist_Alpha = fabs(piso1 - alpha);
                dist_Beta = fabs(piso1 - beta);
                dist_Gamma = fabs(piso1 - gamma);

                //Como el ascensor alpha es el que tiene mas prioridad, se pone una variable useA para que por defecto se escoga el ascensor alpha y todos los datos se adapten a alpha
                useA = 1; 
                useB = 0;
                useG = 0;
                distMin = dist_Alpha;
                //Variable auxiliar para no modificar el valor de alpha en el bucle for
                aux1 = alpha;
                num_PlantasMin = num_PlantasA;

                //Condicional if para que si la distancia de beta es menor que la de alpha o la distancia de beta sea igual a la de alpha y las plantas recorridas con carga de beta sean menos que las de alpha, el ascensor beta sea escogido
                if (dist_Alpha > dist_Beta || (dist_Alpha == dist_Beta && num_PlantasB < num_PlantasA)) {
                    useA = 0;
                    useB = 1;
                    useG = 0;
                    distMin = dist_Beta;
                    //Variable auxiliar para no modificar el valor de alpha en el bucle for
                    aux1 = beta;
                    num_PlantasMin = num_PlantasB;
                }
                //Hacemos lo mismo para el ascensor gamma, pero en vez de con alpha lo hacemos con beta, es decir que comparamos beta y gamma
                if (distMin > dist_Gamma || (distMin == dist_Gamma && num_PlantasG < num_PlantasMin)) {
                    useA = 0;
                    useB = 0;
                    useG = 1;
                    distMin = dist_Gamma;
                    //Variable auxiliar para no modificar el valor de alpha en el bucle for
                    aux1 = gamma;
                    num_PlantasMin = num_PlantasG;
                }

                //Si la variable UseA es 1 es porque el ascesor escogio es el alpha
                if (useA == 1) {
                    printf("Elevator Alpha assigned\n");

                    //Contador para contar todas las veces que se ha escogido el ascensor alpha
                    countA++;

                    //Condicional if para que si el piso donde se encuentra el ascensor alpha y el usuario no haga nada y si es distinto haga una serie de calculos
                    if (alpha != piso1) {
                        //Bucle for para poder ir contando piso a piso por los que pasa el ascensor alpha hasta recorrer todas las plantas hasta llegar a donde se encuentra el usuario
                        for (i = 0; i <= distMin; i++) {
                            //Condicional if para ver si el ascensor alpha tiene que subir plantas o bajarlas hasta encontrar el piso del usuario
                            if (aux1 < piso1) {
                                //Condicional if si el piso del ascensor alpha esta por debajo del piso del usuario, cada vez se mira donde esta el ascensor alpha se le suma uno mas para que vaya al siguiente piso
                                if (alpha == -1) {
                                    printf("B");
                                    alpha++;
                                } else if (alpha == 0) {
                                    printf("G");
                                    alpha++;
                                } else if (alpha == 1) {
                                    printf("1");
                                    alpha++;
                                } else if (alpha == 2) {
                                    printf("2");
                                    alpha++;
                                } else if (alpha == 3) {
                                    printf("3");
                                    alpha++;
                                } else if (alpha == 4) {
                                    printf("4");
                                    alpha++;
                                } else if (alpha == 5) {
                                    printf("5");
                                    alpha++;
                                } else if (alpha == 6) {
                                    printf("A");
                                    alpha++;
                                }
                            } else {
                                //Condicional if cuando el piso de alpha esta por encima del piso del usuario y va restando un valor de alpha para poder bajar de piso
                                if (alpha == -1) {
                                    printf("B");
                                    alpha--;
                                } else if (alpha == 0) {
                                    printf("G");
                                    alpha--;
                                } else if (alpha == 1) {
                                    printf("1");
                                    alpha--;
                                } else if (alpha == 2) {
                                    printf("2");
                                    alpha--;
                                } else if (alpha == 3) {
                                    printf("3");
                                    alpha--;
                                } else if (alpha == 4) {
                                    printf("4");
                                    alpha--;
                                } else if (alpha == 5) {
                                    printf("5");
                                    alpha--;
                                } else if (alpha == 6) {
                                    printf("A");
                                    alpha--;
                                }
                            }

                            //Condicional if para que mientras el contador i sea distinto de la variable destino, para poder printar los dos puntos entre cada piso
                            if (i != (distMin)) {
                                printf("..");
                            }
                        }
                        
                        //Condicional if para poder sumar o restar uno a alpha, ya que en el for anterior cuando llega al piso del usuario, vuelve a sumar o restar dependiendo de la condicion
                        if (aux1 < piso1) {
                            alpha--;
                        } else {
                            alpha++;
                        }

                        printf(" ");
                    }

                    //Condicional if para poder determinar si el ascensor tiene que subir o bajar. Para ello miramos si el piso al que quiere llegar el usuario esta por encima o por debajo del piso en el que se encuentra
                    if (piso2 > piso1) {
                        printf("Going up! ");
                        countA_Up++;
                    } else {
                        printf("Going down! ");
                        countA_Down++;
                    }
                    
                    //Creamos una segunda variable auxiliar para alpha por si acaso, de que no se vaya modificando en el bucle
                    aux2 = alpha;
                    distMin2 = fabs(piso2 - aux2);
                    
                    //Bucle for que hace basicamente lo mismo que el otro bucle, hace que el ascensor se mueva hacia el piso destino al que se quiere desplazar el usuario
                    for (j = 0; j <= distMin2; j++) {
                        //Condicional if que determina si el ascensor tiene que subir o bajar, ya que el piso donde se encuentra alpha puede estar por encima o por debajo del piso de destino del usuario
                        if (aux2 < piso2) {
                            //Condicional if para que el programa vaya printando todos los pisos por los que pasa alpha hacia el piso destino, basicamente lo mismo que el anterior
                            if (alpha == -1) {
                                printf("B");
                                alpha++;
                            } else if (alpha == 0) {
                                printf("G");
                                alpha++;
                            } else if (alpha == 1) {
                                printf("1");
                                alpha++;
                            } else if (alpha == 2) {
                                printf("2");
                                alpha++;
                            } else if (alpha == 3) {
                                printf("3");
                                alpha++;
                            } else if (alpha == 4) {
                                printf("4");
                                alpha++;
                            } else if (alpha == 5) {
                                printf("5");
                                alpha++;
                            } else if (alpha == 6) {
                                printf("A");
                                alpha++;
                            }
                        } else {
                            if (alpha == -1) {
                                printf("B");
                                alpha--;
                            } else if (alpha == 0) {
                                printf("G");
                                alpha--;
                            } else if (alpha == 1) {
                                printf("1");
                                alpha--;
                            } else if (alpha == 2) {
                                printf("2");
                                alpha--;
                            } else if (alpha == 3) {
                                printf("3");
                                alpha--;
                            } else if (alpha == 4) {
                                printf("4");
                                alpha--;
                            } else if (alpha == 5) {
                                printf("5");
                                alpha--;
                            } else if (alpha == 6) {
                                printf("A");
                                alpha--;
                            }
                        }

                        //Condicional if para que mientras el contador j sea distinto de la variable destino, para poder printar los dos puntos entre cada piso
                        if (j != distMin2) {
                            printf("..");
                            num_PlantasA++;
                        }
                    }

                    //Condicional if para poder sumar o restar uno a alpha, ya que en el for anterior cuando llega al piso del usuario, vuelve a sumar o restar dependiendo de la condicion
                    if (aux2 < piso2) {
                        alpha--;
                    } else {
                        alpha++;
                    }

                    printf("\n");

                //Aqui hacemos exactamente lo mismo que lo del ascensor alpha, pero para beta. Entra en esta condicion si la variable useB es 1
                } else if (useB == 1) {
                    printf("Elevator Beta assigned\n");

                    countB++;

                    if (beta != piso1) {
                        for (i = 0; i <= distMin; i++) {
                                if (aux1 < piso1) {
                                    if (beta == -1) {
                                        printf("B");
                                        beta++;
                                    } else if (beta == 0) {
                                        printf("G");
                                        beta++;
                                    } else if (beta == 1) {
                                        printf("1");
                                        beta++;
                                    } else if (beta == 2) {
                                        printf("2");
                                        beta++;
                                    } else if (beta == 3) {
                                        printf("3");
                                        beta++;
                                    } else if (beta == 4) {
                                        printf("4");
                                        beta++;
                                    } else if (beta == 5) {
                                        printf("5");
                                        beta++;
                                    } else if (beta == 6) {
                                        printf("A");
                                        beta++;
                                    }
                                } else {
                                    if (beta == -1) {
                                        printf("B");
                                        beta--;
                                    } else if (beta == 0) {
                                        printf("G");
                                        beta--;
                                    } else if (beta == 1) {
                                        printf("1");
                                        beta--;
                                    } else if (beta == 2) {
                                        printf("2");
                                        beta--;
                                    } else if (beta == 3) {
                                        printf("3");
                                        beta--;
                                    } else if (beta == 4) {
                                        printf("4");
                                        beta--;
                                    } else if (beta == 5) {
                                        printf("5");
                                        beta--;
                                    } else if (beta == 6) {
                                        printf("A");
                                        beta--;
                                    }
                                    
                                }

                            if (i != (distMin)) {
                                printf("..");
                            }
                        }
                            
                        if (aux1 < piso1) {
                            beta--;
                        } else {
                            beta++;
                        }
                        
                        printf(" ");
                    }
                        
                    if (piso2 > piso1) {
                        printf("Going up! ");
                        countB_Up++;
                    } else {
                        printf("Going down! ");
                        countB_Down++;
                    }
                    
                    aux2 = beta;
                    distMin2 = fabs(piso2 - aux2);
                    
                        for (j = 0; j <= distMin2; j++) {
                            if (aux2 < piso2) {
                                if (beta == -1) {
                                    printf("B");
                                    beta++;
                                } else if (beta == 0) {
                                    printf("G");
                                    beta++;
                                } else if (beta == 1) {
                                    printf("1");
                                    beta++;
                                } else if (beta == 2) {
                                    printf("2");
                                    beta++;
                                } else if (beta == 3) {
                                    printf("3");
                                    beta++;
                                } else if (beta == 4) {
                                    printf("4");
                                    beta++;
                                } else if (beta == 5) {
                                    printf("5");
                                    beta++;
                                } else if (beta == 6) {
                                    printf("A");
                                    beta++;
                                }
                            } else {
                                if (beta == -1) {
                                    printf("B");
                                    beta--;
                                } else if (beta == 0) {
                                    printf("G");
                                    beta--;
                                } else if (beta == 1) {
                                    printf("1");
                                    beta--;
                                } else if (beta == 2) {
                                    printf("2");
                                    beta--;
                                } else if (beta == 3) {
                                    printf("3");
                                    beta--;
                                } else if (beta == 4) {
                                    printf("4");
                                    beta--;
                                } else if (beta == 5) {
                                    printf("5");
                                    beta--;
                                } else if (beta == 6) {
                                    printf("A");
                                    beta--;
                                }
                            }
                            if (j != distMin2) {
                                printf("..");
                                num_PlantasB++;
                            }
                        }
                        
                        if (aux2 < piso2) {
                            beta--;
                        } else {
                            beta++;
                        }

                    printf("\n");
                
                //Aqui hacemos exactamente lo mismo que lo de los ascensores alpha y beta, pero para gamma. Entra en esta condicion si la variable useG es 1
                }else if(useG == 1){
                    printf("Elevator Gamma assigned\n");

                    countG++;

                    if (gamma != piso1) {
                        for (i = 0; i <= distMin; i++) {
                            if (aux1 < piso1) {
                                if (gamma == -1) {
                                    printf("B");
                                    gamma++;
                                } else if (gamma == 0) {
                                    printf("G");
                                    gamma++;
                                } else if (gamma == 1) {
                                    printf("1");
                                    gamma++;
                                } else if (gamma == 2) {
                                    printf("2");
                                    gamma++;
                                } else if (gamma == 3) {
                                    printf("3");
                                    gamma++;
                                } else if (gamma == 4) {
                                    printf("4");
                                    gamma++;
                                } else if (gamma == 5) {
                                    printf("5");
                                    gamma++;
                                } else if (gamma == 6) {
                                    printf("A");
                                    gamma++;
                                }
                            } else {
                                if (gamma == -1) {
                                    printf("B");
                                    gamma--;
                                } else if (gamma == 0) {
                                    printf("G");
                                    gamma--;
                                } else if (gamma == 1) {
                                    printf("1");
                                    gamma--;
                                } else if (gamma == 2) {
                                    printf("2");
                                    gamma--;
                                } else if (gamma == 3) {
                                    printf("3");
                                    gamma--;
                                } else if (gamma == 4) {
                                    printf("4");
                                    gamma--;
                                } else if (gamma == 5) {
                                    printf("5");
                                    gamma--;
                                } else if (gamma == 6) {
                                    printf("A");
                                    gamma--;
                                }
                            }

                            if (i != (distMin)) {
                                printf("..");
                            }
                        }
                            
                        if (aux1 < piso1) {
                            gamma--;
                        } else {
                            gamma++;
                        }

                        printf(" ");
                    }

                    if (piso2 > piso1) {
                        printf("Going up! ");
                        countG_Up++;
                    } else {
                        printf("Going down! ");
                        countG_Down++;
                    }
                    
                    aux2 = gamma;
                    distMin2 = fabs(piso2 - aux2);
                    
                    for (j = 0; j <= distMin2; j++) {
                        if (aux2 < piso2) {
                            if (gamma == -1) {
                                printf("B");
                                gamma++;
                            } else if (gamma == 0) {
                                printf("G");
                                gamma++;
                            } else if (gamma == 1) {
                                printf("1");
                                gamma++;
                            } else if (gamma == 2) {
                                printf("2");
                                gamma++;
                            } else if (gamma == 3) {
                                printf("3");
                                gamma++;
                            } else if (gamma == 4) {
                                printf("4");
                                gamma++;
                            } else if (gamma == 5) {
                                printf("5");
                                gamma++;
                            } else if (gamma == 6) {
                                printf("A");
                                gamma++;
                            }
                        } else {
                            if (gamma == -1) {
                                printf("B");
                                gamma++;
                            } else if (gamma == 0) {
                                printf("G");
                                gamma--;
                            } else if (gamma == 1) {
                                printf("1");
                                gamma--;
                            } else if (gamma == 2) {
                                printf("2");
                                gamma--;
                            } else if (gamma == 3) {
                                printf("3");
                                gamma--;
                            } else if (gamma == 4) {
                                printf("4");
                                gamma--;
                            } else if (gamma == 5) {
                                printf("5");
                                gamma--;
                            } else if (gamma == 6) {
                                printf("A");
                                gamma--;
                            }
                        }

                        if (j != distMin2) {
                            printf("..");
                            num_PlantasG++;
                        }
                    }
                    
                    if (aux2 < piso2) {
                        gamma--;
                    } else {
                        gamma++;
                    }

                    printf("\n");   
                }
            }
        break;

        //Esta es la segunda opción del programa. Si la variable option es B o b entra aqui y lo que hace basicamente es mostrar las estadisticas de los tres ascensores
        case 'b':
        case 'B':

            printf("\nElevators statistics:\n");

            //Muestra las estadisticas para alpha, beta y gamma. Primero enseña las veces que ha sido usado, las veces que ha subido, que ha bajado y los pisos que ha recorrido
            printf("\n");
            printf("ALPHA: %d rides (%d-%d) and %d floors traveled\n", countA, countA_Up, countA_Down, num_PlantasA);
            printf("BETA: %d rides (%d-%d) and %d floors traveled\n", countB, countB_Up, countB_Down, num_PlantasB);
            printf("GAMMA: %d rides (%d-%d) and %d floors traveled", countG, countG_Up, countG_Down, num_PlantasG);
            printf("\n");

        break;

        //Esta es la tercera opción del programa y entra aquí si la variable option adquiere el valor de C o c. Basicamente calcula si un ascensor necesita ser inspeccionado o no
        case 'c':
        case 'C':

            //Primero miramos si algun ascensor necesita ser inspeccionado
            resA = num_PlantasA / FLOORS_FOR_INSPECTION;
            resB = num_PlantasB / FLOORS_FOR_INSPECTION;
            resG = num_PlantasG / FLOORS_FOR_INSPECTION;

            //Condicional if que si la variable resA, resB o resG vale 1 o mas es que alguna ascensor necesita ser inspeccionado
            if (resA != 0 || resB != 0 || resG != 0) {
                printf("\n");
                //Condicional if que entra si el ascnesor alpha necesita que le hagan una inspección
                if (resA >= 1) {
                    printf("Elevator Alpha: inspection required\n");
                }
                //Condicional if que entra si el ascnesor beta necesita que le hagan una inspección
                if (resB >= 1) {
                    printf("Elevator Beta: inspection required\n");
                }
                //Condicional if que entra si el ascnesor gamma necesita que le hagan una inspección
                if (resG >= 1) {
                    printf("Elevator Gamma: inspection required\n");
                }

                printf("\n");

                //Bucle do-while que pregunta si el usuario quiere hacer las inspecciones que se necesitan. Este se repite hasta que la variable option2 adquiera el valor de Y, y, N y n
                do {
                    printf("Perform inspection? ");
                    scanf("%c", &option2);
                    scanf("%c", &trash);
                } while (option2 != 'Y' && option2 != 'y' && option2 != 'N' && option2 != 'n');

                //Condicional if que si la variable option2 vale Y o y entra aquí e inspecciona los acsensores que necesitan ser inspeccionados
                if (option2 == 'Y' || option2 == 'y') {
                    //Calcula el precio de cada inspección
                    precioA = resA * INSPECTION_PRICE;
                    precioB = resB * INSPECTION_PRICE;
                    precioG = resG * INSPECTION_PRICE;
                    //Condicional if que si el ascensor alpha necesita ser inspeccionado entra aqui, mostrando el mensaje de que ya ha sido inspeccionado con el coste de la inspección
                    if (resA >= 1) {
                        printf("Elevator Alpha inspected! (%d euros)\n", precioA);
                        num_PlantasA = 0;
                    }
                    //Condicional if que si el ascensor beta necesita ser inspeccionado entra aqui, mostrando el mensaje de que ya ha sido inspeccionado con el coste de la inspección
                    if (resB >= 1) {
                        printf("Elevator Beta inspected! (%d euros)\n", precioB);
                        num_PlantasB = 0;
                    }
                    //Condicional if que si el ascensor gamma necesita ser inspeccionado entra aqui, mostrando el mensaje de que ya ha sido inspeccionado con el coste de la inspección
                    if (resG >= 1) {
                        printf("Elevator Gamma inspected! (%d euros)\n", precioG);
                        num_PlantasG = 0;
                    }
                }

                printf("\n");
                //Calcula el precio total de todas las inspecciones hechas hasta el momento
                total_Price = total_Price + precioA + precioB + precioG;
                printf("Accumulated expense: %d euros", total_Price);
                printf("\n");

            //Entra en esta condicion si ningún ascensor necesita ser inspeccionado
            } else {
                printf("No required inspection");
            }

        break;
    }

}while (flag == 0);

//Mensaje de salida que se muestra al abandonar el programa
printf("\nSee you later!");

    return 0;
}