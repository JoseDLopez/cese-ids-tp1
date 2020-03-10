/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdbool.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

typedef struct alumno_s {
    char apellidos[30]; //!< Lastname char definition
    char nombres[30]; //!< first and second names char definition
    char documento[11]; //!< Document definition
} const * alumno_t; //!< Alumn structure mold with features

/*=====[Definitions of public global variables]==============================*/

extern const alumno_t ALUMNOS[]; //!< Alumn array constant definition

extern const int CANTIDAD_ALUMNOS; //!< Alumn quantity constant definition

/*=====[Prototypes (declarations) of public functions]=======================*/

bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno); //!< Public function for serialize unique alumn

bool SerializarAlumnos(char * cadena, size_t espacio, const alumno_t alumnos[], int cantidad); //!< Public function for serialize every alumn.

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _ALUMNOS_H_ */
