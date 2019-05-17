#ifndef CUTVOXEL_H
#define CUTVOXEL_H
class CutVoxel : public FiguraGeometrica{
    int x,y,z;

public:
    CutVoxel(int xi, int yi, int zi);
    void draw(Sculptor &t);
    ~CutVoxel();
};
#endif // CUTVOXEL_H
