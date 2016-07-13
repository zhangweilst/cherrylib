/* Demonstrate how C can be object oriented 
 * First, typedef struct
 * Second, function pointer
 */

#include <stdio.h>

typedef double (*volume)(double a, double b);

typedef struct box_s
{
	double length;
	double width;
} box;

typedef struct child_box_s
{
	box data;
	volume box_volume;
} child_box;

double glass_box_volume(double l, double w)
{
	return l * w * 0.85;
}

double wooden_box_volume(double l, double w)
{
	return l * w;
}

int main()
{
	child_box glassbox =
	{
		.data = {10.0, 10.0},
		.box_volume = glass_box_volume
	};
	child_box woodenbox = 
	{
		.data = { 10.0, 10.0 },
		.box_volume = wooden_box_volume
	};

	printf("Volume of glass box: %.2lf\n", glassbox.box_volume(glassbox.data.length, glassbox.data.width));
	printf("Volume of wooden box: %.2lf\n", woodenbox.box_volume(woodenbox.data.length, woodenbox.data.width));
	
	return 0;
}
