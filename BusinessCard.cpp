#include <fstream> //Copyright 2022
#include <math.h>  //Jack Pilley
using namespace std;typedef int I;typedef
float F;typedef uint8_t B;struct V{F x,y,
z;V operator+(V v){return V{x+v.x,y+v.y,z
+v.z};}V operator*(F a){return V{x*a,y*a,
z*a};}float operator*(V v){return v.x*x+v
.y*y+v.z*z;}V operator^(V n){V i = (*this
);return i+(n*(i*n)*2.f)*-1;}F operator!(
){return x*x+y*y+z*z;}V N(){V t = *this;
return t*(1/sqrtf(!t));}};F S(V o,V d,V s
){F p=s*d;F a=p*p-1*(!s-1);if(a>0){return 
-p-sqrt(a);}return -1;}V R(V o,V d){V s={
o.x,o.y-.2,o.z-3};V l=(V{.3f,1,0}).N();F
t = S(o,d,s);if(t>0){V normal=(s+d*t).N()
;V p=o+d*t;return V{0,.5,1}*max(normal*l,
0.f)+V{1,1,1}*pow(max(p.N()*(l^normal),
0.f),15)*.4+R(p+(d^normal)*0.01f,d^normal
)*.3f;}if(d.y<0){V p=o+d*(o.y+1.5f)*(1/-d
.y);F t=((I)floor(p.x * 2)-(I)floor(p.z*2
))&1;return V{1,t,t}*(S(p,l,V{p.x,p.y-.2f
,p.z-3})>0?.5f:1);}return V{d.y/2+.3f,d.y
/2+.3f,d.y/2+.5f};}F D(){return rand()/(F
)RAND_MAX/16-1/32.f;}int main(){ofstream
f("c.ppm",ofstream::binary);f<<
"P6 500 500 255\n";for(I r=0;r<500;r++){
for(I c=0;c<500;c++){F x=-1+c/250.f;F y=1
-r/250.f;V p{x*3,y*3,3};V e{};for(I i=0;i
<60;++i){V o{x+D(),y+D(),1};V d=p+o*-1;e=
e+R(o,d.N());}e=(e*(1/60.f))*255.f;f<<(B)
e.x<<(B)e.y<<(B)e.z;}}return 0;}