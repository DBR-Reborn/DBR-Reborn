// /wizards/excelsior/weapons/joker_knife
// Excelsior 7-1-96

inherit "/std/weapon";

void create() {
	::create();
	set_name("knife");
set("id",({"knife","odd looking blade","odd blade","skinner"}));
set("short","an odd looking blade");
	set("long","Though originally designed for juggling, its light weight and "+
		"perfect balance only make it all the more deadly!");
	set_weight(70);
	set_value(1000);
	set_ac(5);
	set_wc(40,"cutting");
	set_wc(14,"impaling");
	set_type("knife");
	set_throwable(1);
	set_quality(6);
set_property("no add quality",1);
set_property("no decay",1);
	set("skill level",300);
set_wield((:call_other,this_object(),"wield_knife":));
	set_hit_bonus(35);
set_verb("carve");
	set_parry_bonus(40);
set_enh_critical(5);
set_material("/metal/neorolite");
}
	
int wield_knife(){
if((string)this_player()->query_name()!="sabrina"){
write("You can't seem to figure out how to use this"+
" odd looking blade.\n");
return 0;
}
else{
return 1;
}
}
