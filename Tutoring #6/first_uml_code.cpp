#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string code;
    double price;
    string description;
    string type;

public:
    Product(string c, double p, string d, string t) 
        : code(c), price(p), description(d), type(t) {}

    double getPrice() const {
        return price;
    }

    // getters y setters...
};

class SaleItem {
private:
    Product product;
    int quantity;

public:
    SaleItem(Product p, int q) : product(p), quantity(q) {}

    double getSubTotal() const {
        return product.getPrice() * quantity;
    }

    // Other methods
};

class Sale {
private:
    vector<SaleItem> items;
    string date;

public:
    Sale(string d) : date(d) {}

    void addItem(SaleItem item) {
        items.push_back(item);
    }

    double getTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.getSubTotal();
        }
        return total;
    }

    // Other Methods
};

class DiscountPolicy {
public:
    virtual double getDiscount(const Sale& sale) const = 0;
};

class CardDiscount : public DiscountPolicy {
public:
    double getDiscount(const Sale& sale) const override {
        return sale.getTotal() * 0.10;
    }
};

class QuantityDiscount : public DiscountPolicy {
public:
    double getDiscount(const Sale& sale) const override {
        double discount = 0;
        for (const auto& item : sale.items) {
            if (item.getQuantity() > 10) {
                discount += item.getSubTotal() * 0.05;
            }
        }
        return discount;
    }
};

class MondayDiscount : public DiscountPolicy {
public:
    double getDiscount(const Sale& sale) const override {
        // Assuming that it is verified if the date corresponds to a Monday
        return sale.getTotal() * 0.15;
    }
};

int main() {
    Product p1("P001", 100.0, "Producto 1", "Tipo A");
    Product p2("P002", 50.0, "Producto 2", "Tipo B");

    SaleItem item1(p1, 5);
    SaleItem item2(p2, 12);

    Sale sale("2024-08-27");
    sale.addItem(item1);
    sale.addItem(item2);

    CardDiscount cardDiscount;
    QuantityDiscount quantityDiscount;
    MondayDiscount mondayDiscount;

    double totalDiscount = cardDiscount.getDiscount(sale) 
                         + quantityDiscount.getDiscount(sale) 
                         + mondayDiscount.getDiscount(sale);

    double finalTotal = sale.getTotal() - totalDiscount;

    cout << "Total sin descuentos: " << sale.getTotal() << endl;
    cout << "Descuento total: " << totalDiscount << endl;
    cout << "Total final: " << finalTotal << endl;

    return 0;
}
