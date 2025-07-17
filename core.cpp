#include "core.h"

Core::Core() {}
void InventoryManager::AddItem(QString& name, QString& quantity,   QString& price,   QString& supplier, QString& category  ){

    if(name.isEmpty()||quantity.isEmpty()||price.isEmpty()|| supplier.isEmpty(), category.isEmpty() ){
        throw runtime_error {"Error: You cannot add an empty item  "};

    }
    if (quantity.toInt()<0|| price.toInt()<0) {
        throw runtime_error {"Only postive numbers"};
    }
    QString key ;
 key = name+supplier;
    if (items.count(key)){
        throw runtime_error {"Item already exsit"} ;

    }
    else {
    items[key]=Item( name, category, quantity.toInt(), price.toInt(), supplier);

    }
}