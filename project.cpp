#include <iostream>
#include <vector>
#include <fstream>
#include<conio.h>
#include<windows.h>
using namespace std;

void menu();
void Merge(vector<string> &a,vector<int> &b, int low, int high, int mid);
void MergeSort(vector<string> &a,vector<int> &b, int low, int high);


class product_amount
{
private :
    class details
    {
    public :
        string product;
        double rs;
    };

    double Pamount_paid(vector<string> &bill,vector<int> &quantity,int low,int high)
    {
        int i=0;
        double amount=0;
        ifstream inFile;

        inFile.open("product_amount.txt");

        if (!inFile)
        {
            cout << "\t\tUnable to open file";
            exit(1);
        }

        details add;

        while(inFile >> add.product >>add.rs)
        {
            if (bill[i]==add.product)
            {
                amount+=(add.rs*quantity[i]);
                i++;

            }
            if(i>high)
                break;
        }
    inFile.close();

    return amount;
    }

public :
    double amount_paid(vector<string> &bill,vector<int> &quantity,int low,int high);

};

class inventor
{
private :
    class details
    {
    public:
        char name[60];
        char mail[60];
        double phone;
        char card;
    };

    void Plogin()
    {
        char password[]="swager",admin_name[]="vikrant";
        char str[20],pass[20],temp;
        cout <<"\t\tEnter the ADMIN NAME\n\t\t";
        cin >>str;
        system("cls");
        printf("\t\tEnter the Password\n\t\t");
        int i=0;
        while(1)
        {
            temp=getch();
            if(temp==13)
            {
                pass[i]='\0';
                break;
            }
            else if(temp==8)
            {
                if(i>0)
                i--;
            }
            else
            {
                pass[i]=temp;
                i++;
            }
            printf("*");

        }
        printf("\n");
        if(strcmp(str,admin_name)==0 && strcmp(pass,password)==0)
        menu();
        else
        cout<<"\t\tInvalid Mail Id or Password\n";
    }

    void Pcustomer_order()
    {
        int n,h;
        string s;
        details add;
        cout<<"\n\t\tENTER THE NAME: ";
        cin>>add.name;
        cout<<"\n\t\tENTER THE MAIL: ";
        cin>>add.mail;
        cout<<"\n\t\tENTER THE PHONE NUMBER: ";
        cin>>add.phone;
        cout<<"\n\t\tYOU HAVE CARD (Y/N): ";
        cin>>add.card;

        ofstream ptr;
        ptr.open("record.txt",ios_base::app);
        ptr<<add.name<<" "<<add.mail<<" "<<add.phone<<" "<<add.card;
        ptr<<"\n";
        ptr.close();

        vector<string> bill;
        vector<int> quantity;
        cout<<"\n\t\tHOW MANY ELEMENTS ARE THERE";
        cin>>n;
        cout<<"\t\tPRODUCT\t"<<"QUANTITY\n";
        for (int i=0;i<n;i++)
        {
            cout<<"\t\t";
            cin>>s;
            cin>>h;
            bill.push_back(s);
            quantity.push_back(h);
        }

        MergeSort(bill,quantity, 0, n-1);

        ofstream ptr2;
        ptr.open("record.txt",ios_base::app);
        ptr2.open("billrecord.txt",ios_base::app);
        for (int i=0;i<n;i++)
        {
            ptr<<bill[i]<<" "<<quantity[i]<<" ";
            ptr2<<bill[i]<<" ";
        }
        ptr<<"\n\n";
        ptr2<<"\n";
        ptr.close();
        ptr2.close();

        product_amount obj2;
        cout<<"\nAMOUNT TO BE PAID: ";

        cout<<obj2.amount_paid(bill,quantity,0,n-1);
        cout<<"\nIf Amount Paid ";
        system("pause");
		system("cls");

        menu();

    }

public :
    void login();
    void customer_order();


};

class prefrencer
{
private :
    class Node
    {
    public:
        int val;
        string E1,E2;
        Node *left,*right;

    	Node(string s1, string s2)
    	{
    		val = 0;
    		E1 = s1;
    		E2 = s2;
    		left =right = NULL;
    	}

    };

    Node *PinsertE(string s1,string s2,Node *temp)
    {
        if(temp ==NULL )
        {
        cout<<"in";
            Node *New = new Node(s1,s2);
            return New ;
        }

        else if(temp->E1==s1 && temp->E2==s2 )
            temp->val+=1;

        else if(temp->E1 > s1 )
            temp->left=PinsertE(s1,s2,temp->left);

        else if(temp->E1 == s1 && temp->E2 > s2)
            temp->left=PinsertE(s1,s2,temp->left);

        else if(temp->E1 == s1 || temp->E2 < s2)
            temp->right=PinsertE(s1,s2,temp->right);

        else if(temp->E1 < s1 )
            temp->right=PinsertE(s1,s2,temp->right);

        return(temp);
    }

    void Preorder(Node *temp)
    {
        if( temp != NULL)
        {
            cout<<"\t";
            cout<<temp->E1<<" "<<temp->E2<<" "<<temp->val<<"\n";
            Preorder(temp->left);

            Preorder(temp->right);
        }
    }

public:
    Node *root=NULL;

    void insertE(vector<string> bill);
    void triverse();

};

void menu()
{   int choice;
    system("cls");
    system("color F");
    cout<<"\t\t\t\tTHAPAR INVENTORY SYSTEM\n";
    cout<<"\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    cout<<"\t\t1.Customer order\n\t\t2.Edit rate list \n\t\t3.Prefrenser \n\t\t4.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;

    system("cls");
    switch(choice)
    {
        case 1:{
            inventor obj;
            obj.customer_order();
        }
        break;
        /*case 2:edit();
        break;
        case 3:insertE();
        break;
        case 4: break;*/

    }

}



int main(){
    int n,qcheck=1,h;
    string s;
    inventor obj;

    obj.login();

    /*obj.insertE(bill);
        obj.triverse();*/
}

void prefrencer::insertE(vector<string> bill)
{
    for (int i=0;i<bill.size();i++)
    {
        for (int j=i+1;j<bill.size();j++)
        {
            root=PinsertE(bill[i],bill[j],root);
        }
    }
}

void prefrencer::triverse()
{
    Preorder(root);
}

void inventor::login()
{
    Plogin();
}

void inventor::customer_order()
{
    Pcustomer_order();
}

double product_amount::amount_paid(vector<string> &bill,vector<int> &quantity,int low,int high)
{
    double p;
    p=Pamount_paid(bill,quantity,low,high);
    return p;
}

void MergeSort(vector<string> &a,vector<int> &b, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a,b, low, mid);
		MergeSort(a,b, mid+1, high);

		Merge(a,b, low, high, mid);
	}
}

void Merge(vector<string> &a, vector<int> &b,int low, int high, int mid)
{
	int i, j, k;
	i = low;
	k = 0;
	j = mid + 1;
	vector<string> temp(high-low+1);
	vector<int> temp2(high-low+1);

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			temp2[k] = b[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			temp2[k] = b[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		temp2[k] = b[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		temp2[k] = b[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
		b[i] = temp2[i-low];
	}
}
