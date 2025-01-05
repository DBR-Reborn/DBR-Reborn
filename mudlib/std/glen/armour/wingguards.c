inherit "/std/armour";

#define minute (60)
#define day (minute*60*24)

int create_time = 0;
int expiration = 4*day;

void expire(){
    if(create_time == 0)
	create_time = time();
    else
    if(time() - create_time > expiration){
	write("this item has expired: " + query_short());
	remove();
    }
}

void create() {
    ::create();
    set_name("wing guards");
    set("id", ({"wing guards", "wing sheaths", "wingguards"
	, "sheaths"}) );
    set("short", "wing guards");
    set("long",
      "A pair of wing sheaths"
    );
    set_type("wingguards");
    set_ac(12);
    set_limbs( ({ "left wing", "right wing"}) );
    set_value(150);
    set_weight(120);
    set_material("leather");
    call_out("expire", 5);
}



