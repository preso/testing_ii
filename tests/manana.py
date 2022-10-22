import numpy
import ctypes

# el path /opt/robotframework/tests es el que utiliza el docker
_libmanana = numpy.ctypeslib.load_library('libmanana', '/opt/robotframework/tests')

_libmanana.calculaManana.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
_libmanana.calculaManana.restype  =  ctypes.c_int

_libmanana.treinta.argtypes = [ctypes.c_int]
_libmanana.treinta.restype  =  ctypes.c_bool

_libmanana.tntuno.argtypes = [ctypes.c_int]
_libmanana.tntuno.restype  =  ctypes.c_bool

_libmanana.bsiesto.argtypes = [ctypes.c_int]
_libmanana.bsiesto.restype  =  ctypes.c_bool

def manana(anio, mes, dia):
    return _libmanana.calculaManana(int(anio), int(mes), int(dia))

def treinta(mes):
    return _libmanana.treinta(int(mes))

def tntuno(mes):
    return _libmanana.tntuno(int(mes))

def bsiesto(mes):
    return _libmanana.bsiesto(int(mes))
