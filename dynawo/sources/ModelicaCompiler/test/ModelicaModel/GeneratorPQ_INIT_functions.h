#ifndef GeneratorPQ_INIT__H
#define GeneratorPQ_INIT__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Complex_s {
  modelica_real _im;
  modelica_real _re;
} Complex;
typedef base_array_t Complex_array;
extern struct record_description Complex__desc;

typedef Complex Dynawo_Types_AC_ApparentPower;
typedef base_array_t Dynawo_Types_AC_ApparentPower_array;
extern struct record_description Dynawo_Types_AC_ApparentPower__desc;

typedef Complex Dynawo_Types_AC_Current;
typedef base_array_t Dynawo_Types_AC_Current_array;
extern struct record_description Dynawo_Types_AC_Current__desc;

typedef Complex Dynawo_Types_AC_Voltage;
typedef base_array_t Dynawo_Types_AC_Voltage_array;
extern struct record_description Dynawo_Types_AC_Voltage__desc;

DLLExport
Complex omc_Complex (threadData_t *threadData, modelica_real omc_re, modelica_real omc_im);

DLLExport
modelica_metatype boxptr_Complex(threadData_t *threadData, modelica_metatype _re, modelica_metatype _im);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Complex,2,0) {(void*) boxptr_Complex,0}};
#define boxvar_Complex MMC_REFSTRUCTLIT(boxvar_lit_Complex)


DLLExport
Complex omc_Complex__omcQuot_2B(threadData_t *threadData, Complex _c1, Complex _c2);
DLLExport
modelica_metatype boxptr_Complex__omcQuot_2B(threadData_t *threadData, modelica_metatype _c1, modelica_metatype _c2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Complex__omcQuot_2B,2,0) {(void*) boxptr_Complex__omcQuot_2B,0}};
#define boxvar_Complex__omcQuot_2B MMC_REFSTRUCTLIT(boxvar_lit_Complex__omcQuot_2B)


DLLExport
Complex omc_Complex__omcQuot_2A_multiply(threadData_t *threadData, Complex _c1, Complex _c2);
DLLExport
modelica_metatype boxptr_Complex__omcQuot_2A_multiply(threadData_t *threadData, modelica_metatype _c1, modelica_metatype _c2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Complex__omcQuot_2A_multiply,2,0) {(void*) boxptr_Complex__omcQuot_2A_multiply,0}};
#define boxvar_Complex__omcQuot_2A_multiply MMC_REFSTRUCTLIT(boxvar_lit_Complex__omcQuot_2A_multiply)


DLLExport
Complex omc_Complex__omcQuot_2A_scalarProduct(threadData_t *threadData, Complex_array _c1, Complex_array _c2);
DLLExport
modelica_metatype boxptr_Complex__omcQuot_2A_scalarProduct(threadData_t *threadData, modelica_metatype _c1, modelica_metatype _c2);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Complex__omcQuot_2A_scalarProduct,2,0) {(void*) boxptr_Complex__omcQuot_2A_scalarProduct,0}};
#define boxvar_Complex__omcQuot_2A_scalarProduct MMC_REFSTRUCTLIT(boxvar_lit_Complex__omcQuot_2A_scalarProduct)


DLLExport
Complex omc_Complex__omcQuot_636F6E7374727563746F72_fromReal(threadData_t *threadData, modelica_real _re, modelica_real _im);
DLLExport
modelica_metatype boxptr_Complex__omcQuot_636F6E7374727563746F72_fromReal(threadData_t *threadData, modelica_metatype _re, modelica_metatype _im);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Complex__omcQuot_636F6E7374727563746F72_fromReal,2,0) {(void*) boxptr_Complex__omcQuot_636F6E7374727563746F72_fromReal,0}};
#define boxvar_Complex__omcQuot_636F6E7374727563746F72_fromReal MMC_REFSTRUCTLIT(boxvar_lit_Complex__omcQuot_636F6E7374727563746F72_fromReal)


DLLExport
Dynawo_Types_AC_ApparentPower omc_Dynawo_Types_AC_ApparentPower (threadData_t *threadData, modelica_real omc_re, modelica_real omc_im);

DLLExport
modelica_metatype boxptr_Dynawo_Types_AC_ApparentPower(threadData_t *threadData, modelica_metatype _re, modelica_metatype _im);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Dynawo_Types_AC_ApparentPower,2,0) {(void*) boxptr_Dynawo_Types_AC_ApparentPower,0}};
#define boxvar_Dynawo_Types_AC_ApparentPower MMC_REFSTRUCTLIT(boxvar_lit_Dynawo_Types_AC_ApparentPower)


DLLExport
Dynawo_Types_AC_Current omc_Dynawo_Types_AC_Current (threadData_t *threadData, modelica_real omc_re, modelica_real omc_im);

DLLExport
modelica_metatype boxptr_Dynawo_Types_AC_Current(threadData_t *threadData, modelica_metatype _re, modelica_metatype _im);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Dynawo_Types_AC_Current,2,0) {(void*) boxptr_Dynawo_Types_AC_Current,0}};
#define boxvar_Dynawo_Types_AC_Current MMC_REFSTRUCTLIT(boxvar_lit_Dynawo_Types_AC_Current)


DLLExport
Dynawo_Types_AC_Voltage omc_Dynawo_Types_AC_Voltage (threadData_t *threadData, modelica_real omc_re, modelica_real omc_im);

DLLExport
modelica_metatype boxptr_Dynawo_Types_AC_Voltage(threadData_t *threadData, modelica_metatype _re, modelica_metatype _im);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Dynawo_Types_AC_Voltage,2,0) {(void*) boxptr_Dynawo_Types_AC_Voltage,0}};
#define boxvar_Dynawo_Types_AC_Voltage MMC_REFSTRUCTLIT(boxvar_lit_Dynawo_Types_AC_Voltage)


DLLExport
Complex omc_Modelica_ComplexMath_conj(threadData_t *threadData, Complex _c1);
DLLExport
modelica_metatype boxptr_Modelica_ComplexMath_conj(threadData_t *threadData, modelica_metatype _c1);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_ComplexMath_conj,2,0) {(void*) boxptr_Modelica_ComplexMath_conj,0}};
#define boxvar_Modelica_ComplexMath_conj MMC_REFSTRUCTLIT(boxvar_lit_Modelica_ComplexMath_conj)


DLLExport
Complex omc_Modelica_ComplexMath_fromPolar(threadData_t *threadData, modelica_real _len, modelica_real _phi);
DLLExport
modelica_metatype boxptr_Modelica_ComplexMath_fromPolar(threadData_t *threadData, modelica_metatype _len, modelica_metatype _phi);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_ComplexMath_fromPolar,2,0) {(void*) boxptr_Modelica_ComplexMath_fromPolar,0}};
#define boxvar_Modelica_ComplexMath_fromPolar MMC_REFSTRUCTLIT(boxvar_lit_Modelica_ComplexMath_fromPolar)


DLLExport
modelica_real omc_Modelica_Math_cos(threadData_t *threadData, modelica_real _u);
DLLExport
modelica_metatype boxptr_Modelica_Math_cos(threadData_t *threadData, modelica_metatype _u);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_cos,2,0) {(void*) boxptr_Modelica_Math_cos,0}};
#define boxvar_Modelica_Math_cos MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_cos)

/*
 * The function has annotation(Include=...>) or is builtin
 * the external function definition should be present
 * in one of these files and have this prototype:
 * extern double cos(double (*_u*));
 */


DLLExport
modelica_real omc_Modelica_Math_sin(threadData_t *threadData, modelica_real _u);
DLLExport
modelica_metatype boxptr_Modelica_Math_sin(threadData_t *threadData, modelica_metatype _u);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_sin,2,0) {(void*) boxptr_Modelica_Math_sin,0}};
#define boxvar_Modelica_Math_sin MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_sin)

/*
 * The function has annotation(Include=...>) or is builtin
 * the external function definition should be present
 * in one of these files and have this prototype:
 * extern double sin(double (*_u*));
 */
#include "GeneratorPQ_INIT_model.h"


#ifdef __cplusplus
}
#endif
#endif

