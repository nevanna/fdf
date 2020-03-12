#include "st.h"

void ft_no_ch(t_b b)
{
	b.x = 10;
	b.y = 50;
	printf("1x->%i y->%i\n", b.x, b.y);
}
void ft_no(t_b *b)
{
	b->x = 10;
	b->y = 50;
	printf("3x->%i y->%i\n", b->x, b->y);
}


int main ()
{
	t_b	b;

	b.x = 12;
	b.y = 33;
	printf("0x->%i y->%i\n", b.x, b.y);
	ft_no_ch(b);
	printf("2x->%i y->%i\n", b.x, b.y);
	ft_no(&b);
	printf("4x->%i y->%i\n", b.x, b.y);
	return (0);
}
