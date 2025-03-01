/* PR tree-optimization/43560 */

struct S
{
  int a, b;
  char c[10];
};

__attribute__ ((noinline)) void
test (struct S *x)
{
  while (x->b > 1 && x->c[x->b - 1] == '/')
    {
      x->b--;
      x->c[x->b] = '\0';
    }
}

const struct S s = { 0, 0, "" };

int
main ()
{
  struct S *p;
#ifdef __CHERI_PURE_CAPABILITY__
  asm ("" : "=C" (p) : "0" (&s));
#else
  asm ("" : "=r" (p) : "0" (&s));
#endif
  test (p);
  return 0;
}
