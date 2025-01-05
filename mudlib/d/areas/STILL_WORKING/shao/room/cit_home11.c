#include <std.h>
#include <shao.h>

inherit VAULT;
object mon;

void init(){
::init();
add_action("look_sky","look");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "Citizen Home");
set("long", "This house is no more then a small room, "
"with some straw laying on the floor in the corner "
"for a bed.\n"
"The floor is constructed of old wooden planks, "
"that are splitting and crumbling in most places."
" The mud walls are cracked and dry with a "
"large number of spots where the mud has totaly"
" flaked off, exposing the wood frame underneath. "
"The ceiling is cracked and crumbling as well, in "
"a few spots the sky can be seen right through "
"the large gaps in the rafters.\n");
set_items( ([
({"straw", "bed"}):"It looks as if some vagrant has"+
" gathered straw and hay to fashion a comfortable"+
" place to sleep.\n",
({"planks","plank","wooden plank","wooden planks","floor"}):
"Old wooden planks have been placed over the muddy "+
"earth, and you suppose it does classify as a "+
"floor.  Although the wood is so stained and "
"rotting it is starting to blend into the dirt it "
"was made to cover.\n",
({"mud","mud walls","walls"}):
"A dark pigmented mud was packed up against a wood "+
"frame to perhaps provide some protection from the "+
"elements, and intruders.\n",
({"rafters","ceiling"}):
"The ceiling is in poor shape, the rafters "+
"seem old and weak, and have large gaps exposing "+
"the sky overhead.\n"
]));
    add_exit("com8","north");
set_door("wood door",PATH+"com8","north", 0);
set_search("default",(: call_other, this_object(),"search_default":));

}
search_default(){
write("You search the room in a random"+
" and unorganized fashion, poking through "+
"the makeshift bed, and lifting old planks..."+
"and you find...\n"+
"\n"+
"A RAT!\n");
mon = new(MON_PATH+"rat")->move(this_object());
}
int look_sky(string str){
if(!str){
notify_fail("look at what?");
return 0;
}
if(str == "sky" || str == "at sky" ||
str == "at gaps" || str == "gaps"){
if(!query_night()){
write("Warm rays of sunlight filter down through"+
" the holes in the ceiling, highlighting the "
"pretty blood, urin, and crap stains on "
"the wonderfully decayed wood floor boards.\n");
return 1;
}
write("The dark night looks cold and forbiding.\n"+
"Actually it looks down right scary and your dam "
"glad yer inside with at least half a roof over "
"your head.\n");
return 1;
}
}
