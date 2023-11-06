#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    int sz;
    double* elem;
};

void vector_init(Vector& v, int s);
void show_all(Vector& v);
void vector_destroy(Vector& v);

#endif // VECTOR_H