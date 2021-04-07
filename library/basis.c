#include "basis.h"
//Util functional
float getSigma(float currentPressure, float supplyPressure)
{
  return currentPressure / supplyPressure;
}
//Main functionality
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
  float sigma = getSigma(currentPressure, supplyPressure);

  return sigma <= GET_FLOW_CHECK_CONSTANT ? GET_FLOW_RETURN_FUNCTION : sqrt(pow(sigma, 2 / ADIABAT_PARAMETER) - pow(sigma, (ADIABAT_PARAMETER + 1) / ADIABAT_PARAMETER));
}

float getMassFlowViaIsoterm(
  float csArea,
  float supplyPressure,
  float supplyAirTemperature,
  float lineResistence,
  float currentPressure)
{
  return (csArea * supplyPressure / sqrt(UNIVERSAL_GAZ_CONSTANT * supplyAirTemperature * lineResistence)) * sqrt(1 - pow(getSigma(currentPressure, supplyPressure), 2));
}

float getResultLineResistence(E_ARR_FLOAT lineResistencies, E_ARR_FLOAT pipeLengths, float frictionCoefficient, float pipesDiameter)
{
  return 1 + INPUTLINE_RESISTENT_COEFFICIENT + utils_summ_e_float(lineResistencies) + frictionCoefficient * ((utils_summ_e_float(pipeLengths)) / pipesDiameter);
}

float getFrictioncoefficient(float gasKinematicViscosity, float gasflowRatePipeline, float pipeDiameter)
{
  return (FRICTION_PROPORTION_COEFFICIENT * gasKinematicViscosity) / (gasflowRatePipeline * pipeDiameter);
}

float getGasflowRatePipeline(float averageSpeedOfPlunger, float plungerDiameter, float pipeDiameter)
{
  return averageSpeedOfPlunger * (pow(plungerDiameter, 2) / pow(pipeDiameter, 2));
}

float getEquipmentResistence(float frictionCoefficient, float equivalentPipeLength, float pipeDiameter)
{
  return frictionCoefficient * (equivalentPipeLength / pipeDiameter);
}

float getComplexFlow(float supplyPressure, float supplyAirTemperature, float effectiveArea, float endPressure)
{
  return effectiveArea * (supplyPressure / sqrt(UNIVERSAL_GAZ_CONSTANT * supplyAirTemperature)) * sqrt(1 - pow((endPressure / supplyPressure), 2));
}

float getEffectiveArea(E_FLOW_SECTOR basicSector, E_FLOW_SECTOR_ARRAY leastSectors)
{
  float final = basicSector.resistence;
  
  for(int i = 0; i < leastSectors.length; i++)
    final += (leastSectors.sectors + i) -> resistence * pow((leastSectors.sectors + i) -> area / basicSector.area, 2);
  
  return basicSector.area / sqrt(final);
} 
