/* Simulation code for GeneratorPQ_INIT generated by the OpenModelica Compiler OMCompiler v1.13.2. */
#if !defined(GeneratorPQ_INIT__MODEL_H)
#define GeneratorPQ_INIT__MODEL_H

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_json.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "simulation/solver/model_help.h"
#include "simulation/solver/delay.h"
#include "simulation/solver/linearSystem.h"
#include "simulation/solver/nonlinearSystem.h"
#include "simulation/solver/mixedSystem.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#include "GeneratorPQ_INIT_functions.h"

#define Complex_index 0
#define Complex__omcQuot_2B_index 1
#define Complex__omcQuot_2A_multiply_index 2
#define Complex__omcQuot_2A_scalarProduct_index 3
#define Complex__omcQuot_636F6E7374727563746F72_fromReal_index 4
#define Dynawo_Types_AC_ApparentPower_index 5
#define Dynawo_Types_AC_Current_index 6
#define Dynawo_Types_AC_Voltage_index 7
#define Modelica_ComplexMath_conj_index 8
#define Modelica_ComplexMath_fromPolar_index 9
#define Modelica_Math_cos_index 10
#define Modelica_Math_sin_index 11

extern void GeneratorPQ_INIT_callExternalObjectDestructors(DATA *_data, threadData_t *threadData);
#if !defined(OMC_NUM_NONLINEAR_SYSTEMS) || OMC_NUM_NONLINEAR_SYSTEMS>0
#endif
#if !defined(OMC_NUM_LINEAR_SYSTEMS) || OMC_NUM_LINEAR_SYSTEMS>0
extern void GeneratorPQ_INIT_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA *data);
#endif
#if !defined(OMC_NUM_MIXED_SYSTEMS) || OMC_NUM_MIXED_SYSTEMS>0
#endif
#if !defined(OMC_NO_STATESELECTION)
extern void GeneratorPQ_INIT_initializeStateSets(int nStateSets, STATE_SET_DATA* statesetData, DATA *data);
#endif
extern int GeneratorPQ_INIT_functionAlgebraics(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_function_storeDelayed(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_updateBoundVariableAttributes(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_functionInitialEquations(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_functionRemovedInitialEquations(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_updateBoundParameters(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_checkForAsserts(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_function_ZeroCrossings(DATA *data, threadData_t *threadData, double* gout);
extern int GeneratorPQ_INIT_function_updateRelations(DATA *data, threadData_t *threadData, int evalZeroCross);
extern const char* GeneratorPQ_INIT_zeroCrossingDescription(int i, int **out_EquationIndexes);
extern const char* GeneratorPQ_INIT_relationDescription(int i);
extern void GeneratorPQ_INIT_function_initSample(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_initialAnalyticJacobianG(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int GeneratorPQ_INIT_initialAnalyticJacobianA(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int GeneratorPQ_INIT_initialAnalyticJacobianB(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int GeneratorPQ_INIT_initialAnalyticJacobianC(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int GeneratorPQ_INIT_initialAnalyticJacobianD(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);
extern int GeneratorPQ_INIT_functionJacG_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int GeneratorPQ_INIT_functionJacA_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int GeneratorPQ_INIT_functionJacB_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int GeneratorPQ_INIT_functionJacC_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern int GeneratorPQ_INIT_functionJacD_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
extern const char* GeneratorPQ_INIT_linear_model_frame(void);
extern const char* GeneratorPQ_INIT_linear_model_datarecovery_frame(void);
extern int GeneratorPQ_INIT_mayer(DATA* data, modelica_real** res, short *);
extern int GeneratorPQ_INIT_lagrange(DATA* data, modelica_real** res, short *, short *);
extern int GeneratorPQ_INIT_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
extern int GeneratorPQ_INIT_setInputData(DATA *data, const modelica_boolean file);
extern int GeneratorPQ_INIT_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
extern void GeneratorPQ_INIT_function_initSynchronous(DATA * data, threadData_t *threadData);
extern void GeneratorPQ_INIT_function_updateSynchronous(DATA * data, threadData_t *threadData, long i);
extern int GeneratorPQ_INIT_function_equationsSynchronous(DATA * data, threadData_t *threadData, long i);
extern void GeneratorPQ_INIT_read_input_fmu(MODEL_DATA* modelData, SIMULATION_INFO* simulationData);
extern void GeneratorPQ_INIT_function_savePreSynchronous(DATA *data, threadData_t *threadData);
extern int GeneratorPQ_INIT_inputNames(DATA* data, char ** names);
extern int GeneratorPQ_INIT_initializeDAEmodeData(DATA *data, DAEMODE_DATA*);
extern int GeneratorPQ_INIT_functionLocalKnownVars(DATA*, threadData_t*);
extern int GeneratorPQ_INIT_symbolicInlineSystem(DATA*, threadData_t*);

#include "GeneratorPQ_INIT_literals.h"




#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#if defined(__cplusplus)
}
#endif

#endif /* !defined(GeneratorPQ_INIT__MODEL_H) */


