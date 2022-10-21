typedef struct Point{
    float x;
    float y;
    float z;
} Point;

typedef struct Vector{
    float i;
    float j;
    float k;
} Vector;

Vector* cross_product(Vector* a, Vector* b);

float vector_norm(Vector* v);

float* min_area_tetrahedron(Point* a, Point* b, Point* c, Point* d);
