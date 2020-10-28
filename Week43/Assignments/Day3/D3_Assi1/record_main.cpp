/*A car service shop needs to keep track of the records of services they provide to their customer. Create a system
for them so they could keep ATLEAST the below records:
• Date the customer visited
• Services performed (at least 2 different services)
• Parts changed (at least 2 different parts)
• Payment (method & amount)*/

#include "record.h"

int main() {
    Record record("Rickard Ljung", "20201021", service_enum::TireChange);

    record.printRecordData();
    record.changePart("Tire", 40);
    record.changePart("SW upgrade", 626.66);
    record.printRecordData();

    record.pay(payment_method_enum::Swish, 13.37);
    record.printRecordData();
}