#include <cmath>
struct Vector3d{
  
  //can be acessed directly
  float x, y, z;

  Vector3d() = default;
  
  //taking three values can be used to initialize the vector 
  Vector3d(float a, float b, float c){

    x = a;
    y = b;
    z = c;

  }

  Vector3d& operator += (const Vector3d& v){

    x += v.x;
    y += v.y;
    z += v.z;

    return (*this);

  }

  Vector3d& operator -= (const Vector3d& v){

    x -= v.x;
    y -= v.y;
    z -= v.z;

    return (*this);

  }
  
  Vector3d& operator *=(float s){

    x *= s;
    y *= s;
    z *= s;

    return (*this);

  }

  Vector3d& operator /= (float s){

    s = 1.0f / s;
    x *= s;
    y *= s;
    z *= s;

    return (*this);
    

  }


  /*The structure also includes two overloaded brackets operators,
   *enabling access to the components using zero-based indicies,
   *consisting of one operator for non-const objects,
   *which can be used for component assignment,
   and one operator for constant objects
   */

  float& operator [](int i){

    return ((&x)[i]);

  }

  const float& operator[](int i) const{

    return((&x)[i]);

  }

};//struct 


inline Vector3d operator +(const Vector3d& a, const Vector3d& b){
  
  return (Vector3d(a.x + b.x, a.y + b.y, a.z + b.z));

}

inline Vector3d operator -(const Vector3d& a, const Vector3d& b){

  return(Vector3d(a.x - b.x, a.y - b.y, a.z - b.z));

}

inline Vector3d operator *(const Vector3d& v, float s){

  return(Vector3d(v.x * s, v.y * s, v.z * s));

}

inline Vector3d operator /(const Vector3d& v, float s){

  s = 1.0f / s;
  return (Vector3d(v.x * s, v.y * s, v.z * s)); 

}

inline Vector3d operator -(const Vector3d& v){

  return (Vector3d(-v.x, -v.y, -v.z));

}

inline float Magnitude (const Vector3d& v){

  return(sqrt(v.x * v.x + v.y * v.y + v.z * v.z));

}

inline Vector3d Normalize (const Vector3d& v){

  return (v / Magnitude(v));

}
