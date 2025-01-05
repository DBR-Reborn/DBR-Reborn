//    A Totem.
// edited by Thrace Merin to fix save compatibility July 30, 2000
// Shamelessly ripped for Shaman by TW 02/04/01
#include <move.h>
#include <daemons.h>
#include <daemons.h>

inherit "/std/Object";
inherit "/std/locker_logic";

void init() {
    ::init();
    add_action("do_deposit","deposit");
    add_action("do_withdraw","withdraw");
    add_action("do_check","check");
}

void create() {
  ::create();
  set_id( ({ "totem", "totem pole" }) );
  set_name("totem");
  set_short("A Shaman's Totem");
  set_long(
  "This totem pole is made of wood. It has an intricately carved design depicting various natural scenes. You can 'deposit' magic power and 'withdraw' magic power from it. You can also 'check' it to see how much magic power is left in it.");
  set_weight(99999999999);
  set_value(0);
  return;
}

int do_deposit(string amounttoadd) {
int amount;
string str;
if(sscanf(amounttoadd, "%d", amount) == 1) {

    if(amount > this_player()->query_mp()) {
        message("info", "You don't have that much magic power.", this_player());
        return 1;
    }

    if(amount > this_object()->query_capacity()-this_object()->query_balance()) {
        message("info", "The totem cannot hold that much power.", this_player());
        return 1;
    }
        message("info", "You deposit some magic power to the totem. You feel drained.", this_player());
        this_object()->add_balance(amount);
        this_player()->set_mp(this_player()->query_mp()-amount);
return 1;
}

message("info", "Please specify the amount of magic power you would like to deposit. The totem currently has "+this_object()->query_balance()+" magic points in it, out of a total of "+this_object()->query_capacity()+".", this_player());

return 1;
}

int do_withdraw(string amounttosubtract) {
int amount;
string str;
if(sscanf(amounttosubtract, "%d", amount) == 1) {

    if(amount > this_player()->query_max_mp()-this_player()->query_mp()) {
        message("info", "You cannot withdraw more magic power than you can normally hold.", this_player());
        return 1;
    }

    if(amount > this_object()->query_balance()) {
        message("info", "The totem does not have that much power in it.", this_player());
        return 1;
    }
        message("info", "You withdraw some magic power from the totem. You feel empowered.", this_player());
        this_object()->subtract_balance(amount);
        this_player()->set_mp(this_player()->query_mp()+amount);
return 1;
}

message("info", "Please specify the amount of magic power you would like to withdraw. The totem currently has "+this_object()->query_balance()+" magic points in it, out of a total of "+this_object()->query_capacity()+".", this_player());
return 1;
}

// Shows the player how much mp is in the totem
int do_check() {
message("info", "The totem currently has "+this_object()->query_balance()+" magic points in it, out of a total of "+this_object()->query_capacity()+".", this_player());
return 1;
}

// adds mp 'to' the totem
int add_balance(int amount) {
this_object()->set_property("balance", this_object()->query_property("balance")+amount);
    SAVE_ITEMS_D->update_lockers(environment(this_object()));
return 1;
}

// subtracts mp 'from' the totem
int subtract_balance(int amount) {
this_object()->set_property("balance", this_object()->query_property("balance")-amount);
    SAVE_ITEMS_D->update_lockers(environment(this_object()));
return 1;
}

// queries current mp 'in the totem'
int query_balance() {
return this_object()->query_property("balance");
}

// set by erect totem skill
int set_capacity(int amount){
this_object()->set_property("capacity", amount);
return 1;
}

// queries maximum capacity
int query_capacity() {
return this_object()->query_property("capacity");
}





// Save system specific stuff
string query_storage_key() { return "totem"; }

int query_is_locker() { return 1; }
get() {return 0;}
string query_my_file() { return "totem"; }

int move(mixed dest) {
  
  if(query_property("no get") && objectp(dest) && living(dest))
    return MOVE_NOT_ALLOWED;
  return ::move(dest);
}


int restore_locker(string null) {
  set_property("no get", 1);
  return 1;
}

