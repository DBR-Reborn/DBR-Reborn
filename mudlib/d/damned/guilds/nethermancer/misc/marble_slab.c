#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("marble slab");
    set_id(({ "slab", "marble slab", "slab of marble", "marble" }));
    set_short("A slab of marble");
    set_long("This is a relatively large and well finished slab of pure marble, sized approximately five feet long and four inches thick. It is extremely heavy and appears useless for weapon and armour crafting, however the mineral is the only one in existence capable of withstanding the energies of the netherworld. If crafted into a container of some sort, this slab could prove very useful to a practictioner of undead magic seeking the creation of a nexus.");
    set_weight(1000);
    set_value(35000);
    return;
}
