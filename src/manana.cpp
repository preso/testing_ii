#include <stdio.h>

/**
 * @defgroup   Ejemplo calculo del dia mañana curso de testing  
 *
 * @brief      This file implements ejemplo manana.
 *
 * @author     Gustavo Ortiz Uriburu
 * @date       2021-2022
 */
#include <stdio.h>

extern "C" bool treinta (int);
extern "C" bool tntuno (int);
extern "C" bool bsiesto(int);
extern "C" int calculaManana(int, int, int);

/**
 * @brief      funcion que recibe el mes e indica si un mes tiene 30 días,
 *             en caso que se reciba un mes invalido (>12 o < 1) devuelve FALSO
 *
 * @param[in]  mes   mes del cual se quiere indicar si tiene 30 días
 *
 * @return     bool indicando si el mes tiene 30 días
 */
extern "C" bool treinta(int mes) {
    return (mes == 4 || mes == 6 || mes == 9 || mes == 11);
}

/**
 * @brief      funcion que recibe el mes e indica si un mes tiene 31 días
 *
 * @param[in]  mes      del cual se quiere indicar si tiene 31 días
 *
 * @return     bool indicando si el mes tiene 31 dias
 */
extern "C" bool tntuno(int mes) {
    return (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12);
}

/**
 * @brief      funcion que recibe el año e indica si un bisiesto
 *
 * @param[in]  anio     del cual se quiere indicar si es bisiesto
 *
 * @return     bool indicando si el año es bisiesto
 */
extern "C" bool bsiesto(int anio) {
    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

/**
 * @brief      verifica validez del año, mes, dia por separado
 *
 * @param[in]  anio  año ingresado por el usuario
 * @param[in]  mes   mes ingresado por el usuario
 * @param[in]  dia   dia ingresado por el usuario
 *
 * @return     int int indicando el resultado segun la siguiente tabla
 *              0 OK
 *              -1 error de año
 *              -3 error de mes
 *              -5 error de dia
 *              -4 error de año y mes
 *              -6 error de año y dia
 *              -8 error de mes y dia
 *              -9 error en todos
 */
extern "C" int esValido(int anio, int mes, int dia) {
    int res = 0;

    // verifico año identificando
    // si cae en el rango pedido
    if (anio < 1900 || anio > 3000) {
        printf("Debe ingresar un año válido entre 1900 y 3000\n");
        res += -1;
    }
    if (mes < 1 || mes > 12) {
        printf("Debe ingresar un mes válido entre 1 y 12\n");
        res += -3;
    }
    if (tntuno(mes) && (dia < 1 || dia > 31)) {
        printf("Debe ingresar un dia válido entre 1 y 31\n");
        res += -5;
    } else if (treinta(mes) && (dia < 1 || dia > 30)) {
        printf("Debe ingresar un dia válido entre 1 y 30\n");
        res += -5;
    } else if (mes == 2 && bsiesto(anio) && (dia < 1 || dia > 29)) {
        printf("Debe ingresar un dia válido entre 1 y 29\n");
        res += -5;
    } else if (mes == 2 && ! bsiesto(anio) && (dia < 1 || dia > 28)) {
        printf("Debe ingresar un dia válido entre 1 y 28\n");
        res += -5;
    }

    return res;
}

/**
 * @brief      calcula el dia de mañana si el dia ingresado es valido
 *
 * @param[in]  anio  del día para determinar mañana
 * @param[in]  mes   del día para determinar mañana
 * @param[in]  dia   del día para determinar mañana
 *
 * @return     int indicando el resultado segun la siguiente tabla
 *              0 OK
 *              -1 error de año
 *              -3 error de mes
 *              -5 error de dia
 *              -4 error de año y mes
 *              -6 error de año y dia
 *              -8 error de mes y dia
 *              -9 error en todos
 *              
 */
extern "C" int calculaManana(int anio, int mes, int dia) {
    int res = 0;

    // si algo fallo me voy
    if ((res = esValido(anio, mes, dia))) {
        return res;
    }
    // calculo el dia despues
    // hay que verificar si es el ultimo dia del mes
    dia = ((tntuno(mes) && dia == 31) || 
           (treinta(mes) && dia == 30) || 
           (mes == 2 && ((bsiesto(anio) && dia == 29) || dia == 28))) ? 1 : dia + 1;
    mes += (dia == 1) ? 1 : 0; // si dia = 1 se incrementa el mes
    if (mes == 13) { // si mes = 1 se incrementa el año
        anio++;
        mes = 1;
    }
    printf("Mañana es: %d-%d-%d\n", dia, mes, anio);

    return res;
}
