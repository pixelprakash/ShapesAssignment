#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

class Shape {
public:
    virtual void input() = 0;
    virtual void compute() = 0;
    virtual ~Shape() {}
};


class Rectangle : public Shape {
    int l,b;
public:
    void input(){
        cout<<"Enter length and breadth of Rectangle: "<<endl;
        cin>>l>>b;
    }
    void compute(){
        int a = l*b;
        int p = 2*(l+b);
        ofstream file("output.txt", ios::app);
        cout<<"Area = "<<a<<", Perimeter = "<<p<<endl;
        file<<"Rectangle of length " << l << "and bredth " << b << " Area = "<< a << "Perimeter = "<< p <<endl;
        file.close();
    }
};

class Square : public Shape {
    int s;
public:
    void input(){
        cout<<"Enter side of Square: "<<endl;
        cin>>s;
    }
    void compute(){
        int a = s*s;
        int p = 4*s;
        ofstream file("output.txt", ios::app);
        cout<<"Area = "<<a<<", Perimeter = "<<p<<endl;
        file<<"Square of side lenght "<< s <<" Area = "<<a<<", Perimeter = "<<p<<endl;
        file.close();
    }
};

class Circle : public Shape {
    int r;
    const double pi=3.14;
public:
    void input(){
        cout<<"Enter radius of Circle: "<<endl;
        cin>>r;
    }
    void compute(){
        int a = pi*r*r;
        int p = 2*pi*r;
        ofstream file("output.txt", ios::app);
        cout<<"Area = "<<a<<", Perimeter = "<<p<<endl;
        file<<"Circle of radius "<< r <<" Area = "<<a<<", Perimeter = "<<p<<endl;
        file.close();
    }
};

class Cube : public Shape {
    int s;
public:
    void input(){
        cout<<"Enter side of Cube: "<<endl;
        cin>>s;
    }
    void compute() {
        int a = 6*s*s;
        int p = 12*s;
        ofstream file("output.txt", ios::app);
        cout<<"Surface Area = "<<a<<", Perimeter = "<<p<<endl;
        file<<"Cube of side " <<s<<" Area = "<<a<<", Perimeter = "<<p<<endl;
        file.close();
    }
};

class Cuboid : public Shape {
    int l,b,h;
public:
    void input(){
        cout<<"Enter length, breadth and height of Cuboid: "<<endl;
        cin>>l>>b>>h;
    }
    void compute(){
        int a = 2*((l*b)+(b*h)+(h*l));
        int p = 4*(l+b+h);
        ofstream file("output.txt", ios::app);
        cout<<"Surface Area = "<<a<<", Perimeter = "<<p<<endl;
        file<<"Cuboid of legth "<<l<<"Breadth "<<b<<"Height "<<h<<" Area = "<<a<<", Perimeter = "<<p<<endl;
        file.close();
    }
};

class Sphere : public Shape {
    int r;
    const double pi=3.14;
public:
    void input(){
        cout<<"Enter radius of Sphere: "<<endl;
        cin>>r;
    }
    void compute(){
        int a = 4*pi*r*r;
        float v = (4.0/3.0)*pi*r*r*r;
        ofstream file("output.txt", ios::app);
        cout<<"Surface Area = "<<a<<", Volume = "<<v<<endl;
        file<<"Sphere of radius "<<r<<" Area = "<<a<<", Volume = "<<v<<endl;
        file.close();
    }
};

class Cone : public Shape {
    int r,h;
    const double pi=3.14;
public:
    void input(){
        cout<<"Enter radius and height of Cone: "<<endl;
        cin>>r>>h;
    }
    void compute(){
        float l = sqrt(r*r + h*h);
        float a = pi*r*(r+l);
        float v = (1.0/3.0)*pi*r*r*h;
        ofstream file("output.txt", ios::app);
        cout<<"Surface Area = "<<a<<", Volume = "<<v<<endl;
        file<<"Cone of radius "<<r<<"height "<<h<<" surface Area = "<<a<<", Volume = "<<v<<endl;
        file.close();
    }
};


int main(){
    Shape *ptr = nullptr;
    int ch, opt;

    cout <<"Which Dimension shape you want to explore:\n";
    cout <<"1 - Two Dimension\n2 - Three Dimension\nEnter your choice: ";
    cin >> ch;

    if(ch==1){
        cout<<"Choose Shape:\n1.Rectangle\n2.Square\n3.Circle\nEnter: ";
        cin >> opt;
        switch(opt){
            case 1: ptr = new Rectangle(); break;
            case 2: ptr = new Square(); break;
            case 3: ptr = new Circle(); break;
            default: cout<<"Invalid option\n"; return 0;
        }
    }
    else if(ch==2){
        cout<<"Choose Shape:\n1.Cube\n2.Cuboid\n3.Sphere\n4.Cone\nEnter: ";
        cin >> opt;
        switch(opt){
            case 1: ptr = new Cube(); break;
            case 2: ptr = new Cuboid(); break;
            case 3: ptr = new Sphere(); break;
            case 4: ptr = new Cone(); break;
            default: cout<<"Invalid option\n"; return 0;
        }
    }
    else{
        cout<<"Choose either 1 or 2 only.\n";
        return 0;
    }

    ptr->input();
    ptr->compute();

    delete ptr;
    return 0;
}
