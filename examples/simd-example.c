//Compile: icc -qopt-report=2 -c simd-example.c

void add_floats(float *a, float *b, float *c, float *d, float *e, int n) {
 int i;
 for (i=0; i<n; i++){
  a[i] = a[i] + b[i] + c[i] + d[i] + e[i];
 }
}
