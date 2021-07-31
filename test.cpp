#include<iostream>
#include "Vector.h"
#include "Array.h"

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define ios freopen("i","r",stdin); freopen("o","w",stdout);

template<typename T>
void PrintVector(const Vector<T>& vector){
  rep(i, vector.Size()){
      std::cout<<vector[i]<<std::endl;
    }
}

class Point{
  public:
    Point(){}
    Point(float x):x(x), y(x), z(x){}
    Point(float&& p, float&& q, float&& r){
      x = std::move(p);
      y = std::move(q);
      z = std::move(r);
    }

    ~Point(){
    }

    // --------------------------
    // Below commented code gives error '<< can have exactly one argument'
    /* std::ostream& operator<<(std::ostream& os, const Point& point){
      os << point.x << ' ' << point.y << ' ' << point.z;
      return os;
    } */

    // ------------------------
    // Undermentioned friend function works just fine and can have 2 arguments
    friend std::ostream& operator<<(std::ostream& os, const Point& point){
      os << point.x << '/' << point.y << '/' << point.z;
      return os;
    }

  private:
    float x = 0.0f, y = 0.0f, z = 0.0f;
};

int main(){
  Point point(1.0f);
  std::cout << point << std::endl;
}