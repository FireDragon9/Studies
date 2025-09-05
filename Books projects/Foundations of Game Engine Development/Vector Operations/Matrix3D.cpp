#include "Vector3d.cpp"


/*this is the definition of a simple data structure holding the entries of a 3x3 Matrix3D, the (i, j) entry of a matrix is accessed byy using the operator (), and the j-th 
 * column is accessed as a 3D vector bt using operator []. Structures for matrices
 * of different size are similar*/

struct Matrix3D{

  private:

    float n[3][3];

  public:

    Matrix3D() = default;

    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22){

      n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
      n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
      n[2][0] = n02; n[2][1] = n21; n[2][2] = n22;

    }

    Matrix3D(const Vector3d& a, const Vector3d& b, const Vector3d& c){

      n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
      n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
      n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
  

    }

    float& operator()(int i, int j){
      return (n[j][i]);
    }

    const float& operator()(int i, int j) const{
      return (n[j][i]);
    }

    Vector3d& operator[](int j){
      return (*reinterpret_cast<Vector3d *>(n[j]));
    }


};//struct Matrux3D
