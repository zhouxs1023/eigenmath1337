#include "defs.h"

void
eval_product(void)
{
	int h, j, k;

	// 1st arg (quoted)

	p1 = cdr(p1);
	p2 = car(p1);
	if (!issymbol(p2))
		stop("product: 1st arg?");

	// 2nd arg

	p1 = cdr(p1);
	push(car(p1));
	eval();
	j = pop_integer();
	if (j == ERR)
		stop("product: 2nd arg?");

	// 3rd arg

	p1 = cdr(p1);
	push(car(p1));
	eval();
	k = pop_integer();
	if (k == ERR)
		stop("product: 3rd arg?");

	// 4th arg

	p1 = cadr(p1);

	save_binding(p2);

	h = tos;

	for (;;) {
		push_integer(j);
		p3 = pop();
		set_binding(p2, p3);
		push(p1);
		eval();
		if (j < k)
			j++;
		else if (j > k)
			j--;
		else
			break;
	}

	multiply_factors(tos - h);

	restore_binding(p2);
}
