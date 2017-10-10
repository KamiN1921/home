#include <iostream>
#include <cstdlib>
#include <cstdio>
#include"lab3.h"
using namespace std;


Fraction::Fraction(int a=0, int b=1){
            x=a;
            y=b;
            //count=0;        
        }
        
        int Fraction::Set(int a, int b=1){
            x=a;
            y=b;// count++;
            return 0;
            
        }
        //set(double a);
        Fraction::~Fraction(){cout<< "Сработал деструктор!"<<endl;}// как грамотно реализовать уборку мусора в классе;
        Fraction Fraction::operator+ (const Fraction &a)
        {
            return Fraction(x*a.y+y*a.x,y *a.y);
        }
        Fraction Fraction::operator* (Fraction &right){
            return Fraction(x*right.x,y *right.y);
        }
        Fraction Fraction::operator- (const Fraction &a)
        {
            return Fraction(x*a.y-y*a.x,y *a.y);
        }
        Fraction Fraction::operator/ (  Fraction &right){
            return Fraction(x*right.y,y *right.x);}

        void Fraction::Print(){
            cout<<x<<"/"<<y<<endl;
        }


int main()
{

    Fraction *v=NULL,*v2 = NULL;
    Fraction t;
    
    int n, a, b;
    

    cout<<"Введите размерность вектора дробей"<<endl;
    cin>>n;
    
    v=new Fraction[n];
    v2=new Fraction[n];

    t.count=n;

    
    for(int i=0;i<n;i++){
        do{
        cout<<"Введите числитель ";
        cin>>a;
        }while(a<0);
        
        do{
		cout<<"Введите знаминатель ";
        cin>>b;
        }while(b<=0);

        v[i].Set(a,b);
    }
    
    for(int i=0;i<n;i++){
        do{
        cout<<"Введите числитель ";
        cin>>a;
        }while(a<0);
        
        do{
		cout<<"Введите знаменатель ";
        cin>>b;
        }while(b<=0);

		v2[i].Set(a,b);
    }

    for(int i=0;i<n;i++)
    {
        cout << "Умножение: ";
        t=v[i]*v2[i];
        t.Print();

        cout << "Деление: ";
        t=v[i]/v2[i];
        t.Print();

        cout << "Сложение: ";
        t=v[i]+v2[i];
        t.Print();

        cout << "Вычитание: ";
        t=v[i]-v2[i];
        t.Print();

        //cout << "размерность: "<<Fraction::count<<endl;

    }

    t.Set(0,1);
    cout << "Скалярное произведение: ";
    for(int i=0;i<n;i++)
        t=t+(v[i]*v2[i]);
        t.Print();
     cout << "Модуль 1: ";
     t.Set(0,1);
     for(int i=0;i<n;i++)
     t=t+(v[i]*v[i]);
     t.Print();
     cout << "Модуль 2: ";
     t.Set(0,1);
     for(int i=0;i<n;i++)
     t=t+(v2[i]*v2[i]);
     t.Print();

    return 0;
}