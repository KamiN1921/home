//напишите программу меняющую местами н-й и м-й элементы списка.
#include<cstdio>
#include<iostream>
using namespace std;

struct element{
    int x;
    element *next;
};

class List{
    element*head;
public:
    List(){head=NULL;}
    ~List(){
        while(head!=NULL){
            element *temp=head->next;
            delete head;
            head=temp;

        }
    }
    void Add(int x) 
    {
     element *temp=new element; 
    temp->x=x; 
    temp->next=head;
    head=temp;
    }


    void Show() 
    {
        element *temp=head; 

        if(temp==NULL)
        cout<<"Список пуст!";
 
 
         while (temp!=NULL) 
         {
            cout<<temp->x<<" "; 
            temp=temp->next; 
         }
    }

    int Swap(int a, int b){
        int n,m,i=1;
        element *temp=head,*tempxta,*tempxtb,*pra,*prb;

        if(a<b){n=--a;m=--b;}else if(a>b){n=--b;m=--a;}

        while (i<=m) 
        {
           
           if(i==n){
               pra=temp;
           }
           if (i==m){
            prb=temp;
           }
            temp=temp->next;
            i++; 
          
        }
        
        temp=pra->next;
        tempxta=pra->next->next;
        tempxtb=prb->next->next;
        pra->next=prb->next;
        pra->next=temp;
        pra->next->next=tempxtb;
        prb->next->next=tempxta;
        return 0;


    }
};
int main(){
    List list;
    int c=0, n,m,i=0;



    do{
        cout<<"Добавьте элемент списка, для выхода нажмите 0"<<endl;
        cin>>c;
        if(c!=0){list.Add(c);i++;}
    }while(c!=0);

    cout<<"Ваш список: "<<endl;
    list.Show();
do{
    cout<<"Введите номера элементов которые хотите поменять: "<<endl;
    std::cin>>n>>m;
    if((n<0)||(m<0)||(n==m))
    cout<<"Некоректный ввод!!"<<endl<<n<<m;
}while((n<0)||(m<0)||(n==m)||(n>i)||(m>i));

    list.Swap(n,m);
    cout<<"Ваш список: "<<endl;
    list.Show();
    return 0;
}