#include <string>
#include <iostream>
using namespace std;


struct Point3D{
    int x, y, z;
    Point3D(){
        x = 0;
        y = 0;
        z = 0;
    }
}

int main(void){
    Point3D point;
    point = new Point3D;
    cout << point.x << point.y << point.z << endl;
}