#define PI 3.14159

#ifndef CURVES_H
#define CURVES_H

// 1. Поддержка нескольких типов 3D-геометрических кривых — кругов, эллипсов и 3D-спиралей.
//    Каждая кривая должна иметь возможность возвращать трехмерную точку и первую производную (3D
//    вектор) по параметру t вдоль кривой.

class Circle
{
public:
    double a;
    Circle() {};
    Circle(double rx) { a = rx; };
    virtual vector <double> getPoint(double t)
    {
        vector <double> ret;

        ret.push_back( a * sin(t) );   //  x = a * sin(t)
        ret.push_back( a * cos(t) );   //  y = a * cos(t)
        ret.push_back( 0.0 );          //  z = 0
        return ret; 
    }
    virtual vector <double> getFirstDer(double t)
    {
        vector <double> ret;

        ret.push_back( a * cos(t) );      //  x = a * cos(t)
        ret.push_back( -(a * sin(t)) );   //  y = - (a * sin(t) )
        ret.push_back( 0.0 );             //  z = 0
        return ret; 
    }
};

class Ellipse: public Circle
{
public:
    double b;
    Ellipse() {};
    Ellipse(double rx, double ry) { a = rx; b = ry; }
    vector <double> getPoint(double t) override 
    {
        vector <double> ret;

        ret.push_back( a * sin(t) );   //  x = a * sin(t)
        ret.push_back( b * cos(t) );   //  y = b * cos(t)
        ret.push_back( 0.0 );          //  z = 0
        return ret; 
    }
    vector <double> getFirstDer(double t) override 
    {
        vector <double> ret;

        ret.push_back( a * cos(t) );      //  x = a * cos(t)
        ret.push_back( -(b * sin(t)) );   //  y = - (b * sin(t) )
        ret.push_back( 0.0 );             //  z = 0
        return ret; 
    }
};

class Helix: public Circle
{
public:
    double step;
    Helix() {};
    Helix(double rx, double s) { a = rx; step = s; }
    vector <double> getPoint(double t) override 
    {
        vector <double> ret;

        ret.push_back( a * sin(t) );          //  x = a * sin(t)
        ret.push_back( a * cos(t) );          //  y = a * cos(t)
        ret.push_back( step / 2 / PI * t );   //  z = step/(2*PI)*t
        return ret; 
    }
    vector <double> getFirstDer(double t) override 
    {
        vector <double> ret;

        ret.push_back( a * cos(t) );      //  x = a * cos(t)
        ret.push_back( -(a * sin(t)) );   //  y = - (a * sin(t) )
        ret.push_back( step/2/PI );       //  z = step/2/PI
        return ret; 
    }
};
 
#endif

