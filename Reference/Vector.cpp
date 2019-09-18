#include "Vector.hpp"

Vector::Vector()
{
  n=0;
  data = new double[1];
}


Vector::Vector(int size, double v)
{
  
  this->n = size;
  data = new double[n];
  for(int i = 0; i < size; i++)
    {
      data[i] = v;
    }
}
 
Vector::~Vector()
{
  n = -1;
  delete [] data;
}


int Vector::size() const
{
  return n;
}


double Vector::max() const
{
  if(n == 0)
    {
      return -1;
    }
  double myMax = data[0];
  for(int i = 1; i < n; i++)
    {
      if(data[i] > myMax)
	{
	  myMax = data[i];
	}
    }
  return myMax;

}
  


Vector* Vector::operator+(Vector &rhs)
{
  
  Vector *myVector = new Vector(this->n, 0);
  for(int i = 0 ; i < n; i++)
    {
      //(*myVector)[i] = data[i] + rhs[i];
      (*myVector)[i] = data[i] + rhs.data[i];
    }
  return myVector;
}


double& Vector::operator[](int i)
{
  return data[i];
}
 

#ifdef DEBUG
#include <iostream>

using namespace std;

int main()
{

  int test_count = 2;
  int test_iter = 0;
  //cout << "We can write our tests here" << endl;
  //TEST CONSTRUCTOR
  Vector *test_vector = new Vector();
  if(test_vector->size() != 0)
    {
      cerr << "ERROR: Vector size on default constructor" << endl;
      cerr << "TEST 1/2 FAILED" << endl;
      test_iter += 1;
    }

  double test_max = test_vector->max();
  if(test_max != -1)
    {
      cerr << "ERROR: Vector max on default constructor" << endl;
      cerr << "TEST 2/2 FAILED" << endl;
      test_iter +=1;
    }
 
  cerr << "Total Test Failed " << test_iter << " out of " << test_count << endl;


}


#endif
