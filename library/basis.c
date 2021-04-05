#include "basis.h"

//Функция расхода по адиабате
float getMassFlowViaAdiabat(
  float flowRate,
  float csArea,
  float supplyPressure,
  float supplyAirTemperature,
  float currentPressure)
{

  return flowRate * csArea * supplyPressure * sqrt(2 * ADIABAT_PARAMETER / ((ADIABAT_PARAMETER - 1) * UNIVERSAL_GAZ_CONSTANT * supplyAirTemperature)) * getFlow(currentPressure, supplyPressure);
}

float getFlow(float currentPressure, float supplyPressure)
{
  float sigma = _getSigma(currentPressure, supplyPressure);

  return sigma <= GET_FLOW_CHECK_CONSTANT ? GET_FLOW_RETURN_FUNCTION : sqrt(pow(sigma, 2 / ADIABAT_PARAMETER) - pow(sigma, (ADIABAT_PARAMETER + 1) / ADIABAT_PARAMETER));
}

float getMassFlowViaIsoterm(
  float csArea,
  float supplyPressure,
  float supplyAirTemperature,
  float lineResistence,
  float currentPressure)
{
  return (csArea * supplyPressure / sqrt(UNIVERSAL_GAZ_CONSTANT * supplyAirTemperature * lineResistence)) * sqrt(1 - pow(_getSigma(currentPressure, supplyPressure), 2));
}

float getResultLineResistence(E_ARR_FLOAT lineResistencies, E_ARR_FLOAT pipeLengths, float frictionCoefficient, float pipesDiameter)
{
  return 1 + INPUTLINE_RESISTENT_COEFFICIENT + utils_summ_e_int(lineResistencies) + frictionCoefficient * ((utils_summ_e_int(pipeLengths)) / pipesDiameter);
}

//Util functional
float _getSigma(float currentPressure, float supplyPressure)
{
  return currentPressure / supplyPressure;
}
