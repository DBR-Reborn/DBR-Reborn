//    A Shaman's Pet Template. -TW 1/11/01

inherit "/std/pet";

// When called from a spell, set_up(int) needs to be called on this object.
// Also, set_id, set_short, set_long set_body_type, and set(race, "")
// should be called on to it. Definitely consider melee damage, too.
// Make sure to add_charge() and set_type().

void create() {
  ::create();
  set_save(0);
set_property("no save", 1);
  set_attack(1);
  set_carry(0);
  set_can_change_aggr(0);
  return;
}

void set_up(int pow) {
  set_level(pow);
  return;
}

void stabilize() {
  remove_call_out("expire");
  set_save(1);
  set_can_change_aggr(1);
  return;
}

void set_dur(int dur) {
  call_out("expire", dur);
  return;
}

void expire() {
  message("info", "%^GREEN%^%^BOLD%^The creature vanishes in a flash of light.",
    environment());
  remove();
  return;
}

int is_elemental() { return 1; }

int add_charge(int charge) {
this_object()->set_property("charge", charge);
return 1;
}

int query_charge() {
return this_object()->query_property("charge");
}

int set_type(string type) {
this_object()->set_property("type", type);
return 1;
}

string query_type() {
return this_object()->query_property("type");
}