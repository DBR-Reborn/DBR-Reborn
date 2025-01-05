#include <std.h>
inherit MONSTER;
create() {
  ::create();
    set_name("woodsman");
    set_id( ({ "woodsman","man" }) );
    set_level(15);
    set_short("a woodsman");
    set_long("This woodsman looks normal for the most part. He is about 6 "
    			 "feet tall. His build is hard to determine, however he is "
             "most definitely not very skinny. His face is lean, tan, and "
             "aged, decorated by a well trimmed goatee and mustache, both "
             "of which are black. His hair is well kept and is black as "
             "well. On the tops of his hands you see the tattoo of a "
             "vulture's head.");
    set("race", "high-man");
    set_gender("male");
    set_body_type("human");
    set_alignment(0);
    new("/wizards/gellor/newfirn/obj/cato_knife1.c")->
      move(this_object());
    force_me("wield knife in left hand");
    new("/wizards/gellor/newfirn/obj/cloak.c")->
      move(this_object());
    force_me("wear cloak");
}
