inherit "/std/armour";
object shadow;

   create() {
	::create();
	set_name("aquamarine ring");
	set("id", ({"ring", "aquamarine ring"}));
	set_short("aquamarine ring");
	set_long("This is a ring made of aquamarine and opal hybrid stone.  It is carved into two dolphins with extraordinaryly large %^CYAN%^gills%^RESET%^ on the side.");
	set_type("ring");
	set_ac(2);
	set_limbs( ({"right hand", "left hand"}));

	set_value(2000);
	set_material("aquamarine-opal");
	set_weight(20);
	set_property("magic item", ({"gills"}));
}
void init(){
	::init();
	add_action("gills", "gills");
}
int gills(){
int check_mp;
check_mp = this_player()->query_mp();
if(check_mp < 70){
	write("Your lack of concentration doesn't allow you to grow any gills.");
return 1;
}
if(check_mp >= 70){
int swim_mod;
swim_mod = 100;
	shadow=clone_object("/std/spells/shadows/skill_shadow.c");
	shadow->add_new_skill_bonus("swimming", swim_mod);
	shadow->start_shadow(this_player(), 120, "The gills on the side of your neck shrink and shrivel away.");
this_player()->add_mp(-70);
write("As you concentrate on the ring, two gills start to grow on the sides of your neck.  You find that you are able to breathe water now.");
return 1;
}
}
