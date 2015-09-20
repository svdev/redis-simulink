#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME REDIS

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

#define NUM_INPUTS          1
/* Input Port  0 */
#define IN_PORT_0_NAME      input
#define INPUT_0_WIDTH       1
#define INPUT_DIMS_0_COL    1
#define INPUT_0_DTYPE       uint8_T
#define INPUT_0_COMPLEX     COMPLEX_NO
#define IN_0_FRAME_BASED    FRAME_NO
#define IN_0_BUS_BASED      0
#define IN_0_BUS_NAME       
#define IN_0_DIMS           1-D
#define INPUT_0_FEEDTHROUGH 1
#define IN_0_ISSIGNED        0
#define IN_0_WORDLENGTH      8
#define IN_0_FIXPOINTSCALING 1
#define IN_0_FRACTIONLENGTH  9
#define IN_0_BIAS            0
#define IN_0_SLOPE           0.125

#define NUM_OUTPUTS          5

/* Output Port  0 */
// FUNCTION CALL TRIGGER

/* Output Port  1 */
#define OUT_PORT_1_NAME      data
#define OUTPUT_1_WIDTH       1
#define OUTPUT_DIMS_1_COL    1
#define OUTPUT_1_DTYPE       uint8_T
#define OUTPUT_1_COMPLEX     COMPLEX_NO
#define OUT_1_FRAME_BASED    FRAME_NO
#define OUT_1_BUS_BASED      0
#define OUT_1_BUS_NAME       
#define OUT_1_DIMS           1-D
#define OUT_1_ISSIGNED        1
#define OUT_1_WORDLENGTH      8
#define OUT_1_FIXPOINTSCALING 1
#define OUT_1_FRACTIONLENGTH  3
#define OUT_1_BIAS            0
#define OUT_1_SLOPE           0.125


/* Output Port  2 */
/* Redis Status codes
    REDIS_ERR -1
    REDIS_OK 0
    REDIS_ERR_IO 1 
    REDIS_ERR_OTHER 2
    REDIS_ERR_EOF 3
    REDIS_ERR_PROTOCOL 4 
    REDIS_ERR_OOM 5
 */
#define OUT_PORT_2_NAME      status
#define OUTPUT_2_WIDTH       1
#define OUTPUT_DIMS_2_COL    1
#define OUTPUT_2_DTYPE       int32_T
#define OUTPUT_2_COMPLEX     COMPLEX_NO
#define OUT_2_FRAME_BASED    FRAME_NO
#define OUT_2_BUS_BASED      0
#define OUT_2_BUS_NAME       
#define OUT_2_DIMS           1-D
#define OUT_2_ISSIGNED        0
#define OUT_2_WORDLENGTH      8
#define OUT_2_FIXPOINTSCALING 1
#define OUT_2_FRACTIONLENGTH  3
#define OUT_2_BIAS            0
#define OUT_2_SLOPE           0.125

/* Output Port  3 */
/* Redis Reply type Codes  
    REDIS_REPLY_STRING 1
    REDIS_REPLY_ARRAY 2
    REDIS_REPLY_INTEGER 3
    REDIS_REPLY_NIL 4
    REDIS_REPLY_STATUS 5
    REDIS_REPLY_ERROR 6 
 */
#define OUT_PORT_3_NAME      replyType
#define OUTPUT_3_WIDTH       1
#define OUTPUT_DIMS_3_COL    1
#define OUTPUT_3_DTYPE       uint8_T
#define OUTPUT_3_COMPLEX     COMPLEX_NO
#define OUT_3_FRAME_BASED    FRAME_NO
#define OUT_3_BUS_BASED      0
#define OUT_3_BUS_NAME       
#define OUT_3_DIMS           1-D
#define OUT_3_ISSIGNED        0
#define OUT_3_WORDLENGTH      8
#define OUT_3_FIXPOINTSCALING 1
#define OUT_3_FRACTIONLENGTH  3
#define OUT_3_BIAS            0
#define OUT_3_SLOPE           0.125

/* Output Port  4 */
/* Redis Reply number of elements counter */
#define OUT_PORT_4_NAME      num
#define OUTPUT_4_WIDTH       1
#define OUTPUT_DIMS_4_COL    1
#define OUTPUT_4_DTYPE       uint32_T
#define OUTPUT_4_COMPLEX     COMPLEX_NO
#define OUT_4_FRAME_BASED    FRAME_NO
#define OUT_4_BUS_BASED      0
#define OUT_4_BUS_NAME       
#define OUT_4_DIMS           1-D
#define OUT_4_ISSIGNED        0
#define OUT_4_WORDLENGTH      8
#define OUT_4_FIXPOINTSCALING 1
#define OUT_4_FRACTIONLENGTH  3
#define OUT_4_BIAS            0
#define OUT_4_SLOPE           0.125


#define NPARAMS              2
/* Parameter  1 */
#define PARAMETER_0_NAME      hostname
#define PARAMETER_0_DTYPE     uint8_T
#define PARAMETER_0_COMPLEX   COMPLEX_NO
/* Parameter  2 */
#define PARAMETER_1_NAME      port
#define PARAMETER_1_DTYPE     uint8_T
#define PARAMETER_1_COMPLEX   COMPLEX_NO

#define SAMPLE_TIME_0        -1
#define NUM_DISC_STATES      0
#define DISC_STATES_IC       [0]
#define NUM_CONT_STATES      0
#define CONT_STATES_IC       [0]

#define SFUNWIZ_GENERATE_TLC 0
#define SOURCEFILES "__SFB__"
#define PANELINDEX           6
#define USE_SIMSTRUCT        1
#define SHOW_COMPILE_STEPS   0                   
#define CREATE_DEBUG_MEXFILE 0
#define SAVE_CODE_ONLY       0
#define SFUNWIZ_REVISION     3.0

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

#define REDIS_INCLUDED_CUSTOM 1
#include "simstruc.h"
//#include "mex.h"
#include "REDIS_custom.h"

#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)

#define IS_PARAM_UINT8(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsUint8(pVal))

extern void REDIS_Outputs_wrapper(void *S,
                          redisContext *c,
                          const uint8_T *input,
                          uint8_T *data ,                           
                          int32_T *status,
                          uint8_T *replyType,
                          uint32_T *numElements,
                          uint32_T data_width,
                          int_T tid);



#define MDL_CHECK_PARAMETERS
 #if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
    static void mdlCheckParameters(SimStruct *S)
    {
     int paramIndex  = 0;
     bool validParam = false;
     
	 {
	  const mxArray *pVal0 = ssGetSFcnParam(S,0);
	  if (!IS_PARAM_UINT8(pVal0)) {
	    validParam = true;
	    paramIndex = 0;
	    goto EXIT_POINT;
	  }
	 }

	 {
	  const mxArray *pVal1 = ssGetSFcnParam(S,1);
	  if (!IS_PARAM_UINT8(pVal1)) {
	    validParam = true;
	    paramIndex = 1;
	    goto EXIT_POINT;
	  }
	 }
      
     EXIT_POINT:
      if (validParam) {
          char parameterErrorMsg[1024];
          sprintf(parameterErrorMsg, "The data type and or complexity of parameter  %d does not match the "
                  "information specified in the S-function Builder dialog. "
                  "For non-double parameters you will need to cast them using int8, int16, "
                  "int32, uint8, uint16, uint32 or boolean.", paramIndex + 1);
	  ssSetErrorStatus(S,parameterErrorMsg);
      }
	return;
    }
 #endif 
static void mdlInitializeSizes(SimStruct *S)
{

    
    
    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS);  /* Number of expected parameters */
      #if defined(MATLAB_MEX_FILE)
	if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
	  mdlCheckParameters(S);
	  if (ssGetErrorStatus(S) != NULL) {
	    return;
	  }
	 } else {
	   return; /* Parameter mismatch will be reported by Simulink */
	 }
      #endif

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);

    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;
    
    if (!ssSetInputPortDimensionInfo(S, 0, DYNAMIC_DIMENSION)) return; // Input port 1 size is dynamic
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    _ssSetInputPortNumDimensions(S, 0, 1);  // 1 dimensional input 
    ssSetInputPortRequiredContiguous(S, 0, true); 
    ssSetInputPortDataType(S,0,SS_UINT8);
    ssSetInputPortDimensionsMode(S, 0, VARIABLE_DIMS_MODE);      
        
    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;  
    ssSetOutputPortDataType(S,0,SS_FCN_CALL);
    ssSetOutputPortWidth(S, 0, 2);
    
    if (!ssSetOutputPortDimensionInfo(S, 1, DYNAMIC_DIMENSION)) return; // Output port 1 size is dynamic
    _ssSetOutputPortNumDimensions(S, 1, 1);    
    ssSetOutputPortDataType(S,1,SS_UINT8);
    
    ssSetOutputPortDimensionsMode(S, 1, FIXED_DIMS_MODE);
 
    // OUTPUT 2 (STATUS)
    ssSetOutputPortDataType(S, 2, SS_INT32);   
    ssSetOutputPortWidth(S, 2, OUTPUT_2_WIDTH);
    ssSetOutputPortComplexSignal(S, 2, OUTPUT_2_COMPLEX);
    ssSetBusOutputAsStruct(S, 2, OUT_2_BUS_BASED);    
        
    // OUTPUT 3 (REPLY TYPE)
    ssSetOutputPortDataType(S, 3, SS_UINT8);   
    ssSetOutputPortWidth(S, 3, OUTPUT_3_WIDTH);
    ssSetOutputPortComplexSignal(S, 3, OUTPUT_3_COMPLEX);
    ssSetBusOutputAsStruct(S, 3, OUT_3_BUS_BASED);   
        
    // OUTPUT 4 (NUM ELEMENTS)
    ssSetOutputPortDataType(S, 4, SS_UINT32);   
    ssSetOutputPortWidth(S, 4, OUTPUT_4_WIDTH);
    ssSetOutputPortComplexSignal(S, 4, OUTPUT_4_COMPLEX);
    ssSetBusOutputAsStruct(S, 4, OUT_4_BUS_BASED);             
    
    
    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 1);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
		     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

# define MDL_SET_INPUT_PORT_FRAME_DATA
static void mdlSetInputPortFrameData(SimStruct  *S, 
                                     int_T      port,
                                     Frame_T    frameData)
{
    ssSetInputPortFrameData(S, port, frameData);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME_0);
    ssSetOffsetTime(S, 0, 0.0);
    
    ssSetExplicitFCSSCtrl(S,0);    
    
    ssSetCallSystemOutput(S,0);  /* call on first element: RECEIVED */    
    ssSetCallSystemOutput(S,1);  /* call on second element: FINISHED */    
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
}


#define MDL_START 
#if defined(MDL_START)
static void mdlStart(SimStruct *S)
{
  
    // Get host/port parameters
    const char *host  = (const char *)mxGetData(PARAM_DEF0(S));
    const char *port  = (const char *)mxGetData(PARAM_DEF1(S));
        
    // Connect to redis
    redisContext *c = REDIS_connectRedis(host, atoi(port));
    
    // Store redis context in pointer-work vector
    // void **PWork = ssGetPWork(S);
    // PWork[0] = (void **)&c;
    
    // Another way to set it up
    ssSetPWorkValue(S,0,(void *)c);
    
    mexPrintf("Redis Server: %s:%s\n",host,port);           

}
#endif /*  MDL_START */



#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetInputPortDataType( S, 0, dType);
}
#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
  
  ssSetInputPortDataType (S, 0, SS_UINT8);
  
  ssSetOutputPortDataType(S, 0, SS_FCN_CALL);  
  ssSetOutputPortDataType(S, 1, SS_UINT8);
  ssSetOutputPortDataType(S, 2, SS_INT32);
  ssSetOutputPortDataType(S, 3, SS_UINT8);
  ssSetOutputPortDataType(S, 4, SS_INT32);

}
/* Function: mdlOutputs =======================================================
 *
*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const uint8_T   *input  = (const uint8_T*) ssGetInputPortSignal(S,0);
    uint8_T         *data  = (uint8_T *)ssGetOutputPortSignal(S,1);        
    int32_T         *status  = (int32_T *)ssGetOutputPortRealSignal(S,2);
    uint8_T         *replyType  = (uint8_T *)ssGetOutputPortRealSignal(S,3);
    uint32_T        *numElements  = (uint32_T *)ssGetOutputPortRealSignal(S,4);    
    
    int32_T         data_width = ssGetOutputPortWidth(S, 1);    
    // Get length of block parameters
    //const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    //const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    //const uint8_T  *hostname  = (const uint8_T *)mxGetData(PARAM_DEF0(S));
    //const uint8_T  *port  = (const uint8_T *)mxGetData(PARAM_DEF1(S));
    
    redisContext *c = (redisContext *) ssGetPWorkValue(S,0);
    
    REDIS_Outputs_wrapper((void *)S, c, input, data, status, replyType, numElements, data_width, tid);
    
}

/*
 * The following function is for setting up the variable sized input port widths
 */
#if defined(MATLAB_MEX_FILE)
#define MDL_SET_INPUT_PORT_WIDTH
static void mdlSetInputPortWidth(SimStruct *S, int_T port, int_T width)
{
    ssSetInputPortWidth(S, port, width);
    ssSetOutputPortWidth(S, 1, width);    
}

#define MDL_UPDATE 
#if defined(MDL_UPDATE) && defined(MATLAB_MEX_FILE) 
static void mdlUpdate(SimStruct *S, int_T tid) 
{ 
   /* Add mdlUpdate code here to run between steps after mdlOutputs() */
} 
#endif 


/*
 * The following function is for setting up the variable sized output port widths
 */

#define MDL_SET_OUTPUT_PORT_WIDTH
static void mdlSetOutputPortWidth(SimStruct *S, int_T port, int_T width)
{
    UNUSED_ARG(S);
    UNUSED_ARG(port);
    UNUSED_ARG(width);
    return;
}
#endif

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
           
    void **PWork = ssGetPWork(S);        
    redisContext *c = (redisContext *)PWork[0];                
    
    REDIS_redis_disconnect(c);
    
    // Set redis context to null
    //ssSetPWorkValue(S,0,(void *)c);    
    
}
#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


