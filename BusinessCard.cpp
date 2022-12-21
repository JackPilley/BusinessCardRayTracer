#include <fstream> //Copyright 2022
#include <math.h>  //Jack Pilley
#define u return
using namespace std;typedef int I;typedef
float F;typedef uint8_t B;struct V{F x,y,
z;V operator+(V v){u V{x+v.x,y+v.y,z+v.z}
;}V operator*(F a){u V{x*a,y*a,z*a};}F
operator*(V v){u v.x*x+v.y*y+v.z*z;}V
operator^(V n){u *this+(n*(*this*n)*2)*-1
;}F operator!(){u x*x+y*y+z*z;}V N(){u *
this*(1/sqrtf(!*this));}};F S(V o,V d,V s
){F p=s*d;F a=p*p-1*(!s-1);if(a>0){u -p-
sqrt(a);}u-1;}V R(V o,V d){V s={o.x,o.y-
.2,o.z-3};V l=(V{.3f,1,0}).N();F t=S(o,d,
s);if(t>0){V n=(s+d*t).N();V p=o+d*t;u V{
0,.5,1}*max(n*l,0.f)+V{1,1,1}*pow(max(p.N
()*(l^n),0.f),15)*.6+R(p+(d^n)*0.01,d^n)*
.3;}if(d.y<0){V p=o+d*(o.y+1.5)*(1/-d.y);
F t=(I)(floor(p.x*2)-floor(p.z*2))&1;u V{
1,t,t}*(S(p,l,V{p.x,p.y-.2f,p.z-3})>0?.5:
1);}u V{d.y/2+.3f,d.y/2+.3f,d.y/2+.5f};}F
D(){u (F)rand()/RAND_MAX/16-1/32.f;}I
main(){ofstream f("card.ppm",ofstream::
binary);f<<"P6 500 500 255 ";for(I r=0;r<
500;r++){for(I c=0;c<500;c++){F x=-1+c/
250.f;F y=1-r/250.f;V p{x*3,y*3,3};V e{};
for(I i=0;i<60;++i){V o{x+D(),y+D(),1};V
d=p+o*-1;e=e+R(o,d.N());}e=(e*(1/60.f))*
255.f;f<<(B)min(e.x,255.f)<<(B)min(e.y,
255.f)<<(B)min(e.z,255.f);}}u 0;}