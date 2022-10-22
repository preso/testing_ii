*** Settings ***
Library     manana.py

*** Test Cases ***
Dia Valido
  [Documentation]   Tiene que ser 13-10-2022
  ${value} =  Calcula   2022  10  12
  Should Be True  ${value} == 0

Dia Anio Bisiesto
  [Documentation]   Tiene que ser 1-3-2004
  ${value} =  Calcula   2004  02  29
  Should Be True  ${value} == 1

Dia Anio Bisiesto Invalido
  [Documentation]   Invalido por no ser bisiesto
  ${value} =  Calcula   2005  02  29
  Should Be True  ${value} == -5


*** Keywords ***
Calcula 
  [Arguments]   ${a}  ${m}  ${d}
  [Documentation]   Retorna el valor del dia de mañana
  ${value} =  manana  ${a}  ${m}  ${d}
  RETURN  ${value}
  Fail  Algo malo paso
