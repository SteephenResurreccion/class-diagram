#include <iostream>
#include <iomanip>
#include <algorithm>

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
			public:
			string productName, productID;
			float unitPrice;
			int productQuantity;
			void setProductArray(string name, string id, float price, int quantity){
				productName=name;
				productID=id;
				unitPrice=price;
				productQuantity=quantity;
			}
		};

class productClass: public productList{
	private:
		float productPrice;
		int productCount;
		
	public:
		productList productArray[20];
		
		productClass(){
		productArray[0].setProductArray("Rice and Steak", "ABC", 149, 10);
		productArray[1].setProductArray("Rice and Porkchop", "EFG", 129, 15);
		productArray[2].setProductArray("Iced Coffee", "HIJ", 59, 50);
		productArray[3].setProductArray("Buko Juice", "KLM", 39, 40);
		productArray[4].setProductArray("Velvet Cake (1 Slice)", "NOP", 99, 8);
		}
		void displayCatalogue(){
			cout<<left<<setw(28)<<"\nProduct"
			<<setw(10)<<" ID"
			<<setw(20)<<"Price per unit"
			<<setw(20)<<"Amount left"<<endl;
			for(int i=0; i<5; i++){
				cout<<left<<setw(28)<<productArray[i].productName
				<<setw(10)<<productArray[i].productID
				<<setw(20)<<productArray[i].unitPrice
				<<setw(20)<<productArray[i].productQuantity<<endl;
			}
		}
		void setProductQuantity(int location,int subtractor){
			productArray[location].productQuantity=productArray[location].productQuantity-subtractor;
		}
		float getUnitPrice(){
			return unitPrice;
		}
		int getProductCount(){
			return productCount;
		}
		float getProductPrice(){
			return unitPrice*productCount;
		}
		int countInitializedProducts() {
            int count = 0;
            for (int i = 0; i < 20; i++) {
                if (!productArray[i].productName.empty()) {
                    count++;
                }
            }
            return count;
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


class shoppingCart: public productClass{
	private:
		float total, grandTotal;
	public:	
		float totalCost(int location, int count){
				total = productArray[location].unitPrice*count;
				grandTotal+=total;
			}
			
		void displayShoppingCart(int location, int productCount, int i){
			cout<<"\nOrder ID: "<<i+1<<"\n";
			cout<<"Total Amount: "<<total;			
			cout<<left<<setw(28)<<"\nProduct"
			<<setw(10)<<" ID"
			<<setw(20)<<"Price per unit"
			<<setw(20)<<"Amount left"<<endl;
			cout<<left<<setw(28)<<productArray[location].productName
				<<setw(10)<<productArray[location].productID
				<<setw(20)<<productArray[location].unitPrice
				<<setw(20)<<productCount<<endl;
		}
};

void integerValidation(int &number){
			while (!(cin >> number)) {
		        cout <<"	Invalid input. Please try again: ";
		        cin.clear(); 
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		}
		}

bool limitValidation(int qtyBuy, int qtyLeft){
			if(qtyLeft<qtyBuy){
				cout<<"	We're out of stock of that item, please try again.\n";
				return true;
			}
			return false;	
		}

int main(){
	productClass product;
	shoppingCart cart;
	string itemChoice, orderChoice;
	int initializedCount = product.countInitializedProducts(), arrayLocation, productBoughtCount, orderCounter=0;
	bool validStringType, retry;
	int orderID[20][2];
	
	do {
		product.displayCatalogue();
		cout<<"\n";
		retry=false;
	do {
		validStringType=false;
		cout << "	Input the item ID to buy: ";
		getline(cin, itemChoice);
		transform(itemChoice.begin(), itemChoice.end(), itemChoice.begin(), ::toupper);
		for(int i=0; i<initializedCount; i++){
			if (itemChoice == product.productArray[i].productID){
			validStringType = true;
			arrayLocation = i;
			break;
			}
		}
	} while (!validStringType);
	cout<<"	"<<left<<setw(28)<<"Product"
			<<setw(10)<<" ID"
			<<setw(20)<<"Price per unit"
			<<setw(20)<<"Amount left"<<endl;
	cout<<"	"<<left<<setw(28)<<product.productArray[arrayLocation].productName
			<<setw(10)<<product.productArray[arrayLocation].productID
			<<setw(20)<<product.productArray[arrayLocation].unitPrice
			<<setw(20)<<product.productArray[arrayLocation].productQuantity<<endl;
	cout<<"	Input the amount of the product you want to buy: ";
	integerValidation(productBoughtCount);
	limitValidation(productBoughtCount, product.productArray[arrayLocation].productQuantity);
	cin.ignore();
		
		do {
		validStringType=false;
		cout<<"	Try Again?(if there was an error in your choice)[Y/N]: ";
		getline(cin, orderChoice);
		transform(orderChoice.begin(), orderChoice.end(), orderChoice.begin(), ::toupper);
		if (orderChoice == "Y" || orderChoice == "N"){
			retry = true;
			validStringType = true;
		}
		} while (!validStringType);
		do {
		if (orderChoice == "Y")
		break;
		validStringType=false;
		cout<<"	Buy More?[Y/N](No to proceed to checkout): ";
		getline(cin, orderChoice);
		transform(orderChoice.begin(), orderChoice.end(), orderChoice.begin(), ::toupper);
		if (orderChoice == "Y"){
			retry = true;
			validStringType = true;
			orderID[orderCounter][0]=arrayLocation;
			orderID[orderCounter][1]=productBoughtCount;
			product.setProductQuantity(arrayLocation,productBoughtCount);
			orderCounter+=1;
		}
		else if (orderChoice== "N"){
			retry = false;
			validStringType = true;
			orderID[orderCounter][0]=arrayLocation;
			orderID[orderCounter][1]=productBoughtCount;
			product.setProductQuantity(arrayLocation,productBoughtCount);
			orderCounter+=1;
		}
		} while (!validStringType);
		system("cls");
	}while(retry==true);
	for(int i=0; i<orderCounter; i++){
	cart.totalCost(orderID[i][0],orderID[i][1]);
	cart.displayShoppingCart(orderID[i][0], orderID[i][1],i);
	}
}