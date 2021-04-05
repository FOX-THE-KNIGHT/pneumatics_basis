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

//Util constants
#define GET_FLOW_CHECK_CONSTANT 0.528
#define GET_FLOW_RETURN_FUNCTION 0.259

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

#endif //BASIS_H_
