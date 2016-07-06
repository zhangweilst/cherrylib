#include "typedef_error.h"

typedef struct ref_s ref;

struct ref_s
{
	int a;
	fz_annot* annot;
};

int main()
{
	ref aref;
	aref.a = 1;
	aref.annot = 0;
	return 0;
}
