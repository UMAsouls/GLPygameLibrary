
class IVector3 {
public:
    virtual ~IVector3() = default;

    virtual float getX() const = 0;
    virtual float getY() const = 0;
    virtual float getZ() const = 0;

    virtual void setX(float x) = 0;
    virtual void setY(float y) = 0;
    virtual void setZ(float z) = 0;

    virtual void add(const IVector3& other) = 0;
    virtual void subtract(const IVector3& other) = 0;
    virtual void multiply(float scalar) = 0;
    virtual void divide(float scalar) = 0;

    virtual float dot(const IVector3& other) const = 0;
    virtual IVector3* cross(const IVector3& other) const = 0;
};