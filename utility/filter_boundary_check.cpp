/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float Gp=-3.f;
    float Gs=-24.f;
    float wp=220.f;
    float ws=260.f;
    
    float n=0;
   // float n=(log10((pow(10,-Gs/10)-1)/(pow(10,-Gp/10)-1)))/(2.f*log(ws/wp));
    
    cout<<n;
    
    for(float i=1.f;i<1000;++i){
        n=0;
        for(float o=1.f;n<=10;++o){
            wp=10.f*i;
            ws=wp+10000.f-10.f*o;
            n=(log10((pow(10,-Gs/10)-1)/(pow(10,-Gp/10)-1)))/(2.f*log(ws/wp));
            
        }
        cout<<"wp: "<<wp<< " min ws: "<<ws<< " div: "<< ws/wp<< " min ws after div: "<<wp*1.1f<<endl;
        
    }

    return 0;
}
