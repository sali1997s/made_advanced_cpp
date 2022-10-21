#include <gtest/gtest.h>
#include<stdio.h>
#include<stdlib.h>

extern "C" {
    #include<solution.h>
}

TEST(Src, TestBasics) {
    FILE* fp = fopen("../../test.txt","r");
    Point *a = (Point*) malloc(sizeof(Point));
    Point *b = (Point*) malloc(sizeof(Point));
    Point *c = (Point*) malloc(sizeof(Point));
    Point *d = (Point*) malloc(sizeof(Point));

    fscanf(fp, "%f %f %f", &a->x, &a->y, &a->z);
    fscanf(fp, "%f %f %f", &b->x, &b->y, &b->z);
    fscanf(fp, "%f %f %f", &c->x, &c->y, &c->z);
    fscanf(fp, "%f %f %f", &d->x, &d->y, &d->z);
    fclose(fp);

    float * result;
    result = min_area_tetrahedron(a, b, c, d);
    
    EXPECT_FLOAT_EQ(1, *result);
    free(a);
    free(b);
    free(c);
    free(d);
}

TEST(Src, TestBasicsPermute1) {
    FILE* fp = fopen("../../test.txt","r");
    Point *a = (Point*) malloc(sizeof(Point));
    Point *b = (Point*) malloc(sizeof(Point));
    Point *c = (Point*) malloc(sizeof(Point));
    Point *d = (Point*) malloc(sizeof(Point));

    fscanf(fp, "%f %f %f", &b->x, &b->y, &b->z);
    fscanf(fp, "%f %f %f", &a->x, &a->y, &a->z);
    fscanf(fp, "%f %f %f", &c->x, &c->y, &c->z);
    fscanf(fp, "%f %f %f", &d->x, &d->y, &d->z);
    fclose(fp);

    float * result;
    result = min_area_tetrahedron(a, b, c, d);
    
    EXPECT_FLOAT_EQ(1, *result);
    free(a);
    free(b);
    free(c);
    free(d);
}

TEST(Src, TestBasicsPermute2) {
    FILE* fp = fopen("../../test.txt","r");
    Point *a = (Point*) malloc(sizeof(Point));
    Point *b = (Point*) malloc(sizeof(Point));
    Point *c = (Point*) malloc(sizeof(Point));
    Point *d = (Point*) malloc(sizeof(Point));

    fscanf(fp, "%f %f %f", &b->x, &b->y, &b->z);
    fscanf(fp, "%f %f %f", &c->x, &c->y, &c->z);
    fscanf(fp, "%f %f %f", &a->x, &a->y, &a->z);
    fscanf(fp, "%f %f %f", &d->x, &d->y, &d->z);
    fclose(fp);

    float * result;
    result = min_area_tetrahedron(a, b, c, d);
    
    EXPECT_FLOAT_EQ(1, *result);
    free(a);
    free(b);
    free(c);
    free(d);
}
