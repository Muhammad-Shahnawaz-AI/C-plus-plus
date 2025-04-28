#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class product
{
	private:
	int productid;
	string productname;
	int quantity;
	float price;
	public:
		void addproduct()
		{
			cout<<"Enter the product name: ";
			cin.ignore();
			cin>>productname;
			cout<<"Enter the product id: ";
			cin>>productid;
			cout<<"Enter the quantity: ";
			cin>>quantity;
			cout<<"Enter the price: ";
			cin>>price;
		}
		void saveproduct(string filename)
		{
			ofstream file;
			file.open(filename,ios::app);
			file<<productid<<", "<<productname<<", "<<quantity<<", "<<price<<endl;
			file.close();
		}
		static void listproducts(string filename)
		{
			ifstream file;
			file.open(filename,ios::in);
			while(!(file.eof()))
			{
				string m;
				getline(file,m);
				cout<<m<<endl;
			}
		}
		
	
};
int main()
{
	product p;
	int c=0;
	while(!(c==3))
	{
		cout<<"1. Add product"<<endl;
		cout<<"2. List product"<<endl;
		cout<<"3. Exit"<<endl;
		cin>>c;
		if(c==1)
		{
			p.addproduct();
			p.saveproduct("product.txt");
			
		}
		else if(c==2)
		{
			p.listproducts("product.txt");
		}
		else if(c==3)
		{
			cout<<"exiting program"<<endl;
		}
		else
		{
			cout<<"invalid input"<<endl;
		}
	}
	return 0;
}
