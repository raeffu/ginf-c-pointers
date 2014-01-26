#include <stdio.h>

struct NODE {
  int a ;
  struct NODE *b;
  struct NODE *c;
};

struct NODE nodes[5] = {
  { 5, nodes + 3, NULL },
  { 15, nodes + 4, nodes + 3 },
  { 22, NULL, nodes + 4 },
  { 12, nodes + 1, nodes },
  { 18, nodes + 2, nodes + 1 }
};

struct NODE *np = nodes + 2;
struct NODE **npp = &nodes[1].b;

int main(){

  printf("struct NODE nodes[5] = {\n { 5, nodes + 3, NULL },\n { 15, nodes + 4, nodes + 3 },\n { 22, NULL, nodes + 4 },\n { 12, nodes + 1, nodes },\n { 18, nodes + 2, nodes + 1 }\n};\n");
  printf("sizeof(int) \t\t%zu\n", sizeof(int));
  printf("sizeof(struct NODE *) \t%zu\n", sizeof(struct NODE *));
  printf("sizeof(nodes[0].a) \t%zu\n", sizeof(nodes[0].a));
  printf("sizeof(nodes[0].b) \t%zu\n", sizeof(nodes[0].b));
  printf("sizeof(nodes[0].c) \t%zu\n", sizeof(nodes[0].c));
    printf("sizeof(nodes[0]) \t%zu\n", sizeof(nodes[0]));
  printf("sizeof(nodes) \t\t%zu\n", sizeof(nodes));

  printf("nodes[3].a\t\t%i\n", nodes[3].a);
  printf("nodes[3].a\t\t%i\n", nodes[3].a);

  printf("nodes\t\t\t%p\n", nodes);
  //  printf("%i\n", nodes.a);
  printf("nodes[3].a\t\t%i\n", nodes[3].a);
  printf("nodes[3].c\t\t%p\n", nodes[3].c);
  printf("nodes[3].c->a\t\t%i\n", nodes[3].c->a);
  printf("*nodes\t\t\t{ %i, %p, %p }\n", (*nodes).a, (*nodes).b, (*nodes).c);
  //    printf("*nodes.a\t\t\t %i\n", *nodes.a);
  printf("*nodes.a\t\tillegal\n");
  printf("(*nodes).a\t\t%i\n", (*nodes).a);

  printf("nodes->a\t\t%i\n", nodes->a);
  printf("nodes[3].b->b\t\t%p\n", nodes[3].b->b);

  printf("*nodes[3].b->b\t\t{ %i, %p, %p }\n", (*nodes[3].b->b).a, (*nodes[3].b->b).b, (*nodes[3].b->b).c );
  printf("&nodes\t\t\t%p \n", &nodes);
  printf("&nodes[3].a\t\t%p \n", &nodes[3].a);
    printf("&nodes[3].b\t\t%p \n", &nodes[3].b);
  printf("&nodes[3].c\t\t%p \n", &nodes[3].c);

  printf("&nodes[3].c->a\t\t%p \n", &nodes[3].c->a);

  printf("np\t\t\t%p \n", np);
  printf("np->a\t\t\t%i \n", np->a);

  printf("np->c->c->a\t\t%i \n", np->c->c->a);

  printf("*npp\t\t\t%p \n", *npp);
  // printf("**npp\t\t\t%p \n", **npp);

  printf("**npp\t\t\t{ %i, %p, %p }\n", (**npp).a, (**npp).b, (**npp).c );

  printf("**npp\t\t\t{ %i, %p, %p }\n", (**npp).a, (**npp).b, (**npp).c );
  printf("*npp->a\t\t\tillegal\n" );
  printf("(*npp)->a\t\t%i\n",(*npp)->a );

  printf("&np\t\t\tunknown: %p\n",&np);
  printf("&np->a\t\t\t%p\n",&np->a);
  printf("&np->c->c->a\t\t%p\n",&np->c->c->a);

  return 1;
}
