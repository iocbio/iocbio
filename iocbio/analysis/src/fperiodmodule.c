/* File: fperiodmodule.c
 * This file is auto-generated with f2py (version:2_6882).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Tue Mar 15 13:33:46 2011
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *fperiod_error;
static PyObject *fperiod_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len

#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = fperiod_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern float fperiod(double*,int,int,int,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/********************************** fperiod **********************************/
static char doc_f2py_rout_fperiod_fperiod[] = "\
Function signature:\n\
  y = fperiod(f,[lbound,ubound])\n\
Required arguments:\n"
"  f : input rank-2 array('d') with bounds (n,m)\n"
"Optional arguments:\n"
"  lbound := 1 input int\n"
"  ubound := n-1 input int\n"
"Return objects:\n"
"  y : float";
/* extern float fperiod(double*,int,int,int,int*); */
static PyObject *f2py_rout_fperiod_fperiod(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           float (*f2py_func)(double*,int,int,int,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  float fperiod_return_value=0;
  double *f = NULL;
  npy_intp f_Dims[2] = {-1, -1};
  const int f_Rank = 2;
  PyArrayObject *capi_f_tmp = NULL;
  int capi_f_intent = 0;
  PyObject *f_capi = Py_None;
  int n = 0;
  int m = 0;
  int lbound = 0;
  PyObject *lbound_capi = Py_None;
  int ubound = 0;
  PyObject *ubound_capi = Py_None;
  static char *capi_kwlist[] = {"f","lbound","ubound",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "O|OO:fperiod.fperiod",\
    capi_kwlist,&f_capi,&lbound_capi,&ubound_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable f */
  ;
  capi_f_intent |= F2PY_INTENT_IN|F2PY_INTENT_C;
  capi_f_tmp = array_from_pyobj(PyArray_DOUBLE,f_Dims,f_Rank,capi_f_intent,f_capi);
  if (capi_f_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(fperiod_error,"failed in converting 1st argument `f' of fperiod.fperiod to C/Fortran array" );
  } else {
    f = (double *)(capi_f_tmp->data);

  /* Processing variable lbound */
  if (lbound_capi == Py_None) lbound = 1; else
    f2py_success = int_from_pyobj(&lbound,lbound_capi,"fperiod.fperiod() 1st keyword (lbound) can't be converted to int");
  if (f2py_success) {
  /* Processing variable m */
  m = shape(f,1);
  /* Processing variable n */
  n = shape(f,0);
  /* Processing variable ubound */
  if (ubound_capi == Py_None) ubound = n-1; else
    f2py_success = int_from_pyobj(&ubound,ubound_capi,"fperiod.fperiod() 2nd keyword (ubound) can't be converted to int");
  if (f2py_success) {
/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
  fperiod_return_value = (*f2py_func)(f,n,m,lbound,&ubound);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("f",fperiod_return_value);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  } /*if (f2py_success) of ubound*/
  /* End of cleaning variable ubound */
  /* End of cleaning variable n */
  /* End of cleaning variable m */
  } /*if (f2py_success) of lbound*/
  /* End of cleaning variable lbound */
  if((PyObject *)capi_f_tmp!=f_capi) {
    Py_XDECREF(capi_f_tmp); }
  }  /*if (capi_f_tmp == NULL) ... else of f*/
  /* End of cleaning variable f */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************* end of fperiod *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"fperiod",-1,{{-1}},0,(char *)fperiod,(f2py_init_func)f2py_rout_fperiod_fperiod,doc_f2py_rout_fperiod_fperiod},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "fperiod",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyObject *PyInit_fperiod(void) {
#else
#define RETVAL
PyMODINIT_FUNC initfperiod(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = fperiod_module = PyModule_Create(&moduledef);
#else
  m = fperiod_module = Py_InitModule("fperiod", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module fperiod (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'fperiod' is auto-generated with f2py (version:2_6882).\nFunctions:\n"
"  y = fperiod(f,lbound=1,ubound=n-1)\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  fperiod_error = PyErr_NewException ("fperiod.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));

/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"fperiod");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif