#include<stdio.h>
#include"solution.h"
#include<stdlib.h>

int main(){
    FILE* fp = fopen("../test.txt","r");
    if (!fp){
        return -1;
    }
    Point* a = malloc(sizeof(Point));
    Point* b = malloc(sizeof(Point));
    Point* c = malloc(sizeof(Point));
    Point* d = malloc(sizeof(Point));

    if (fscanf(fp, "%f %f %f", &a->x, &a->y, &a->z) != 3){
        return -1;
    }
    if (fscanf(fp, "%f %f %f", &b->x, &b->y, &b->z) != 3){
        return -1;
    };
    if (fscanf(fp, "%f %f %f", &c->x, &c->y, &c->z) != 3){
        return -1;
    };
    if (fscanf(fp, "%f %f %f", &d->x, &d->y, &d->z) != 3){
        return -1;
    };
    fclose(fp);

    float* result = min_area_tetrahedron(a, b, c, d);
    printf("result %f, %p \n", *result, (void *) result);

    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}
