#include <iostream>
#include <iomanip>
#include <algorithm>
#include <conio.h>

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


class orderClass: public productClass{
	private:
	public:
		void displayOrder(int location, int productCount){		
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


class shoppingCart: public productClass{
	private:
		float total, grandTotal;
	public:	
		void totalCost(int location, int count){
				total = productArray[location].unitPrice*count;
				grandTotal+=total;
			}
			
		void displayShoppingCart(int location, int productCount){
			cout<<"\nTotal Amount: "<<total;			
			cout<<left<<setw(28)<<"\nProduct"
			<<setw(10)<<" ID"
			<<setw(20)<<"Price per unit"
			<<setw(20)<<"Amount left"<<endl;
			cout<<left<<setw(28)<<productArray[location].productName
				<<setw(10)<<productArray[location].productID
				<<setw(20)<<productArray[location].unitPrice
				<<setw(20)<<productCount<<endl;
		}
		float getGrandTotal(){
			return grandTotal;
		}
		void setGrandTotal(int num){
			grandTotal=num;	
		}
};

void integerValidation(int &number){
			while (!(cin >> number)) {
		        cout <<"	Must be a number. Please try again: ";
		        cin.clear(); 
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		}
		}

int main(){
	productClass product;
	shoppingCart cart;
	orderClass order;
	string itemChoice, orderChoice, checkoutChoice;
	int initializedCount = product.countInitializedProducts(), arrayLocation, productBoughtCount, orderCounter=0, menuChoice, productCounter=0;
	bool validStringType, retry, menuLoop=true, validation, soldOut=false;
	int orderID[20][20][2]; 
	float pricePerShoppingCart[20][2];
	
	do {
		do{
		validation=true;
		cout<<" \n	1. View and Buy Products \n	2. View Shopping Cart \n	3. View Orders \n	4. Exit\n	Please Choose from the 4 choices above[1-4]: ";
		integerValidation(menuChoice);
		cin.ignore();
		if(menuChoice==2&&productCounter==0){
			cout<<"\n	Must have added a product first.\n";
			validation=false;
		}
		if(menuChoice==3&&orderCounter==0){
			cout<<"\n	Must have made an order first.\n";
			validation=false;
		}
		}while(validation==false);
		switch(menuChoice){
			case 1:
				do {
					if(	product.productArray[0].productQuantity==0&&
							product.productArray[1].productQuantity==0&&
							product.productArray[2].productQuantity==0&&
							product.productArray[3].productQuantity==0&&
							product.productArray[4].productQuantity==0){
							soldOut=true;	
							cout<<"\n	Sold Out.";
							cout<<"\n	Sold Out.";
							cout<<"\n	Sold Out.";
							cout<<"\n\n	Press Enter to Continue";	
							getch();
							break;
					}
					product.displayCatalogue();
					cout<<"\n";
					retry=false;
					do {
						
						validation=true;
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
						if(product.productArray[arrayLocation].productQuantity==0){
							cout<<"\n	There are no more of that product left, try again.\n";
							validation=false;
						}
					} while (!validStringType||validation==false);
					if (soldOut==true){
					system("cls");
					break;
					}
					cout<<"	"<<left<<setw(28)<<"Product"
							<<setw(10)<<" ID"
							<<setw(20)<<"Price per unit"
							<<setw(20)<<"Amount left"<<endl;
					cout<<"	"<<left<<setw(28)<<product.productArray[arrayLocation].productName
							<<setw(10)<<product.productArray[arrayLocation].productID
							<<setw(20)<<product.productArray[arrayLocation].unitPrice
							<<setw(20)<<product.productArray[arrayLocation].productQuantity<<endl;
					do{
						cout<<"	Input the amount of the product you want to buy: ";
						validation=true;
						integerValidation(productBoughtCount);
						cin.ignore();
						if(productBoughtCount> product.productArray[arrayLocation].productQuantity){
							cout<<"	We're out of stock of that item, please try again. \n";
							validation=false;
						}
						if(productBoughtCount<=0){
							cout<<"	Product bought must be greater than 0. \n";
							validation=false;
						}
					}while(validation==false);
					do {
						validStringType=false;
						cout<<"	Do you wish to try again?(if there was an error in your choice)[Y/N]: ";
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
						cout<<"	Buy More?[Y/N](No to proceed to menu): ";
						getline(cin, orderChoice);
						transform(orderChoice.begin(), orderChoice.end(), orderChoice.begin(), ::toupper);
						if (orderChoice == "Y"){
							retry = true;
							validStringType = true;
							orderID[orderCounter][productCounter][0]=arrayLocation;
							orderID[orderCounter][productCounter][1]=productBoughtCount;
							product.setProductQuantity(arrayLocation,productBoughtCount);
							productCounter+=1;
						}
						else if (orderChoice== "N"){
							retry = false;
							validStringType = true;
							orderID[orderCounter][productCounter][0]=arrayLocation;
							orderID[orderCounter][productCounter][1]=productBoughtCount;
							product.setProductQuantity(arrayLocation,productBoughtCount);
							productCounter+=1;
						}
					} while (!validStringType);
				system("cls");
				}while(retry==true);
			break;
			case 2:
				cout<<"\nOrder ID: "<<orderCounter+1<<"\n";
				for(int i=0; i<productCounter; i++){
				cart.totalCost(orderID[orderCounter][i][0],orderID[orderCounter][i][1]);
				cart.displayShoppingCart(orderID[orderCounter][i][0], orderID[orderCounter][i][1]);
				}
				cout<<"\n-------------------------------------------------\n\nGrand Total for everything in the shopping cart: "<<cart.getGrandTotal();
				do{
					validStringType=false;
					cout<<"\n\n	Would you like to checkout?[Y/N]: ";
					getline(cin, checkoutChoice);
					transform(checkoutChoice.begin(), checkoutChoice.end(), checkoutChoice.begin(), ::toupper);
					if(checkoutChoice=="Y"){
						cout<<"\n	Success!";
						validStringType=true;
						pricePerShoppingCart[orderCounter][0]=productCounter;
						pricePerShoppingCart[orderCounter][1]=cart.getGrandTotal();
						productCounter=0;
						cart.setGrandTotal(0);
						orderCounter+=1;
						cout<<"\n\n	Press Enter to Continue";	
						getch();
					}
					if(checkoutChoice=="N"){
						validStringType=true;
					}
				}while(!validStringType);
					system("cls");
			break;
			case 3:
				for(int j=0; j<orderCounter; j++){
					cout<<"\n-------------------------------------------------\nOrder ID: "<<j+1;
					cout<<"\nGrand Total: "<<pricePerShoppingCart[j][1];
					for(int k=0; k<pricePerShoppingCart[j][0]; k++){
						order.displayOrder(orderID[j][k][0], orderID[j][k][1]);
					}
				}
				cout<<"\n\n	Press Enter to Continue";	
				getch();
				system("cls");
			break;
			case 4:
				menuLoop=false;
			break;
			default:
				menuLoop=true;
		}
		
	}while(menuLoop==true);
	return 0;
}