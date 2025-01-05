#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("statue");
    set("id", ({ "statue", "kyoki statue", "black statue", "black and grey statue", "grey statue", "statue of kyoki", "black statue of kyoki", "grey statue of kyoki", "black and grey statue of kyoki" }));
    set_short("%^BOLD%^%^WHITE%^A black and grey statue of Kyoki%^RESET%^");
    set_long("This is a life size statue, approximately six feet in height. It is completely painted of adeptly laid black and grey color and depicts the legendary Invisible-Dagger Kyoki, the definitive assassin.");
    set_weight(10000000);
    set_value(0);
}
