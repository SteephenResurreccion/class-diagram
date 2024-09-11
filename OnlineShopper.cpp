#include <iostream>
#include <iomanip>

using namespace std;


class customer{
	private:
		string customerName;
		int customerID, phoneNumber, orderLog[100];
	public:
		void setCustomerName(string name){
			customerName=name;
		}
		void setCustomerID(int ID){
			customerID=ID;
		}
		void setCustomerPhoneNumber(int phoneNum){
			phoneNumber=phoneNum;
		}
		void setOrderLog(int order){
			orderLog[100]=order;
		}
};

class productList{
			private:
			string productName;
			float unitPrice;
			int productQuantity, productID;
			
			public:
			void setProductArray(string name, int id, float price, int quantity){
				productName=name;
				productID=id;
				unitPrice=price;
				productQuantity=quantity;
			}
		};

class productClass{
	private:
		float productPrice;
		int productCount;
		
	public:
		void displayCatalogue(){
			cout<<setw(5)<<"\nProduct"<<setw(5)<<"ID"<<setw(5)<<"Price per unit"<<setw(5)<<"Amount left\n"<<setw(5);
			for(int i=0; i<5; i++){
				cout<<setw(5)<<productArray[i].productName<<setw(5)<<productArray[i].productID<<setw(5)<<productArray[i].unitPrice<<setw(5)<<productArray[i].productQuantity;
			}
		}
		float getUnitPrice(float price){
			return unitPrice;
		}
		int getProductCount(){
			return productCount;
		}
		float getProductPrice(){
			unitPrice*productCount;
		}
};


class order{
	private:
		float paymentValue;
		bool paymentSuccess = false;
		int orderID;
	public:
		void setPaymentValue(){
			cout<<"	Enter amount to pay: ";
			cin>>paymentValue;
		}
		
		void paymentChecker(float total){
			if(paymentValue>=total)
				paymentSuccess = true;
		}
		void cancelOrder(){
		}
};


class shoppingCart{
	private:
		float total;
	public:	
		float totalCost(int count, float setPrice){
			for(int i=0; i<count; i++){
				total += setPrice;
				return total;
			}
		}
		void displayShoppingCart(string name, float price, int count, int unitPrice, int productCount){
			cout<<"\n	Product Name		Cost per Unit		Number of Units		Total Cost";
			for(int i=0; i<count;i++){
				cout<<"\n	1. "<<name<<"		P"<<unitPrice<<"		"<<productCount<<"		P"<<price;
			}
			cout<<"\n	Total Costs: P"<<total;
		}
};


int main(){
	productClass product;
	product.displayCatalogue();
	productList productArray[5];
		
	productArray[0].setProductArray("Rice and Steak", 1, 149, 10);
	productArray[1].setProductArray("Rice and Porkchop", 2, 129, 15);
	productArray[2].setProductArray("Iced Coffee", 3, 59, 50);
	productArray[3].setProductArray("Buko Juice", 4, 39, 40);
	productArray[4].setProductArray("Velvet Cake (1 Slice)", 5, 99, 8);
}