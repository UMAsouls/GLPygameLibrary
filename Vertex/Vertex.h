#pragma once


class Vertex {
private:
    float x, y, z; // Vertex coordinates
    float nx, ny, nz; // Normal coordinates
    float u, v; // Texture coordinates

public:

    Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
        : x(x), y(y), z(z), nx(nx), ny(ny), nz(nz), u(u), v(v) {}

    float X() const { return x; } float Y() const { return y; } float Z() const { return z; } 
    float NX() const { return nx; } float NY() const { return ny; } float NZ() const { return nz; }
    float U() const { return u; } float V() const { return v; }


    

}; 