#include "test.h"

extern void *mlx_init(void);
extern void *mlx_new_window(void *, int, int, char *);

void test()
{
	void *init;

	init = mlx_init();
	mlx_new_window(init, 100, 100, "title");
}