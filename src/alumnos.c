/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */
 
/*=====[Inclusion of own header]=============================================*/

#include "alumnos.h"
#include <stdio.h>
#include <string.h>

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/
//! Const structure of alumn José López.
/*! More detailed  description. */
static const struct alumno_s JOSE_LOPEZ = {
        .apellidos = "LOPEZ", /*!< lastname value of alumn. */
        .nombres = "José Daniel", /*!< first and second name value of alumn. */
        .documento = "20.010.452", /*!< document value of alumn. */
    }; //!< Create alumn José López following alumn structure

const alumno_t ALUMNOS[] = {
    &JOSE_LOPEZ, /*!< alumn added to array. */
}; //!< const array for alumns and declaration which alumns has inside

const int CANTIDAD_ALUMNOS = (sizeof(ALUMNOS) / sizeof(alumno_t)); //!< Constant alumns quantity creation following size of alumns array

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

/*=====[Implementations of interrupt functions]==============================*/

bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno) {
    /**
     * With the received alumn it returns its properties and creates an string with information
     * in json format.
     * @return return json with information
     */
    int resultado; /*!< declaration of resultado */
    const char FORMATO[] = "{"
        "\"documento\":\"%s\","
        "\"apellidos\":\"%s\","
        "\"nombres\":\"%s\""
    "}"; /*!< Function that gives format to char to return. */

    resultado = snprintf(cadena, espacio, FORMATO, 
             alumno->documento, alumno->apellidos, alumno->nombres); /*!< set resultado value with alumn serialized. */

    return (resultado >= 0); /*!< Return of the size of serialized alumn. */
}

bool SerializarAlumnos(char * cadena, size_t espacio, const alumno_t alumnos[], int cantidad) {
    /**
     * For each alumn it uses SerializarAlumno function to receive json with information and
     * then print each alumn.
     */
    int posicion = snprintf(cadena, espacio, "[\r\n  ");
    bool resultado = (posicion > 0);

    if (resultado){
        for(int indice = 0; indice < cantidad; indice++ ) {
            resultado = SerializarAlumno(&cadena[posicion], espacio - posicion, alumnos[indice]);
            if (resultado) {
                posicion += strlen(&cadena[posicion]);
                posicion += snprintf(&cadena[posicion], espacio - posicion, ",\r\n  ");
            } else {
                break;
            }
        }
    }

    snprintf(&cadena[posicion] - 5, espacio - posicion + 5, "\r\n]");
    return resultado; /*!< return true or false of resultado. */
}

/*=====[Implementations of private functions]================================*/
