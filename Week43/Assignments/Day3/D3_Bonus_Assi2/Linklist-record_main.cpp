
/*• Update your linked-list so you can use it as storage in previous assignment.Record*/
#include "Linklist.h"
#include "record.h"

int main () {
    Record *record = new Record("Rickard Ljung", "20201021", service_enum::TireChange);
    record->changePart("Tire", 40);
    record->changePart("SW upgrade", 626.66);

    record->pay(payment_method_enum::Swish, 13.37);

    LinkedList list;
    list.add(record, 0);

    Record *record2 = static_cast<Record*>(list.getObject(0));
    //record2->printRecordData();
} 