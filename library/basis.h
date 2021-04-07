#ifndef BASIS_H_
#define BASIS_H_

#include "utils.h"

//R
#define UNIVERSAL_GAZ_CONSTANT 287
//T
#define KELVIN_COEFFICIENT 273
//Common air constants
//Показатель адиабаты k
#define ADIABAT_PARAMETER 1.4
//Кинематический коэффициент вязкости
#define KINEMATIC_VISCOSITY 0.0000132
//Динамический коэффициент вязкости
#define DYNAMIC_VISCOSITY 0.00001704
//Удельная массовая изобарная теплоемкость
#define SPECIFIC_ISOBAR_HEAT 1005
//Удельная массовая изохорная теплоемкость
#define SPECIFIC_ISOHOR_HEAT 718
//Постоянная рода газа
#define TEMPERATURE_AIR_CONSTANT 111
//Скорость звука
#define AIR_SPEED 344
//Плотность воздуха
#define AIR_VELOCITY 1.204
//Коэффициент сопротивления входа в линию
#define INPUTLINE_RESISTENT_COEFFICIENT 0.5
//Средний коэффициент трения в трубопроводе
#define AVERAGE_FRICTION_COEFFICIENT 0.3

//Util constants
#define GET_FLOW_CHECK_CONSTANT 0.528
#define GET_FLOW_RETURN_FUNCTION 0.259
//Util - коэффициент пропорциональности при расчете коэффициента трения при ламинарном течении газа
#define FRICTION_PROPORTION_COEFFICIENT 64

//Массовый расход газа в момент адиабатического течения
// flowRate - коэффициент расхода
// csArea - площадь сечения трубопровода
// supplyPressure - давление питания
// supplyAirTemperature - температура газа питания
// currentPressure - текущее давление в подаче
float getMassFlowViaAdiabat(
    float flowRate,
    float csArea,
    float supplyPressure,
    float supplyAirTemperature,
    float currentPressure);
//Расходная функция
// currentPressure - давление текущее
// supplyPressure - давление питания
float getFlow(float currentPressure, float supplyPressure);
//Коэффициент сопротивления линии трубопроводов
//lineResistencies - линейные сопротивления отдельных участков
//pipeLengths - длины отдельных трубопроводов
//frictionCoefficient - коэффициент трения в трубопроводе (выбирается или расчитывается отдельно в зависимости от характера течения воздуха)
//pipesDiameter - диаметр трубопроводов (предполагается, что он будет одинаковым на всех участках)
float getResultLineResistence(E_ARR_FLOAT lineResistencies, E_ARR_FLOAT pipeLengths, float frictionCoefficient, float pipesDiameter);
//Коэффициент трения в трубопроводе при ламилярном течении в трубопроводе
//gasKinematicViscosity - кинематическая вязкость газа
//gasflowRatePipeline - скорость течения газа в трубопроводе
//pipeDiameter - диаметр трубопровода
float getFrictioncoefficient(float gasKinematicViscosity, float gasflowRatePipeline, float pipeDiameter);
//Скорость течения в трубопроводе
//averageSpeedOfPlunger - средняя скорость движения поршня
//plungerDiameter - диаметр поршня
//pipeDiameter - диаметр трубопровода
float getGasflowRatePipeline(float averageSpeedOfPlunger, float plungerDiameter, float pipeDiameter);
//Определение коэффициента сопротивления аппаратуры через заменяющий эквивалентный трубопровод
//frictionCoefficient - коэффициент трения
//equivalentPipeLength - длина эквивалентного трубопровода
//pipeDiameter - диаметр трубопровода
float getEquipmentResistence(float frictionCoefficient, float equivalentPipeLength, float pipeDiameter);

//Расчет расхода в пневматической линии, с разными сечениями
//supplyPressure - давление питания
//supplyAirTemperature - температура газа питания
//effectiveArea -  эффективная площадь
//endPressure - давление на выходе из системы
float getComplexFlow(float supplyPressure, float supplyAirTemperature, float effectiveArea, float endPressure);
//Расчет эффективной площади проходного сечения 
float getEffectiveArea(E_FLOW_SECTOR basicSector, E_FLOW_SECTOR_ARRAY leastSectors); 

#endif //BASIS_H_
