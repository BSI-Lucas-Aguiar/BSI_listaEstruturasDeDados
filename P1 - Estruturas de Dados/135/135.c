#include <stdlib.h>

typedef struct forma{
	float altura, raio;
} area;

area *preenche_cilindro(area *cilindro, float raio, float altura){
	cilindro=(area*)malloc(sizeof(area));
	cilindro->raio=raio;
	cilindro->altura=altura;

	return cilindro;
}


float preenche_area(area *cilindro){
	float area_base, area_lateral, area_total;

	area_base=(3.14*(cilindro->raio*2));
	area_lateral=(2*3.14*cilindro->raio*cilindro->altura);

	area_total=(2*area_base)+area_lateral;

	return area_total;
}

float preenche_volume(area *cilindro){
	float area_base, volume;
	area_base=(3.14*(cilindro->raio*2));

	volume=(area_base*cilindro->altura);

	return volume;
}
