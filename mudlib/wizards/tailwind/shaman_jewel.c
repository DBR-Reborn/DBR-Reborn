inherit "/std/Object";

// Everything is now set with the functions at the end of the object.

string color,gemtype;
int timecharging;
int recursion = 0;

void restore_stuff(){TO->set_up();}
void gem_set(string gemmaterial){
    switch(gemmaterial){
    case "/diamond":
	color="pure white";
	gemtype="life";
	break;
    case "/ruby":
	color="dark red";
	gemtype="fire";
	break;
    case "/emerald":
	color="clear green";
	gemtype="earth";
	break;
    case "/sapphire":
	color="bright blue";
	gemtype="sky";
	break;
    case "/jade":
	color="dark green";
	gemtype="magic";
	break;
    case "/obsidian":
	color="clear";
	gemtype="none";
	break;
    case "/amethyst":
	color="clear purple";
	gemtype="time";
	break;
    case "/turquoise":
	color="brilliant blue-green";
	gemtype="water";
	break;
    case "/onyx":
	color="translucent black";
	gemtype="death";
	break;
    case "/quartz":
	color="clear";
	gemtype="none";
	break;
    }
    return;
}

void set_up(){
    recursion = 1;
    gem_set(this_object()->query_material());
    switch(query_property("charge")) {
    case -10000..10:
	set_short("A faintly lit "+ color +" "+this_object()->query_flavor());
	break;
    case 11..20:
	set_short("A dim "+ color +" "+this_object()->query_flavor());
	break;
    case 21..30:
	set_short("A glowing "+ color +" "+this_object()->query_flavor());
	break;
    case 31..40:
	set_short("A brightly-glowing "+ color +" "+this_object()->query_flavor());
	break;
    case 41..60:
	set_short("A shining "+ color +" "+this_object()->query_flavor());
	break;
    case 61..70:
	set_short("A brightly-shining "+ color +" "+this_object()->query_flavor());
	break;
    case 71..80:
	set_short("A blindingly-bright "+ color +" "+this_object()->query_flavor());
	break;
    case 81..90:
	set_short("A "+ color +" "+this_object()->query_flavor()+
	  " shining like a small sun");
	break;
    case 91..100000000000:
	set_short("A "+ color +" "+this_object()->query_flavor()+
	  " that glows like a supernova");
	break;
    }
    set_id( ({ (string)this_object()->query_flavor(), "shaman "
	+(string)this_object()->query_flavor(), "jewel" }) );
    set_long("This "+(string)this_object()->query_flavor()+
      " contains the power of "+(string)this_object()->query_type()+
      " within it. It is made of "+this_object()->query_material()+".");
    this_object()->set_type(gemtype);
    this_object()->set_color(color);

    if((gemtype == "time") && (timecharging==0)){
	call_out("time_charge", 20);
	timecharging=1;
    }
    recursion = 0;
    return;
}

void create() {
    ::create();
    set_name("shaman-jewel");
    set_weight(5);
    set_value(1);
    if(!recursion)
	call_out("set_up", 1);
    return;
}

int time_charge() {
    this_object()->add_charge(10);
    call_out("time_charge", 3600);
    return 1;
}

int is_battery() {return 1;}

int add_charge(int charge) {
    if(this_object()->query_charge()>0){
	write("This jewel has already been charged.");
	return 0;
    }
    if(charge>this_object()->query_max_charge()){
	this_object()->set_property("charge", this_object()->query_max_charge());
	write("The jewel begins to shine more brightly.");
	if(!recursion)
	    call_out("set_up", 1);
	return 1;
    }
    this_object()->set_property("charge", charge);
    write("The jewel begins to shine more brightly.");
    if(!recursion)
	call_out("set_up", 1);
    return 1;
}

int subtract_charge(int charge) {
    if(this_object()->query_property("charge")-charge<=0){
	write("The jewel goes completely dark, and shatters "+
	  "to dust. The remains scatter to the wind.");
	this_object()->remove();
	return 1;
    }
    this_object()->set_property("charge",
      this_object()->query_property("charge")-charge);
    write("Your jewel seems to darken a bit.");
    if(!recursion)
	call_out("set_up", 1);
    return 1;
}

int query_charge() {
    return this_object()->query_property("charge");
}

int set_max_charge(int maxcharge) {
    this_object()->set_property("max-charge", maxcharge);
    return 1;
}

int query_max_charge() {
    return this_object()->query_property("max-charge");
}

int set_type(string jeweltype) {
    this_object()->set_property("type", jeweltype);
    if(!recursion)
	call_out("set_up", 1);
    return 1;
}

string query_type() {return this_object()->query_property("type");}

int set_color(string jewelcolor) {
    this_object()->set_property("color", jewelcolor);
    if(!recursion)
	call_out("set_up", 1);
    return 1;
}

string query_color() {return this_object()->query_property("color");}
// Jewel, Orb, or Natural Sphere
int set_flavor(string flavor) {
    this_object()->set_property("flavor", flavor);
    if(!recursion)
	call_out("set_up", 1);
    return 1;
}

string query_flavor() {return this_object()->query_property("flavor");}


