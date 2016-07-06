// This can decode base64 to binay format file(eg. jpeg file)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int index[] =
{
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
	-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
	-1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

int main()
{
	FILE* fp;
	fp = fopen("test.jpg", "wb");

	freopen("data.base64", "r", stdin);

	char* in;
	in = (char*)malloc(4 * sizeof(char));
	int len = 0, cap = 4;
	char temp;

	while (~scanf("%c", &temp))
	{
		if (index[temp] == -1 && temp != '=')
			continue;
		if (len == cap)
		{
			in = (char*)realloc(in, cap * 2);
			cap = cap * 2;
		}
		in[len++] = temp;
	}

	if (len % 4 != 0)
		return 1;

	char a, b, c, d;
	char out[3];
	for(int i = 0; i < len / 4 - 1; ++i)
	{
		a = index[in[i * 4]];
		b = index[in[i * 4 + 1]];
		c = index[in[i * 4 + 2]];
		d = index[in[i * 4 + 3]];
		out[0] = (a << 2) | ((b >> 4) & 0x3);
		out[1] = ((b & 0xF) << 4) | ((c >> 2) & 0xF);
		out[2] = (c << 6) | (d & 0x3F);
		fwrite(out, sizeof(char), 3, fp);
	}

	a = index[in[len - 4]];
	b = index[in[len - 3]];
	c = index[in[len - 2]];
	d = index[in[len - 1]];
	if (in[len - 1] == '=' && in[len - 2] == '=')
	{
		out[0] = (a << 2) | ((b >> 4) & 0x3);
		fwrite(out, sizeof(char), 1, fp);
	}
	else if (in[len - 1] == '=')
	{
		out[0] = (a << 2) | ((b >> 4) & 0x3);
		out[1] = ((b & 0xF) << 4) | ((c >> 2) & 0xF);
		fwrite(out, sizeof(char), 2, fp);
	}
	else
	{
		out[0] = (a << 2) | ((b >> 4) & 0x3);
		out[1] = ((b & 0xF) << 4) | ((c >> 2) & 0xF);
		out[2] = (c << 6) | (d & 0x3F);
		fwrite(out, sizeof(char), 3, fp);
	}

	free(in);
	fclose(fp);

	return 0;
}
