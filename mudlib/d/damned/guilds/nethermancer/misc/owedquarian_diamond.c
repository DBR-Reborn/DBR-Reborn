#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("owedquarian diamond");
    set_id(({ "diamond", "diamond of owedquar", "owedquarian diamond", "eternal darkness diamond" }));
    set_short("%^CYAN%^Owedquarian Diamond%^RESET%^");
    set_long("This object is a diamond the likes of which few beings have ever seen. It is completely pure and sized approximately as large as a man's head in the shape of a perfect three dimensional diamond, complete with razor sharp edge points. As your hands grasp it they begin to notably burn without rest, giving the impression that an amazing power rests within the unbreakable mineral.");
    set_property("eternal darkness diamond", 1);
    set_weight(200);
    set_value(1000000);
    return;
}
