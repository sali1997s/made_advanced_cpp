#include"solution.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

Vector* cross_product(Vector* a, Vector* b){
    Vector* v = malloc(sizeof(Vector));
    v->i = a->k * b->j - a->j * b->k;
    v->j = a->i * b->k - a->k * b->i;
    v->k = a->j * b->i - a->i * b->j;
    return v;
}

float vector_norm(Vector* v){
    return sqrt((v->i * v->i + v->j * v->j + v->k * v->k));
}

float area_triangle(Point* a, Point* b, Point* c){
    Vector* v = malloc(sizeof(Vector));
    v->i = c->x - a->x;
    v->j = c->y - a->y;
    v->k = c->z - a->z;

    Vector* u = malloc(sizeof(Vector));
    u->i = b->x - a->x;
    u->j = b->y - a->y;
    u->k = b->z - a->z;

    Vector* w = cross_product(v, u);
    w->i = w->i / 2;
    w->j = w->j / 2;
    w->k = w->k / 2;
    free(v);
    free(u);

    float area = vector_norm(w);
    free(w);

    return area;
}

float* min_area_tetrahedron(Point* a, Point* b, Point* c, Point* d){
    float* min_area;
    float s0 = area_triangle(a, b, c);
    min_area = &s0;
    //min_area = s0;
    float s1 = area_triangle(a, b, d);
    float s2 = area_triangle(a, c, d);
    float s3 = area_triangle(b, c, d);
    if (*min_area > s1){
        //*min_area = s1;
        min_area = &s1;
    }
    if (*min_area > s2){
        //*min_area = s2;
        min_area = &s2;
    }
    if (*min_area > s3){
        //*min_area = s3;
        min_area = &s3;
    }
    return min_area;
}
