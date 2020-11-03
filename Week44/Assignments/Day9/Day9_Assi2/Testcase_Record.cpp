#include <string>
#include <iostream>

const std::string service_types[3] = {"TireChange", "WindScreenChange", "YearlyService"};
enum service_enum {TireChange, WindScreenChange, YearlyService};
typedef struct struct_part{
    std::string name = "";
    float price;
} part_struct;
const std::string payment_types[3] = {"Cash", "Card", "Swish"};
enum payment_method_enum {Cash, Card, Swish};
typedef struct struct_payment{
    payment_method_enum payment_type;
    float amount = -1;
} payment_struct;

class Record {
    private:
        std::string customer_name, date;
        service_enum service;
        part_struct parts[10]; //?? object with parts?
        payment_struct payment;
        unsigned int nbr_changed_parts = 0;
    public:
        Record() = delete;
        Record(std::string _name, std::string _date, service_enum _service);
        void changePart(std::string part_name, float part_price);
        void pay(payment_method_enum payment, float amount);
        void printRecordData();
        float totPartPrice();
}; 

Record::Record(std::string _name, std::string _date, service_enum _service):customer_name(_name), date(_date), service(_service) {}

void Record::changePart(std::string part_name, float part_price) {
    this->parts[this->nbr_changed_parts].name = part_name;
    this->parts[this->nbr_changed_parts].price = part_price;
    this->nbr_changed_parts += 1;
}
void Record::pay(payment_method_enum payment, float amount) {
    this->payment.payment_type = payment;
    this->payment.amount = amount;
}
void Record::printRecordData() {
    std::cout << "Customer name: " << this->customer_name << "\nDate of visit: " << this->date << "\nService type: " << service_types[this->service] << std::endl;
    std::cout << "Changed parts: \n";
    if (this->nbr_changed_parts > 0) {
        for(int i = 0; i < this->nbr_changed_parts; i++) {
            std::cout << "    * " << this->parts[i].name << std::endl;
        }
    } else {
        std::cout << "    No parts are change yet!" << std::endl;
    }
    float total_price = this->totPartPrice();
    if (total_price > 0) {
        std::cout << "Total price of parts: " << total_price << std::endl;
    }
    if (this->payment.amount != -1) {
        std::cout << "Payment: \n" << this->payment.amount << " SEK with " << payment_types[this->payment.payment_type] << std::endl;
    } else {
        std::cout << "The customer have not payed yet!!" << std::endl;
    }
    std::cout << std::endl;
}
float Record::totPartPrice() {
    float total_price = 0;
    for(int i = 0; i < this->nbr_changed_parts; i++) {
        total_price += this->parts[i].price;
    }
    return total_price;
}


/*A car service shop needs to keep track of the records of services they provide to their customer. Create a system
for them so they could keep ATLEAST the below records:
• Date the customer visited
• Services performed (at least 2 different services)
• Parts changed (at least 2 different parts)
• Payment (method & amount)*/


int main() {
    Record record("Jinsi Jasi", "20201021", service_enum::TireChange);

    record.printRecordData();
    record.changePart("Tire", 40);
    record.changePart("SW upgrade", 626.66);
    record.printRecordData();

    record.pay(payment_method_enum::Swish, 13.37);
    record.printRecordData();


}