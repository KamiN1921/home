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
	 cout<<endl;
    }

    int Swap(int a, int b){
        int n,m,i=1;
        element *temp=head, *temp1, *tempxta,*tempxtb,*pra,*prb;

        if(a<b){n=--a;m=--b;}else if(a>b){n=--b;m=--a;}

        while (i<=m) 
        {
           
           if (i==n){
               pra=temp;
           }
           if (i==m){
               prb=temp;
           }

            temp=temp->next;
            i++; 
          
        }
        
        if (n>0) { temp=pra->next; } else { temp = head; } // если a элемент не первый в списке, сохраняем эл. a, иначе он остаётся head
        temp1=prb->next; // сохраняем эл. b

	tempxta=temp->next; // сохраняем ссылку на след за а 
	tempxtb=temp1->next; // сохраняем ссылку на след за b
 
        if (n>0) { pra->next=prb->next; } else { head=prb->next; } // если а - первый в списке, b становится головой списка
        prb->next=temp; // элементы мы поменяли


	temp1->next=tempxta; // восстанавливаем связи
	temp->next=tempxtb;  // восстанавливаем связи

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
