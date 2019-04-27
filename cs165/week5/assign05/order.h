// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"
#include <iostream>
#include <string>
using namespace std;


class Order
{
   private:
   int quantity;
   string zip;
   
   
   public:
   Order() 
   {
      quantity = 0;
      product = Product();
      customer = Customer();
   }
   
   Order(Product product, int quantity, Customer customer)
      {
      setProduct(product);
      setQuantity(quantity);
      setCustomer(customer);
      }
      Customer customer;
      Address address;
      Product product;
      Product getProduct();
      
      void setProduct(Product product); 
      
      int getQuantity();
      void setQuantity(int quantity);
      
      Customer getCustomer();
      void setCustomer(Customer customer);
      
      string getShippingZip();
      float getTotalPrice();
      
      void displayShippingLabel();
      void displayInformation();
};

// Put your Order class here


#endif
