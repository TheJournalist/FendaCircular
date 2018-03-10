// DifracaoCircular.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define PI 3.14159265358979323846

int main()
{
	double lambda = 0.005; // 500 nm
	double D = 0.005; // 5mm

	int width = 980;
	int height = 980;
	ALLEGRO_DISPLAY *display = NULL;
	al_init();
	al_init_primitives_addon();
	display = al_create_display(height, width);
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	al_draw_line(0, height - 10, width, height - 10, al_map_rgb(255, 255, 255), 1);
	
	double kdsintheta, I;
	float t = 0;
	/*
	for (double theta = 0; theta < (100.0 * PI); theta += 0.01)
	{
		kdsintheta = (((double)(2 * PI) / (lambda)) * D * sin(theta));
		I = pow((2.0 * _j1(kdsintheta)) / kdsintheta, 2.0);
		al_draw_circle(width / 2, height / 2, theta, al_map_rgb(255, 255, 255), I);
		al_draw_pixel(t++, height-I * 100 - 10, al_map_rgb(255, 255, 255));
		printf("theta = %f     I(theta) = %f\n", theta, I);
		//al_rest(0.01);
		al_flip_display();
	}*/

	for (double x = 0; x < 35; x += 0.001)
	{
		I = pow((2.0 * _j1(x)) / x, 2.0);
		al_draw_circle(width / 2, height / 2, 20*x, al_map_rgb(255, 255, 255), I);
		al_draw_pixel((int)t, height - I * 1000 - 10, al_map_rgb(255, 255, 255));
		t += 0.05;
		printf("x = %f    I(x) = %f\n", x, I);
		//al_rest(0.01);
		al_flip_display();
	}
	
	getchar();
    return 0;
}

