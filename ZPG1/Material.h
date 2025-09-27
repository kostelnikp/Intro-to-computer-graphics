#pragma once

/*
 * Autor: Peter Kosteln�k
 * Login: KOS0378
 * D�tum: 08. december 2024
 * Projekt: ZPG 2024
 */


class Material
{
private:
	float ra;
	float rd;
	float rs;
public:
	Material(float ra, float rd, float rs);

	float getRa();
	float getRd();
	float getRs();

	void setRa(float ra);
	void setRd(float rd);
	void setRs(float rs);

};

