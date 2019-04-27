// File: order.cpp

#include "order.h"
#include <iostream>
#include <string>
using namespace std;

Product Order :: getProduct()
{
   return this->product;
}
void Order :: setProduct(Product product)
{
   this->product = product;
}

int Order :: getQuantity()
{
   return this->quantity;
}
void Order :: setQuantity(int quantity)
{
   this->quantity = quantity;
}

Customer Order :: getCustomer()
{
   return this->customer;
}

void Order :: setCustomer(Customer customer)
{
   this->customer = customer;
}

string Order :: getShippingZip()
{
   address = customer.getAddress();
   return address.getZip();
} 

float Order :: getTotalPrice()
{
   return this->product.getTotalPrice() * this->quantity;
}
void Order :: displayShippingLabel()
{
    this->customer.display();
}
void Order :: displayInformation()
{
   cout << this->customer.getName() << endl;
   cout << this->product.getName() << endl;
   cout << "Total Price: $" << getTotalPrice() << endl;
}
// Put your the method bodies for your order class here
