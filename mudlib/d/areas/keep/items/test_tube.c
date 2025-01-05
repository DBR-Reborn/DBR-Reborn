#include <std.h>

/* This is a test tube for decoration in the laboratory room of the black keep. It serves no special purpose whatsoever. */

inherit OBJECT;

void create() {
::create();
set_name("test tube");
set("id", ({ "tube", "test tube", "testtube" }));
set_short("An empty test tube");
set_long("This is a small glass test tube. It appears extremely delicate, even the slightest force would likely shatter it.");
set_weight(1);
set_value(10);
}
