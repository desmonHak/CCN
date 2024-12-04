#ifndef CCN_CORE_C
#define CCN_CORE_C

#include "../include/core.h"


/*
 * No usamos simplemente un const char* normal para la cadena de documentación 
 * porque CPython se puede compilar para que no incluya cadenas de documentación. 
 * Esto es útil en plataformas con menos RAM disponible. Para respetar adecuadamente 
 * esta opción de tiempo de compilación, envolvemos todas las cadenas de documentación 
 * en la macro PyDoc_STRVAR().
 */
PyDoc_STRVAR(CCN_doc, "Func method_SetProcessAffinityMask");
PyDoc_STRVAR(CCN_lib_module_doc, "Modulo CCN");


static PyObject *method_SetProcessAffinityMask(PyObject *self, PyObject *args) {
    /*
     * La función C siempre tiene dos argumentos, llamados convencionalmente self y args.
     * El argumento self apunta al objeto del módulo para funciones a nivel de módulo; para un método 
     * apuntaría a la instancia del objeto. El argumento args será un puntero a un objeto de 
     * tupla de Python que contiene los argumentos.
     */

    /* Parse arguments 
     * La función PyArg_ParseTuple() en la API de Python verifica los tipos de argumento y los convierte a valores C.
     */

    long int mask_affinity = 0;

    // https://www.mit.edu/people/amliu/vrut/python/ext/parseTuple.html
    if(!PyArg_ParseTuple(args, "l", &mask_affinity)) {
        return NULL;
    }


    return PyLong_FromLong(mask_affinity);
}
/*
 * Funciones del modulo con sus metadatos
 */
static PyMethodDef CCN_lib_native_methods[] = {
    {
        "CCN", 
        (PyCFunction)method_SetProcessAffinityMask, 
        METH_VARARGS, 
        CCN_doc
    },
    {NULL, NULL, 0, NULL}
};

/*
 *
 * Metadatos del modulo
 * 
 */
static struct PyModuleDef CCN_lib_native = {
    PyModuleDef_HEAD_INIT,
    "CCN",
    CCN_lib_module_doc,
    -1,
    CCN_lib_native_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

/*
 *
 * Funcion inicializadora del modulo:
 * Una vez que definimos nuestra función y nuestro módulo, debemos indicarle a CPython cómo importar nuestro módulo. 
 * Para ello, debemos definir una única función con el tipo PyMODINIT_FUNC denominada PyInit_{name}, donde name es el 
 * nombre de nuestro módulo.
 * Esta función se ejecutará la primera vez que alguien escriba import fib.fib from python. Esto 
 * se puede considerar como el código que se ejecuta en el "ámbito del módulo" en un archivo Python normal. 
 * Al final de nuestra función, debemos devolver el módulo recién creado. Para crear un PyObject* a 
 * partir de un PyModule_Def, podemos usar PyModule_Create().
 * 
 */
PyMODINIT_FUNC PyInit_CCN_lib(void) {
    _ACTIVATE_COLORS_ANSI_WIN__();
    debug_print_ccn("init module");

    /* Assign module value */
    PyObject *module = PyModule_Create(&CCN_lib_native);
    if (module == NULL) return NULL;


    return module; // retornar el modulo creado.
}
#endif