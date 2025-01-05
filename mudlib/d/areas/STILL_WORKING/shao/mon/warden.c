// Wizard : Hood
// File : warden.c
// Shao-tan Jail Warden

#include <std.h>

inherit MONSTER;


void reset() {
	::reset();
if(!present("plate")) {
new("/wizards/hood/area/armor/w_plate")->move(this_object());
command("wear plate");
}
if(!present("greaves")){
new("/wizards/hood/area/armor/w_greaves")->move(this_object());
command("wear greaves");
}
if(!present("helmet")){
new("/wizards/hood/area/armor/w_helm")->move(this_object());
command("wear helmet");
}
if(!present("glove")){
new("/wizards/hood/area/armor/w_glove")->move(this_object());
command("wear glove on right hand");
}
if(!present("glove 2")) {
new("/wizards/hood/area/armor/w_glove")->move(this_object());
command("wear glove on left hand");
}
if(!present("boots")){
alias armor new("/wizards/hood/area/armor/$*")->move(this_object());
armor w_boots
if(!present("sword"))
if(!present("cloak"))
if(!present("bracer"))
if(!present("bracer 2"))
if(!present("belt"))
if(!present("ring"))
		new("/std/obj/torch")->move(this_object());
	if(!present("knife")) {
		new("/d/nfd/weapons/juggler_knife")->move(this_object());
		command("wield knife in right hand");
	}
	if(!present("knife 2")) {
		new("/d/nfd/weapons/juggler_knife")->move(this_object());
		command("wield knife in left hand");
	}
}

void create() {
	::create();
set_name("Karajm");
set("id",({"warden","jail warden","karajm","Karajm"}) );
set_level(19);
set("short","warden");
set("long","This rather large and mean looking fellow "+
"appears to be the Shao-tan Jail Warden.  Judging by the "+
"numerous scars that cover his face and hands, and also "+
"from the faded tattoo of a cross under his left eye you "+
"suspect him to be a retired paladin.  Retired or not "+
"his large frame and meen glare suggest he still may be able "
"to kick some serious ass.\n");
	set("race","high-man");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(19);
	set_combat_chance(30);
	set_skill("knife",83);
	set_skill("attack",85);
	set_skill("illusionism",79);
	set_skill("parry",70);
	set_skill("dodge",70);
	set_languages(({"middle-english","common","yin","serra","orcish"}));
	set_emotes(30,({"The juggler tosses one under his leg.","The juggler "+
		"tosses an object behind his back.","The juggler juggles %^YELLOW%^%^BOLD%^"+
		"torches%^RESET%^.","The juggler juggles knives.","Shoot! He dropped one.",
		"The juggler switches to juggling clubs.","Joker juggles 4 objects at once!",
		"Joker juggles %^BOLD%^%^RED%^5%^RESET%^ objects at once!"}),0);
	reset();
}
