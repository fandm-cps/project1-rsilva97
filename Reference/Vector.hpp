#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector
{
public:
  Vector();
  Vector(int n, double v);
  ~Vector();
  
  int size() const;
  Vector* operator+(Vector &rhs);
  double& operator[](int i);
  
  double max() const;

private:
  double *data;
  int n;
};

#endif
