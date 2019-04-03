#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct rect_t {
	float width;
	float height;
	float left;
	float top;
};

void move_rect(rect_t& r, float hor, float ver)
{
	r.left += hor;
	r.top += ver;
}

void resize_rect(rect_t& r, float hor, float ver)
{
	r.width += hor;
	r.height += ver;
}

void print_rect(const rect_t& r)
{
	cout << "W: " << r.width << "; H: " << r.height;
	cout << "L: " << r.left << "; T: " << r.top;
	cout << endl;
}

int main()
{
	rect_t r = { 10,20,30,40 };
	print_rect(r);
	move_rect(r, 1, 2);
	print_rect(r);
	resize_rect(r, 1, 2);
	print_rect(r);
	return 0;
}
