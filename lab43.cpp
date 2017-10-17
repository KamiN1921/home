#include<iostream>
#include<cmath>

using namespace std;

class mnog{
protected:
    int d;
    int a;
    int b;
    int c;
public:
    mnog(){
        cout<<"Введите d"<<endl;
        cin>>d;
        cout<<"Введите a"<<endl;
        cin>>a;
        cout<<"Введите b"<<endl;
        cin>>b;
        cout<<"Введите c"<<endl;
        cin>>c;
    };
    ~mnog(){};
    int calc(int x){
        return (d*x*x*x+a*x*x+b*x+c);
    }
    int getd(){return d;}

};
class root{
    mnog* a;
public:
    root(){
        a=new mnog[1];
    };
    ~root(){delete []a;}
    void find(){
        int x;
        bool flag=false;
        x=std::abs(a->getd());
        for (int i = 1; i <= int(std::sqrt(x)); i++){
            if ((x%i == 0) &&( a->calc(i) == 0)) {
                std::cout << "Корень: " << i << std::endl;
                flag=true;   
            }
            if ((x%i == 0) &&( a->calc(-i) == 0)) {
                std::cout << "Корень: " << -i  << std::endl;
                flag=true;
            }
            
        } if(!flag)std::cout<<"нет действительных целых корней"<<endl;

    }


};
int main(){
    root a;

    a.find();

    return 0;
}