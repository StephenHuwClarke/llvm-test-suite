/* PR target/65648 */

int a = 0, *b = 0, c = 0;
static int d = 0;
short e = 1;
static long long f = 0;
long long *i = &f;
unsigned char j = 0;

__attribute__((noinline, noclone)) void
foo (int x, int *y)
{
#ifdef __CHERI_PURE_CAPABILITY__
  asm volatile ("" : : "r" (x), "C" (y) : "memory");
#else
  asm volatile ("" : : "r" (x), "r" (y) : "memory");
#endif
}

__attribute__((noinline, noclone)) void
bar (const char *x, long long y)
{
#ifdef __CHERI_PURE_CAPABILITY__
  asm volatile ("" : : "C" (x), "C" (&y) : "memory");
#else
  asm volatile ("" : : "r" (x), "r" (&y) : "memory");
#endif
  if (y != 0)
    __builtin_abort ();
}

int
main ()
{
  int k = 0;
  b = &k;
  j = (!a) - (c <= e);
  *i = j;
  foo (a, &k);
  bar ("", f);
  return 0;
}
