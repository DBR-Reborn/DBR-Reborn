inherit "/std/tailwind/potion/potion_plant";
 
void create() {
  ::create();
  set_name("balsam weeds");
  set("id", ({"weeds", "balsam weeds"}) );
  set("short", "a bunch of balsam weeds");
  set("long", "The balsam weed is a less destructive weed than its "
              "cousin, the yithki weed.  This plant has a short, wide "
              "stem, a large white flower on top, and, like the yithki "
              "weed, has large, shiny leaves.");
  set_weight(3+random(5));
  set_toxin_level(25+random(3));
  set_strength(3);
}
