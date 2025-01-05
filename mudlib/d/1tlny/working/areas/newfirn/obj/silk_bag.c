// Wizard: Gellor
// silk bag
// silk_bag.c
inherit "std/bag_logic.c";
void create() {
set_name("bag");
set("id",({"bag","a silk bag","silk bag"}));
set("short","A soft silk bag");
set("long","This bag is rather large and light. It is made of "
			  "hand-woven spider silk which is nearly unmatchable "
           "for strength and dependability.");
set_weight( 30 );
set_value( 25 );
set_max_internal_encumbrance( 1400 );
}
