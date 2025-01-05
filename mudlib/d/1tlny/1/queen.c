inherit MONSTER;
void create() {
			::create();
			set_name("Salamander Queen");
			set("id",({"salamander queen","salamander","queen"}));
			set_level(18+random(3));
			set("short","Salamander Queen");
			set("long","Before you stands the high Queen of the Salamanders.  She has long fiery hair and %^BOLD%^GREEN%^green%^RESET%^ eyes.  Her snake like body moves around you as she gets ready to strike");
			set("race","salamander");
			set_gender("female");
			set_body_type("salamander");
			set_overall_ac(25);
			set_combat_chance(50);
			set_spell_level("greater elemental bolt",6);
			add_spell("greater elemental bolt","$A");
			set_spell_level("instill poison",6);
			add_spell("instill poison","$A");
			set_spell_level("killing cloud",6);
			add_spell("killing cloud","$A");
			set_spell_level("internal flame",6);
			add_spell("internal flame","$A");
			set_spell_level("heal",6);
			add_spell("heal","$(ME)");
			set_skill("attack",110);
			set_skill("parry",120);
			set_skill("dodge",125);
			set_skill("concentrate",80);
			set_skill("conjuration",99);
			set_skill("elementalism",95);
			set_skill("body alteration",87);
			set_skill("prayer",92);
			set_skill("fire lore",101);
			set_max_hp(3000);
			set_hp(3000);
			set_max_mp(5000);
			set_mp(5000);
			set_exp(50000);
			set_money("mithril",random(5)+20);
			force_me("use fire lore");
			reset();

		}	

// From another code:

//if(!present("spear")) {
//new("/wizards/cityhunter/weapon/sspear.c")->move(this_object());
//force_me("wield spear in left hand and right hand"); }		
