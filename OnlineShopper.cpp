#include <iostream>

using namespace std;


class customer{
	private:
		string customerName;
		int customerID, phoneNumber;
	public:
		
};


class product{
	private:
		string productName;
		float productPrice, unitPrice;
		int productCount;
	
	public:	
		void displayCatalogue(){
			
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
	
}