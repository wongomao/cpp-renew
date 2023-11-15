#ifndef VECTOR_STRUCT_H
#define VECTOR_STRUCT_H

struct VectorStruct {
    int sz;
    double* elem;
};

void vector_init(VectorStruct& v, int s);
void show_all(VectorStruct& v);
void vector_destroy(VectorStruct& v);
void vector_action(VectorStruct v, VectorStruct& rv, VectorStruct* pv);
double read_and_sum(int s);

#endif // VECTOR_STRUCT_H