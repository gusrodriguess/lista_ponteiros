/* O código abaixo pode conter um memory leak, quando a variável
size for maior que 50 não será executado o que tem depois do if, visto
que tem um return dentro desse if. */

int f(char *data){
  void *s;
  s = malloc(50);
  int size = strlen(data);
  if (size > 50)
    return(-1);
  free(s);
  return 0;
}
